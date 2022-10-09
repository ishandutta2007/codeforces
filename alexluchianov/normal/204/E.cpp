#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>

using ll = long long;

int const sigma = 26;

int lg(int number) {
  return 31 - __builtin_clz(number);
}

/*
returns vector with positions in suffix array
*/
std::vector<int> suffixArray(std::vector<int> v) {
  int n = v.size();
  int lim = lg(n) + 1;

  std::vector<int> pos(n);
  for(int i = 0;i < n; i++)
    pos[i] = v[i];

  for(int h = 1; h <= lim; h++) {
    std::vector<std::pair<ll, int>> aux;
    for(int i = 0; i < n; i++) {
      int halfjump = (1 << (h - 1));
      if(i + halfjump < n)
        aux.push_back({1LL * pos[i] * (n + 1) + pos[i + halfjump], i});
      else
        aux.push_back({1LL * pos[i] * (n + 1), i});
    }
    std::sort(aux.begin(), aux.end());
    int ptr = 0;
    for(int i = 0; i < aux.size(); i++) {
      if(0 == i || aux[i].first != aux[i - 1].first) 
        ++ptr;
      pos[aux[i].second] = ptr;
    }
  }
  for(int i = 0; i < n; i++)
    pos[i]--;

  return pos;
}

std::vector<int> kasai(std::vector<int> v, std::vector<int> pos) {
  assert(v.size() == pos.size());
  int n = v.size();
  std::vector<int> lcp(n), s(n);
  for(int i = 0; i < n; i++)
    s[pos[i]] = i;

  for(int i = 0; i < n; i++) {
    int target = pos[i];
    if(target < n - 1) {
      if(0 < i)
        lcp[target] = std::max(0, lcp[pos[i - 1]] - 1);

      while(s[target] + lcp[target] < n && 
            s[target + 1] + lcp[target] < n &&
            v[s[target] + lcp[target]] == v[s[target + 1] + lcp[target]])
        lcp[target]++;
    }
  }
  return lcp;
}

class Dsu{
private:
  std::vector<int> mult;
  std::vector<std::set<int>> myset;
  std::vector<std::vector<int>> elements;
  std::vector<int> sol;
  int k;
public:
  Dsu(int n, int k_, std::vector<int> &origin) {
    k = k_;
    mult.resize(n);
    sol.resize(n);
    myset.resize(n);
    elements.resize(n);
    for(int i = 0; i < n; i++) {
      mult[i] = i;
      if(0 < origin[i]) {
        elements[i].push_back(i);
        myset[i].insert(origin[i]);
      }
    }
  }
  int jump(int gala) {
    if(gala != mult[gala])
      mult[gala] = jump(mult[gala]);
    return mult[gala];
  }
  
  void unite(int gala, int galb, int time) {
    gala = jump(gala);
    galb = jump(galb);
    if(gala == galb)
      return ;

    if(myset[galb].size() < myset[gala].size())
      std::swap(gala, galb);
    mult[gala] = galb;
    int preva = myset[gala].size(), prevb = myset[galb].size();
    for(std::set<int>::iterator it = myset[gala].begin(); it != myset[gala].end(); it++)
      myset[galb].insert(*it);
    
    if(k <= myset[galb].size()) {
      if(preva < k) {
        for(int i = 0; i < elements[gala].size(); i++)
          sol[elements[gala][i]] = time;
      }
      if(prevb < k)
        for(int i = 0; i < elements[galb].size(); i++)
          sol[elements[galb][i]] = time;
    }
      
    if(elements[galb].size() < elements[gala].size())
      std::swap(elements[gala], elements[galb]);
    for(int i = 0; i < elements[gala].size(); i++)
      elements[galb].push_back(elements[gala][i]);
    elements[gala].clear();
    myset[gala].clear();
  }

  std::vector<int> collect() {
    return sol;
  }
  std::vector<int> sizes() {
    std::vector<int> sol(myset.size());
    for(int i = 0; i < myset.size(); i++)
      sol[i] = myset[i].size();
    return sol;
  }
};

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;
  std::vector<int> v, origin;
  for(int i = 1;i <= n; i++) {
    std::string s;
    std::cin >> s;
    for(int j = 0; j < s.size(); j++) {
      v.push_back(s[j] - 'a' + 1);
      origin.push_back(i);
    }
    v.push_back(sigma + i);
    origin.push_back(0);
    if(k == 1)
      std::cout << 1LL * s.size() * (s.size() + 1) / 2 << '\n';
  }
  if(k == 1)
    return 0;

  std::vector<int> pos = suffixArray(v);
  std::vector<int> lcp = kasai(v, pos);
  
  std::vector<std::pair<int,int>> events;
  for(int i = 0; i + 1 < v.size(); i++)
    events.push_back({lcp[i], i});
  
  std::vector<int> origin2(v.size());
  for(int i = 0; i < v.size(); i++)
    origin2[pos[i]] = origin[i];

  Dsu dsu(v.size(), k, origin2);
  std::sort(events.begin(), events.end());
  std::reverse(events.begin(), events.end());
  for(int i = 0; i < events.size(); i++) {
    int node = events[i].second, time = events[i].first;
    dsu.unite(node, node + 1, time);
  }
  std::vector<int> sol = dsu.collect();
  
  std::vector<ll> answer(n);
  
  for(int i = 0; i < v.size(); i++)
    if(0 < origin2[i]) { 
      answer[origin2[i] - 1] += sol[i];
    }
  for(int i = 0; i < answer.size(); i++)
    std::cout << answer[i] << " ";
  std::cout << '\n';
  return 0;
}