#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>

using ll = long long;

int const nmax = 200000;
int const inf = 1000000000;

std::pair<int,int> v[1 + nmax];
int stage[1 + nmax];
ll startTime[1 + nmax];
ll startBalance[1 + nmax];
std::set<int> myset;

ll race(int x, int y) {
  assert(x != y);
  int start = std::max(startTime[x], startTime[y]);
  ll result = std::max(0LL, (startBalance[x] - startBalance[y] + 
          1LL * (start - startTime[x]) * v[x].first -
         1LL * (start - startTime[y]) * v[y].first +
         (v[y].first - v[x].first - 1)
         ) / (v[y].first - v[x].first)) + start;
  //std::cout << "race: " << x << " " << y << " " << result << '\n'; 
  return result;
}

std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq;

bool insert(int node) {
  if(stage[node] == 0) {
    std::set<int>::iterator it;
    it = myset.upper_bound(node);
    if(it != myset.end()) 
      pq.push({race(node, *it), -node});
    if(it != myset.begin()) {
      it--;
      pq.push({race(*it, node), -(*it)});
    }
    stage[node] = 1;
    myset.insert(node);
    return true;
  }
  return false;
}

bool erase(int node) {
  if(stage[node] == 1) {
    stage[node] = 2;
    myset.erase(node);
    std::set<int>::iterator it, it2;
    it = myset.lower_bound(node);
    if(it != myset.end() && it != myset.begin()) {
      it2 = it;
      it2--;
      pq.push({race(*it2, *it), -(*it2)});
    }
    return true;
  }
  return false;
}

int main() {
  int n;
  ll target;
  std::cin >> n >> target;
  std::vector<std::pair<int,int>> temp;

  for(int i = 1; i <= n; i++) {
    int val, cost;
    std::cin >> val >> cost;
    temp.push_back({val, cost});
  }
  std::sort(temp.begin(), temp.end());
  
  int ptr = 0;
  for(int i = 0; i < temp.size(); i++) {
    while(0 < ptr && temp[i].second <= v[ptr].second)
      ptr--;
    if(0 == ptr || v[ptr].first < temp[i].first)
      v[++ptr] = temp[i];
  }
  n = ptr;
  assert(1 <= n && v[1].second == 0);
  ll result = target;
  pq.push({0, 1});
  ptr = 0;
  
  for(int i = 2; i <= n; i++)
    startTime[i] = inf;

  while(0 < pq.size()) {
    bool isnew = false;
    ll time = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(0 < node) {
      isnew = insert(node);
      ptr = std::max(node, ptr);
    } else {
      isnew = erase(-node);
    }
    if(isnew == true) {
      int node = *myset.begin();
      if(ptr < n) {
        int newtime = startTime[node] + std::max(0LL, (v[ptr + 1].second - startBalance[node] + v[node].first - 1) / v[node].first);
        ll newBalance = startBalance[node] + 1LL * (newtime - startTime[node]) * v[node].first - v[ptr + 1].second;
        if(newtime < startTime[ptr + 1] || (newtime == startTime[ptr + 1] && startBalance[ptr + 1] < newBalance)) {
          startBalance[ptr + 1] = newBalance;
          startTime[ptr + 1] = newtime;
          pq.push({newtime, ptr + 1});
        }
      }
      result = std::min(result,  startTime[node] + std::max(0LL, (target - startBalance[node] + v[node].first - 1)) / (v[node].first));
    }
  }
  std::cout << result << '\n';
  return 0;
}