#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 2e5 + 5;

int root [MAX_N];
int find (int u) {
  if (root[u] != u) {
    root[u] = find(root[u]);
  }
  return root[u];
}

void merge (int u, int v) {
  u = find(u);
  v = find(v);

  root[u] = v;
}

int lfend [MAX_N];
int rgend [MAX_N];

int main () {
  for (int i = 0; i < MAX_N; i++) {
    root[i] = i;
    lfend[i] = MAX_N;
    rgend[i] = -1;
  }

  ios::sync_with_stdio(false);

  int vertexc, edgec;
  cin >> vertexc >> edgec;

  for (int i = 0; i < edgec; i++) {
    int u, v;
    cin >> u >> v;

    merge(u, v);
  }

  for (int i = 1; i <= vertexc; i++) {
    int u = find(i);
    lfend[u] = min(lfend[u], i);
    rgend[u] = max(rgend[u], i);
  }

  vector<pair<int, int>> events;
  for (int i = 1; i <= vertexc; i++) {
    if (lfend[i] <= rgend[i]) {
      events.push_back({lfend[i], 1});
      events.push_back({rgend[i], 2});
    }
  }

  sort(events.begin(), events.end());
  int cur_segc = 0;
  int ans = 0;
  for (auto e : events) {
    if (e.second == 1) {
      if (cur_segc > 0) {
        ans++;
      }
      cur_segc++;
    } else {
      cur_segc--;
    }
  }

  cout << ans << endl;
}