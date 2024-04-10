#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

long long safe_mod(long long a, long long mod);


template<typename Container, typename HashType = long long>
class prefix_hash_table {
private:
  HashType mod, mult;
  vector<HashType> table, powers;
public:
  prefix_hash_table(const Container &a, HashType _mod = 1000000007, HashType _mult = 31);
  prefix_hash_table();
  HashType hash_between(size_t begin, size_t end);
};

template< typename ContainerOut, typename ContainerIn, typename Operation>
ContainerOut apply(const ContainerIn& container, Operation op);

template<typename Param>
class is_equal {
private:
  Param value;
public:
  is_equal(Param _value);
  bool operator ()(const Param& a);
};


template<typename Container>
Container sorted(const Container &a);


template<typename Container>
void print_container(const Container& container, ostream& stream = cout);


prefix_hash_table<vector<int>> tables[26];

int main() {
  int nb_chars, nb_requests;
  scanf("%d%d", &nb_chars, &nb_requests);

  string chars;
  cin >> chars;

  for(char car = 'a';car <= 'z';car++) {
    tables[car-'a'] = prefix_hash_table<vector<int>>(apply<vector<int>>(chars, is_equal<char>(car)));
  }

  for(int req = 0;req < nb_requests;req++) {
    int x, y, len;
    scanf("%d%d%d", &x, &y, &len);
    x--; y--;

    vector<int> occsX, occsY;
    for(char car = 'a';car <= 'z';car++) {
      occsX.push_back(tables[car-'a'].hash_between(x, x+len));
      occsY.push_back(tables[car-'a'].hash_between(y, y+len));
    }

    if(sorted(occsX) == sorted(occsY)) {
      printf("YES\n");
    }
    else {
      printf("NO\n");
    }
  }

  return 0;
}


long long safe_mod(long long a, long long mod) {
  return ((a % mod) + mod) % mod;
}

template<typename Container, typename HashType>
prefix_hash_table<Container, HashType>::prefix_hash_table(const Container &a, HashType _mod, HashType _mult) {
  mod = _mod;
  mult = _mult;
  
  HashType prefix_hash = 0, power = 1;
  table.push_back(prefix_hash);
  powers.push_back(power);

  for(auto elem : a) {
    prefix_hash = prefix_hash + power * safe_mod(hash<typename Container::value_type>()(elem), mod);
    prefix_hash %= mod;

    table.push_back(prefix_hash);
    
    power = power * mult;
    power %= mod;
    powers.push_back(power);
  }
}

template<typename Container, typename HashType>
prefix_hash_table<Container, HashType>::prefix_hash_table() {}

template<typename Container, typename HashType>
HashType prefix_hash_table<Container, HashType>::hash_between(size_t begin, size_t end) {
  return safe_mod(safe_mod(table[end] - table[begin], mod) * powers[powers.size() - 1 - begin], mod);
}

template< typename ContainerOut, typename ContainerIn, typename Operation>
ContainerOut apply(const ContainerIn& container, Operation op) {
  ContainerOut res;
  for(auto elem : container) {
    inserter(res, res.end()) = op(elem);
  }
  return res;
}

template<typename Param>
is_equal<Param>::is_equal(Param _value) {
  value = _value;
}

template<typename Param>
bool is_equal<Param>::operator ()(const Param &a) {
  return a == value;
}

template<typename Container>
Container sorted(const Container &a) {
  Container res = a;
  sort(res.begin(), res.end());
  return res;
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