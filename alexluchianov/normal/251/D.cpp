#include <iostream>
#include <vector>

using ll = long long;

int const lgmax = 60;

class Reductor{
private:
  std::vector<std::pair<ll, int>> v;
public: 
  Reductor() {
    
  }
  ll reduce(ll number) {
    for(int i = 0; i < v.size(); i++)
      if((1LL << v[i].second) & number)
        number ^= v[i].first;
    return number;
  }
  void tryAdd(ll number) {
    number = reduce(number);
    for(int i = 0; i < lgmax; i++)
      if((1LL << i) & number) {
        v.push_back({number, i});
        return ;
      }
  }
};

int main() {
  int n;
  std::cin >> n;
  std::vector<ll> v(n), cand;
  ll total = 0;
  for(auto &it : v) {
    std::cin >> it;
    total ^= it;
  }
  
  Reductor red;
  for(int i = 0; i < v.size(); i++) {
    if(red.reduce(v[i]) != 0) {
      red.tryAdd(v[i]);
      cand.push_back(i);
    }
  }

  std::vector<std::pair<ll, ll>> active(cand.size());
  for(int i = 0; i < cand.size(); i++)
    active[i] = {v[cand[i]], (1LL << i)};
  
  ll currSum = 0, currMask = 0;
  
  for(int i = lgmax - 1; 0 <= i; i--) {
    if(0 == ((1LL << i) & total)) {
      for(int j = 0; j < active.size(); j++)
        if(active[j].first & (1LL << i)) {
          
          if(0 == (currSum & (1LL << i))) {
            currSum ^= active[j].first;
            currMask ^= active[j].second;
          }

          for(int j2 = j + 1; j2 < active.size(); j2++) 
            if(active[j2].first & (1LL << i)) {
              active[j2].first ^= active[j].first;
              active[j2].second ^= active[j].second;
            }
          active[j].first = active[j].second = 0;
          break;
        }
    }
  }

  for(int i = lgmax - 1; 0 <= i; i--) {
    if(0 < ((1LL << i) & total)) {

      for(int j = 0; j < active.size(); j++)
        if(active[j].first & (1LL << i)) {
          
          if(0 == (currSum & (1LL << i))) {
            currSum ^= active[j].first;
            currMask ^= active[j].second;
          }

          for(int j2 = j + 1; j2 < active.size(); j2++) 
            if(active[j2].first & (1LL << i)) {
              active[j2].first ^= active[j].first;
              active[j2].second ^= active[j].second;
            }
          active[j].first = active[j].second = 0;
          break;
        }
    }
  }

  std::vector<int> sol(n);
  std::fill(sol.begin(), sol.end(), 1);
  for(int i = 0; i < cand.size(); i++)
    if((1LL << i) & currMask)
      sol[cand[i]] = 2;

  for(int i = 0; i < sol.size(); i++)
    std::cout << sol[i] << " ";
  std::cout << '\n';
  return 0;
}