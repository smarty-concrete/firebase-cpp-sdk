/*
 * Copyright 2023 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "firebase/firestore.h"
#include "firestore_integration_test.h"

namespace firebase {
namespace firestore {
namespace {

using FilterTest = FirestoreIntegrationTest;

TEST_F(FilterTest, IdenticalShouldBeEqual) {
  FieldPath foo_path{std::vector<std::string>{"foo"}};

  Filter filter1a = Filter::ArrayContains("foo", FieldValue::Integer(42));
  Filter filter1b = Filter::ArrayContains(foo_path, FieldValue::Integer(42));

  Filter filter2a = Filter::ArrayContainsAny(
      "foo", std::vector<FieldValue>{FieldValue::Integer(42)});
  Filter filter2b = Filter::ArrayContainsAny(
      foo_path, std::vector<FieldValue>{FieldValue::Integer(42)});

  Filter filter3a = Filter::EqualTo("foo", FieldValue::Integer(42));
  Filter filter3b = Filter::EqualTo(foo_path, FieldValue::Integer(42));

  Filter filter4a = Filter::NotEqualTo("foo", FieldValue::Integer(42));
  Filter filter4b = Filter::NotEqualTo(foo_path, FieldValue::Integer(42));

  Filter filter5a = Filter::GreaterThan("foo", FieldValue::Integer(42));
  Filter filter5b = Filter::GreaterThan(foo_path, FieldValue::Integer(42));

  Filter filter6a =
      Filter::GreaterThanOrEqualTo("foo", FieldValue::Integer(42));
  Filter filter6b =
      Filter::GreaterThanOrEqualTo(foo_path, FieldValue::Integer(42));

  Filter filter7a = Filter::LessThan("foo", FieldValue::Integer(42));
  Filter filter7b = Filter::LessThan(foo_path, FieldValue::Integer(42));

  Filter filter8a = Filter::LessThanOrEqualTo("foo", FieldValue::Integer(42));
  Filter filter8b =
      Filter::LessThanOrEqualTo(foo_path, FieldValue::Integer(42));

  Filter filter9a =
      Filter::In("foo", std::vector<FieldValue>{FieldValue::Integer(42)});
  Filter filter9b =
      Filter::In(foo_path, std::vector<FieldValue>{FieldValue::Integer(42)});

  Filter filter10a =
      Filter::NotIn("foo", std::vector<FieldValue>{FieldValue::Integer(42)});
  Filter filter10b =
      Filter::NotIn(foo_path, std::vector<FieldValue>{FieldValue::Integer(42)});

  EXPECT_TRUE(filter1a == filter1a);
  EXPECT_TRUE(filter2a == filter2a);
  EXPECT_TRUE(filter3a == filter3a);
  EXPECT_TRUE(filter4a == filter4a);
  EXPECT_TRUE(filter5a == filter5a);
  EXPECT_TRUE(filter6a == filter6a);
  EXPECT_TRUE(filter7a == filter7a);
  EXPECT_TRUE(filter8a == filter8a);
  EXPECT_TRUE(filter9a == filter9a);
  EXPECT_TRUE(filter10a == filter10a);

  EXPECT_TRUE(filter1a == filter1b);
  EXPECT_TRUE(filter2a == filter2b);
  EXPECT_TRUE(filter3a == filter3b);
  EXPECT_TRUE(filter4a == filter4b);
  EXPECT_TRUE(filter5a == filter5b);
  EXPECT_TRUE(filter6a == filter6b);
  EXPECT_TRUE(filter7a == filter7b);
  EXPECT_TRUE(filter8a == filter8b);
  EXPECT_TRUE(filter9a == filter9b);
  EXPECT_TRUE(filter10a == filter10b);

  EXPECT_FALSE(filter1a != filter1a);
  EXPECT_FALSE(filter2a != filter2a);
  EXPECT_FALSE(filter3a != filter3a);
  EXPECT_FALSE(filter4a != filter4a);
  EXPECT_FALSE(filter5a != filter5a);
  EXPECT_FALSE(filter6a != filter6a);
  EXPECT_FALSE(filter7a != filter7a);
  EXPECT_FALSE(filter8a != filter8a);
  EXPECT_FALSE(filter9a != filter9a);
  EXPECT_FALSE(filter10a != filter10a);

  EXPECT_FALSE(filter1a != filter1b);
  EXPECT_FALSE(filter2a != filter2b);
  EXPECT_FALSE(filter3a != filter3b);
  EXPECT_FALSE(filter4a != filter4b);
  EXPECT_FALSE(filter5a != filter5b);
  EXPECT_FALSE(filter6a != filter6b);
  EXPECT_FALSE(filter7a != filter7b);
  EXPECT_FALSE(filter8a != filter8b);
  EXPECT_FALSE(filter9a != filter9b);
  EXPECT_FALSE(filter10a != filter10b);

  EXPECT_TRUE(filter1a != filter2a);
  EXPECT_TRUE(filter1a != filter3a);
  EXPECT_TRUE(filter1a != filter4a);
  EXPECT_TRUE(filter1a != filter5a);
  EXPECT_TRUE(filter1a != filter6a);
  EXPECT_TRUE(filter1a != filter7a);
  EXPECT_TRUE(filter1a != filter8a);
  EXPECT_TRUE(filter1a != filter9a);
  EXPECT_TRUE(filter1a != filter10a);
  EXPECT_TRUE(filter2a != filter3a);
  EXPECT_TRUE(filter2a != filter4a);
  EXPECT_TRUE(filter2a != filter5a);
  EXPECT_TRUE(filter2a != filter6a);
  EXPECT_TRUE(filter2a != filter7a);
  EXPECT_TRUE(filter2a != filter8a);
  EXPECT_TRUE(filter2a != filter9a);
  EXPECT_TRUE(filter2a != filter10a);
  EXPECT_TRUE(filter3a != filter4a);
  EXPECT_TRUE(filter3a != filter5a);
  EXPECT_TRUE(filter3a != filter6a);
  EXPECT_TRUE(filter3a != filter7a);
  EXPECT_TRUE(filter3a != filter8a);
  EXPECT_TRUE(filter3a != filter9a);
  EXPECT_TRUE(filter3a != filter10a);
  EXPECT_TRUE(filter4a != filter5a);
  EXPECT_TRUE(filter4a != filter6a);
  EXPECT_TRUE(filter4a != filter7a);
  EXPECT_TRUE(filter4a != filter8a);
  EXPECT_TRUE(filter4a != filter9a);
  EXPECT_TRUE(filter4a != filter10a);
  EXPECT_TRUE(filter5a != filter6a);
  EXPECT_TRUE(filter5a != filter7a);
  EXPECT_TRUE(filter5a != filter8a);
  EXPECT_TRUE(filter5a != filter9a);
  EXPECT_TRUE(filter5a != filter10a);
  EXPECT_TRUE(filter6a != filter7a);
  EXPECT_TRUE(filter6a != filter8a);
  EXPECT_TRUE(filter6a != filter9a);
  EXPECT_TRUE(filter6a != filter10a);
  EXPECT_TRUE(filter7a != filter8a);
  EXPECT_TRUE(filter7a != filter9a);
  EXPECT_TRUE(filter7a != filter10a);
  EXPECT_TRUE(filter8a != filter9a);
  EXPECT_TRUE(filter8a != filter10a);
  EXPECT_TRUE(filter9a != filter10a);
}

TEST_F(FilterTest, DifferentValuesAreNotEqual) {
  Filter filter1a = Filter::ArrayContains("foo", FieldValue::Integer(24));
  Filter filter1b = Filter::ArrayContains("foo", FieldValue::Integer(42));
  Filter filter1c = Filter::ArrayContains("bar", FieldValue::Integer(42));

  Filter filter2a = Filter::EqualTo("foo", FieldValue::Integer(24));
  Filter filter2b = Filter::EqualTo("foo", FieldValue::Integer(42));
  Filter filter2c = Filter::EqualTo("bar", FieldValue::Integer(42));

  Filter filter3a = Filter::NotEqualTo("foo", FieldValue::Integer(24));
  Filter filter3b = Filter::NotEqualTo("foo", FieldValue::Integer(42));
  Filter filter3c = Filter::NotEqualTo("bar", FieldValue::Integer(42));

  Filter filter4a = Filter::GreaterThan("foo", FieldValue::Integer(24));
  Filter filter4b = Filter::GreaterThan("foo", FieldValue::Integer(42));
  Filter filter4c = Filter::GreaterThan("bar", FieldValue::Integer(42));

  Filter filter5a =
      Filter::GreaterThanOrEqualTo("foo", FieldValue::Integer(24));
  Filter filter5b =
      Filter::GreaterThanOrEqualTo("foo", FieldValue::Integer(42));
  Filter filter5c =
      Filter::GreaterThanOrEqualTo("bar", FieldValue::Integer(42));

  Filter filter6a = Filter::LessThan("foo", FieldValue::Integer(24));
  Filter filter6b = Filter::LessThan("foo", FieldValue::Integer(42));
  Filter filter6c = Filter::LessThan("bar", FieldValue::Integer(42));

  Filter filter7a = Filter::LessThanOrEqualTo("foo", FieldValue::Integer(24));
  Filter filter7b = Filter::LessThanOrEqualTo("foo", FieldValue::Integer(42));
  Filter filter7c = Filter::LessThanOrEqualTo("bar", FieldValue::Integer(42));

  EXPECT_FALSE(filter1a == filter1b);
  EXPECT_FALSE(filter1b == filter1c);
  EXPECT_FALSE(filter2a == filter2b);
  EXPECT_FALSE(filter2b == filter2c);
  EXPECT_FALSE(filter3a == filter3b);
  EXPECT_FALSE(filter3b == filter3c);
  EXPECT_FALSE(filter4a == filter4b);
  EXPECT_FALSE(filter4b == filter4c);
  EXPECT_FALSE(filter5a == filter5b);
  EXPECT_FALSE(filter5b == filter5c);
  EXPECT_FALSE(filter6a == filter6b);
  EXPECT_FALSE(filter6b == filter6c);
  EXPECT_FALSE(filter7a == filter7b);
  EXPECT_FALSE(filter7b == filter7c);

  EXPECT_TRUE(filter1a != filter1b);
  EXPECT_TRUE(filter1b != filter1c);
  EXPECT_TRUE(filter2a != filter2b);
  EXPECT_TRUE(filter2b != filter2c);
  EXPECT_TRUE(filter3a != filter3b);
  EXPECT_TRUE(filter3b != filter3c);
  EXPECT_TRUE(filter4a != filter4b);
  EXPECT_TRUE(filter4b != filter4c);
  EXPECT_TRUE(filter5a != filter5b);
  EXPECT_TRUE(filter5b != filter5c);
  EXPECT_TRUE(filter6a != filter6b);
  EXPECT_TRUE(filter6b != filter6c);
  EXPECT_TRUE(filter7a != filter7b);
  EXPECT_TRUE(filter7b != filter7c);
}

TEST_F(FilterTest, CompositesWithOneFilterAreTheSameAsFilter) {
  Filter filter1 = Filter::EqualTo("foo", FieldValue::Integer(42));
  Filter filter2 = Filter::Or(filter1);
  Filter filter3 = Filter::And(filter1);

  EXPECT_TRUE(filter1 == filter2);
  EXPECT_TRUE(filter1 == filter3);

  EXPECT_FALSE(filter1 != filter2);
  EXPECT_FALSE(filter1 != filter3);
}

TEST_F(FilterTest, EmptyCompositeIsIgnored) {
  Filter filter1 = Filter::And();
  Filter filter2 = Filter::And(Filter::And(), Filter::And());
  Filter filter3 = Filter::And(Filter::Or(), Filter::Or());
  Filter filter4 = Filter::Or();
  Filter filter5 = Filter::Or(Filter::Or(), Filter::Or());
  Filter filter6 = Filter::Or(Filter::And(), Filter::And());

  CollectionReference collection = Collection();

  EXPECT_EQ(filter1, filter2);
  EXPECT_EQ(filter1, filter3);
  EXPECT_EQ(filter4, filter5);
  EXPECT_EQ(filter4, filter6);

  Query query1 = collection.Where(filter1);
  Query query2 = collection.Where(filter2);
  Query query3 = collection.Where(filter3);
  Query query4 = collection.Where(filter4);
  Query query5 = collection.Where(filter5);
  Query query6 = collection.Where(filter6);

  EXPECT_EQ(collection, query1);
  EXPECT_EQ(collection, query2);
  EXPECT_EQ(collection, query3);
  EXPECT_EQ(collection, query4);
  EXPECT_EQ(collection, query5);
  EXPECT_EQ(collection, query6);
}

TEST_F(FilterTest, CompositeComparison) {
  Filter filter1 = Filter::ArrayContains("foo", FieldValue::Integer(42));
  Filter filter2 = Filter::EqualTo("foo", FieldValue::Integer(42));
  Filter filter3 = Filter::NotEqualTo("foo", FieldValue::Integer(42));
  Filter filter4 = Filter::GreaterThan("foo", FieldValue::Integer(42));

  Filter and1 = Filter::And(filter1);
  Filter and2 = Filter::And(filter1, filter2);
  Filter and3 = Filter::And(filter1, filter2, filter3);
  Filter and4 = Filter::And(filter1, filter2, filter3, filter4);

  Filter or1 = Filter::Or(filter1);
  Filter or2 = Filter::Or(filter1, filter2);
  Filter or3 = Filter::Or(filter1, filter2, filter3);
  Filter or4 = Filter::Or(filter1, filter2, filter3, filter4);

  EXPECT_EQ(and1, and1);
  EXPECT_EQ(and2, and2);
  EXPECT_EQ(and3, and3);
  EXPECT_EQ(and4, and4);

  EXPECT_EQ(or1, or1);
  EXPECT_EQ(or2, or2);
  EXPECT_EQ(or3, or3);
  EXPECT_EQ(or4, or4);

  EXPECT_EQ(and1, or1);
  EXPECT_NE(and2, or2);
  EXPECT_NE(and3, or3);
  EXPECT_NE(and4, or4);

  EXPECT_NE(and1, and2);
  EXPECT_NE(and1, and3);
  EXPECT_NE(and1, and4);
  EXPECT_NE(and2, and3);
  EXPECT_NE(and2, and4);
  EXPECT_NE(and3, and4);

  EXPECT_NE(or1, or2);
  EXPECT_NE(or1, or3);
  EXPECT_NE(or1, or4);
  EXPECT_NE(or2, or3);
  EXPECT_NE(or2, or4);
  EXPECT_NE(or3, or4);
}

}  // namespace

}  // namespace firestore
}  // namespace firebase
