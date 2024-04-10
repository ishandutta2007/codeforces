#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using ll = long long;

int const nmax = 100000;
int sol[5 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int,std::pair<int,int>>> events;
  std::multiset<int> myset;

  for(int i = 1; i <= m; i++) {
    int l, r, t;
    std::cin >> l >> r >> t;
    events.push_back({l, {1, t}});
    events.push_back({r, {2, t}});
  }

  int last = 0;
  std::sort(events.begin(), events.end());
  std::vector<std::pair<int,int>> events2;
  
  for(int i = 0; i < events.size(); i++) {
    int pos = events[i].first;
    int op = events[i].second.first;
    int val = events[i].second.second;
    if(last < pos && 0 < myset.size()) {
      int temp = *myset.begin();
      /*
        The wall is between [last, pos] and it appears at moment temp
      */
      events2.push_back({temp - (pos), -1});
      events2.push_back({temp - (last), -2});
    }
    last = pos;
    if(op == 1)
      myset.insert(val);
    else
      myset.erase(myset.find(val));
  }

  for(int i = 1;i <= n; i++) {
    int x;
    std::cin >> x;
    events2.push_back({x, i});
  }
  std::sort(events2.begin(), events2.end());
  
  last = 0;
  int acc = 0;
  int result = 0;

  for(int i = 0; i < events2.size(); i++) {
    int time = events2[i].first;
    int op = events2[i].second;
    result += acc * (time - last);
    last = time;
    if(op == -1)
      acc++;
    else if(op == -2)
      acc--;
    else
      sol[op] = result;
  }

  for(int i = 1;i <= n; i++)
    std::cout << sol[i] << '\n'; 
  return 0;
}