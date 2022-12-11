#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


template<typename Map>
Map read_map(istream& stream = cin);

template<typename Map>
Map read_map_of_size(size_t size, istream& stream = cin);

template<typename MapOut, typename Map, typename Operation>
MapOut map_sum(const Map& a, const Map& b, Operation op, typename Map::value_type::second_type def);

template<typename ContainerOut, typename ContainerIn>
ContainerOut value_set(const ContainerIn& container);

template<typename Container>
typename Container::value_type sum(const Container& container);


template<typename Container>
void print_container(const Container& container, ostream& stream = cout);

template<typename Container, typename Filter>
Container filter(const Container& container, Filter fliter);


template<typename Container>
Container sorted(const Container &a);

void fast_io();


int main() {
  fast_io();
  auto first_set = sorted(read_map<vector<pair<int, int>>>());
  auto second_set = sorted(read_map<vector<pair<int, int>>>());

  auto maxi =  [](int a, int b) -> int { return max(a, b); };
  auto union_set = map_sum<vector<pair<int, int>>>(first_set, second_set, maxi, 0);

  cout << sum(value_set<vector<long long>>(union_set)) << endl;
  return 0;
}


template<typename Map>
Map read_map(istream& stream) {
  size_t size;
  cin >> size;
  return read_map_of_size<Map>(size, stream);
}

template<typename Map>
Map read_map_of_size(size_t size, istream& stream) {
  Map res;
  for(size_t i = 0;i < size;i++) {
    typename Map::value_type::first_type key;
    typename Map::value_type::second_type value;
    stream >> key >> value;
    inserter(res, res.end()) = make_pair(key, value);
  }
  return res;
}

template<typename MapOut, typename Map, typename Operation>
MapOut map_sum(const Map& a, const Map &b, Operation op, typename Map::value_type::second_type def) {
  MapOut res;

  typename Map::const_iterator b_it = b.begin();
  for(auto pair : a) {
    while(b_it != b.end() && b_it->first < pair.first) {
      inserter(res, res.end()) = make_pair(b_it->first, op(def, b_it->second));
      b_it++;
    }

    if(b_it == b.end() || b_it->first != pair.first) {
      inserter(res, res.end()) = make_pair(pair.first, op(pair.second, def));
    }
    else {
      inserter(res, res.end()) = make_pair(pair.first, op(pair.second, b_it->second));
      b_it++;
    }
  }

  while(b_it != b.end()) {
    inserter(res, res.end()) = make_pair(b_it->first, op(def, b_it->second));
    b_it++;
  }
  
  return res;
}

template<typename ContainerOut, typename ContainerIn>
ContainerOut value_set(const ContainerIn& container) {
  ContainerOut values;
  for(typename ContainerIn::value_type p : container) {
    inserter(values, values.end()) = p.second;
  }
  return values;
}

template<typename Container>
typename Container::value_type sum(const Container& container) {
  typename Container::value_type sum = 0;
  for(auto elem : container) {
    sum += elem;
  }
  return sum;
}


template<typename Container>
void print_container(const Container& container, ostream& stream) {
  #ifndef print_hide_size
  stream << container.size() << endl;
  #endif
  
  for(typename Container::value_type elem : container) {
    stream << elem;
    #ifndef print_separator
    stream << " ";
    #endif
  }
  
  #ifndef print_no_endl
  stream << endl;
  #endif
}

template<typename Container, typename Filter>
Container filter(const Container& container, Filter filter) {
  Container filtered;
  for(typename Container::value_type elem : container) {
    if(filter(elem)) {
      inserter(filtered, filtered.end()) = elem;
    }
  }
  return filtered;
}

template<typename Container>
Container sorted(const Container &a) {
  Container res = a;
  sort(res.begin(), res.end());
  return res;
}

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}