#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

using ll = long long;

int const nmax = 200000;
int const lgmax = 20;

int far[1 + lgmax][1 + nmax * 4];
ll farp[1 + lgmax][5 + nmax * 4];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int lim, n;
  std::cin >> lim >> n;
  std::vector<std::pair<int,int>> events;
  std::vector<std::pair<int,int>> secEvents;

  for(int i = 1;i <= n; i++) {
    int val;
    std::cin >> val;
    events.push_back({val, 1});
    events.push_back({val + lim, 1});
    secEvents.push_back({val, i});
    secEvents.push_back({val + lim, i});
  }
  for(int i = 1;i <= n; i++) {
    int val;
    std::cin >> val;
    events.push_back({val, -1});
    events.push_back({val + lim, -1});
    secEvents.push_back({val, -i});
    secEvents.push_back({val + lim, -i});
  }
  std::sort(events.begin(), events.end());
  std::vector<ll> sum(events.size());
  for(int i = 0; i < events.size(); i++)
    if(0 < i)
      sum[i] = events[i].first * events[i].second + sum[i - 1];
    else
      sum[i] = events[i].first * events[i].second;
  int acc = 0;
  std::map<int,int> mp;
  for(int i = events.size() - 1; 0 <= i; i--) {
    acc += events[i].second;
    auto it = mp.find(acc);
    if(it != mp.end()) {
      far[0][i] = it->second;
      farp[0][i] = sum[it->second - 1];
      if(0 < i)
        farp[0][i] -= sum[i - 1];
      if(farp[0][i] < 0)
        farp[0][i] = -farp[0][i];
    } else
      far[0][i] = - 1;
    mp[acc] = i;
  }

  for(int h = 1; h < lgmax; h++)
    for(int i = 0; i < events.size(); i++) {
      if(far[h - 1][i] == -1)
        far[h][i] = -1;
      else {
        far[h][i] = far[h - 1][far[h - 1][i]];
        farp[h][i] = farp[h - 1][i] + farp[h - 1][far[h - 1][i]];
      }
    }

  ll result = 2LL * lim * n;
  int startpoint = 0;

  for(int i = 0; i < 2 * n; i++) {
    int node = i;
    ll aux = 0;
    for(int h = lgmax - 1; 0 <= h; h--)
      if(0 <= far[h][node] && far[h][node] <= i + 2 * n) {
        aux += farp[h][node];
        node = far[h][node];
      }

    if(aux <= result) {
      result = aux;
      startpoint = i;
    }
  }

  std::sort(secEvents.begin(), secEvents.end());
  std::vector<int> answer(n);

  std::stack<int> st;

  for(int i = startpoint; i < startpoint + 2 * n; i++) {
    if(0 == st.size() || 0 < 1LL * st.top() * secEvents[i].second)
      st.push(secEvents[i].second);
    else {
      int x = st.top();
      st.pop();
      if(0 < x)
        answer[x - 1] = -secEvents[i].second;
      else
        answer[secEvents[i].second - 1] = -x;
    }
  }

  std::cout << result << '\n';
  for(int i = 0; i < answer.size(); i++)
    std::cout << answer[i] << " ";
  std::cout << '\n';
  return 0;
}