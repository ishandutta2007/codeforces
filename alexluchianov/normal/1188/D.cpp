#pragma GCC optimize ("O3")
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using ll = long long;

int const nmax = 100000;
int const lgmax = 61;

ll v[5 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  //std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

  for(int i = 1; i <= n; i++) {
    std::cin >> v[i];
    //v[i] = std::uniform_int_distribution<ll>(0, (1LL << lgmax))(rng);
  }

  std::vector<std::pair<ll,ll>> events;
  std::vector<std::pair<ll,ll>> bonus;
  std::vector<ll> splits;
  
  events.push_back({0, 0});
  for(int h = lgmax - 1; 0 <= h; h--) {
    bonus.clear();

    ll cap = (1LL << (h + 1));
    int overload = 1;
    if(h == (lgmax - 1))
      overload = n * lgmax;
    for(int i = 1;i <= n; i++) {
      ll x = (v[i] + (1LL << h)) % cap;
      ll y = v[i] % cap;
      if(x < y) {
        bonus.push_back({x, 1 * overload});
        bonus.push_back({y, -1 * overload});
      } else {
        bonus.push_back({x, 1 * overload});
        bonus.push_back({0, 1 * overload});
        bonus.push_back({y, -1 * overload});
      }
    }
     
    bonus.push_back({0, 1});
    bonus.push_back({0, -1});
    
    bonus.push_back({1LL << h, 1});
    bonus.push_back({1LL << h, -1});
    

    for(int i = 0; i < events.size(); i++) {
      bonus.push_back({events[i].first, 1});
      bonus.push_back({events[i].first, -1});
    }

    std::sort(bonus.begin(), bonus.end());
    
    int ptr = 0;
    ll acc = 0;
    std::vector<std::pair<ll,ll>> newEvents, newEvents2;

    for(int i = 0; i < bonus.size(); i++) {
      acc += bonus[i].second;
      if(i + 1 == bonus.size() || bonus[i].first != bonus[i + 1].first) {
        while(ptr + 1 < events.size() && events[ptr + 1].first <= bonus[i].first)
          ptr++;

        ll coef = events[ptr].second + acc;
        if(0 == newEvents.size() || (newEvents.back().second != coef) || bonus[i].first == (1LL << h) ) 
          newEvents.push_back({bonus[i].first, coef});
      }
    }
    splits.clear();

    for(int i = 0; i < newEvents.size(); i++)
      splits.push_back(newEvents[i].first % (1LL << h));
    
    for(int i = 0; i < newEvents.size(); i++)
      if((1LL << h) <= newEvents[i].first) {
        for(int j = i; j < newEvents.size(); j++)
          newEvents2.push_back({newEvents[j].first - (1LL << h), newEvents[j].second});
        newEvents.resize(i);
        break;
      }
    events.clear();
    ptr = 0;
    int ptr2 = 0;
    std::sort(splits.begin(), splits.end());
    splits.erase(std::unique(splits.begin(), splits.end()), splits.end());

    for(int i = 0; i < splits.size(); i++) {
      while(ptr + 1 < newEvents.size() && newEvents[ptr + 1].first <= splits[i])
        ptr++;
      while(ptr2 + 1 < newEvents2.size() && newEvents2[ptr2 + 1].first <= splits[i])
        ptr2++;
      ll coef = std::min(newEvents[ptr].second, newEvents2[ptr2].second);
      if(0 == events.size() || events.back().second != coef)
        events.push_back({splits[i], coef});
    }
  }
  std::cout << events[0].second << '\n';
  return 0; 
}