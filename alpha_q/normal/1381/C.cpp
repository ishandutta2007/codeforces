#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

bitset <N> vis;
vector <int> pos[N];
int t, n, x, y, b[N], ans[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%d %d %d", &n, &x, &y);
    for (int i = 1; i <= n + 1; ++i) {
      vis[i] = 0, pos[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", b + i);
      vis[b[i]] = 1, pos[b[i]].emplace_back(i);
    }
    int magic = -1;
    for (int i = 1; i <= n + 1; ++i) {
      if (!vis[i]) {
        magic = i;
        break;
      }
    }
    assert(magic != -1);
    y -= x;
    priority_queue <pair <int, int>> pq;
    for (int i = 1; i <= n + 1; ++i) {
      pq.emplace(pos[i].size(), i);
    }
    for (int i = 1; i <= n; ++i) {
      ans[i] = -1;
    }
    for (int i = 0; i < x; ++i) {
      int v = pq.top().second; pq.pop();
      assert(!pos[v].empty());
      ans[pos[v].back()] = b[pos[v].back()];
      pos[v].pop_back();
      pq.emplace(pos[v].size(), v);
    }
    int v = pq.top().second;
    if (pos[v].size() * 2 > n - x and y > 2 * (n - x - pos[v].size())) {
      puts("NO");
      continue;
    }
    int rem = n - x;
    while (!pos[v].empty() and pos[v].size() * 2 > rem) {
      pos[v].pop_back(), --rem;
    }
    vector <int> vec;
    while (!pq.empty()) {
      int v = pq.top().second; pq.pop();
      while (!pos[v].empty()) {
        vec.emplace_back(pos[v].back());
        pos[v].pop_back(); 
      }
    }
    int at = 0;
    while (at < vec.size() and b[vec[at]] == b[vec[0]]) ++at;
    for (int i = 0; i < y; ++i) {
      ans[vec[i]] = b[vec[at]];
      ++at; if (at == vec.size()) at = 0;
    }
    // for (int i = 1; i <= n; ++i) {
    //   printf("%d ", ans[i]);
    // }
    // puts("");
    for (int i = 1; i <= n; ++i) {
      if (ans[i] == -1) ans[i] = magic;
    }
    puts("YES");
    for (int i = 1; i <= n; ++i) {
      printf("%d ", ans[i]);
    }
    puts("");
  }
  return 0;
}