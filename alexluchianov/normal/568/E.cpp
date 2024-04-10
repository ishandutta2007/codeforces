#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cassert>
#include <map>

using ll = long long;

int const nmax = 100000;
int v[5 + nmax];
std::map<int,int> frec;
std::set<int> active;

int pos[1 + 20 * nmax], val[1 + 20 * nmax], last[1 + 20 * nmax], currId = 0;
std::set<std::pair<int,int>> myset;

void insert(int pos_, int val_) {
  std::set<std::pair<int,int>>::iterator it = myset.lower_bound({val_, 0}), it2;
  ++currId;
  pos[currId] = pos_;
  val[currId] = val_;
  last[currId] = -1;
  
  if(frec.find(val_) != frec.end())
    active.erase(val_);

  if(it == myset.end()) {
    if(0 < myset.size()) 
      last[currId] = myset.rbegin()->second;
    myset.insert({val_, currId});
  } else if(val_ < it->first) {
    it2 = it;
    if(it2 != myset.begin()) {
      it2--;
      last[currId] = it2->second;
    }
    myset.insert({val_, currId});
    if(frec.find(it->first) != frec.end())
      active.insert(it->first);
    myset.erase(it);
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  std::cin >> m;
  for(int i = 1;i <= m; i++) {
    int temp;
    std::cin >> temp;
    frec[temp]++;
    active.insert(temp);
  }
  for(int i = 1;i <= n; i++) {
    if(v[i] != -1) {
      insert(i, v[i]);
    } else {
      std::vector<int> aux;
      int last = 0;
      std::set<int>::iterator it = active.begin();
      while(it != active.end()) {
        aux.push_back(*it);
        std::set<std::pair<int,int>>::iterator it2 = myset.lower_bound({*it, 0});
        if(it2 != myset.end())
          it = active.lower_bound(it2->first);
        else
          break;
      }
      for(int j = aux.size() - 1; 0 <= j; j--)
        insert(i, aux[j]);
    }
  }

  assert(0 < myset.size());
  std::set<std::pair<int,int>>::iterator it = myset.end();
  it--;
  int node = it->second;
  while(-1 != node) {
    if(v[pos[node]] == -1) {
      v[pos[node]] = val[node];
      frec[val[node]]--;
    }
    node = last[node];
  }
  for(int i = 1;i <= n; i++) {
    if(-1 != v[i])
      std::cout << v[i] << " ";
    else {
      while(0 == frec.begin()->second)
        frec.erase(frec.begin());
      std::cout << frec.begin()->first << " " ;
      frec.begin()->second--;
    }
  }
  std::cout << '\n';
  return 0;
}