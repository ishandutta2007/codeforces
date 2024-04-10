#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;

typedef long long ll;

#define l first
#define r second

template <typename T>
using ordered_set = tree<T, null_type, less<T>,
  rb_tree_tag, tree_order_statistics_node_update>;

const int MAX_N = 1e6 + 5;

int root [MAX_N];

int find (int u) {
  if (u != root[u]) {
    root[u] = find(root[u]);
  }
  return root[u];
}

void merge (int u, int v) {
  u = find(u);
  v = find(v);

  root[u] = v;
}

int main () {
  for (int i = 0; i < MAX_N; i++) {
    root[i] = i;
  }
  
  ios::sync_with_stdio(false);

  int segc;
  cin >> segc;

  vector<pair<int, int>> segs (segc);
  vector<pair<int, pair<int, int>>> events;
  for (int i = 0; i < segc; i++) {
    cin >> segs[i].l >> segs[i].r;

    events.push_back({segs[i].l, segs[i]});
    events.push_back({segs[i].r, segs[i]});
  }
  
  int edgec = 0;
  ordered_set<int> active; // r
  sort(events.begin(), events.end());
  for (auto cur : events) {
    auto seg = cur.second;
    if (seg.l == cur.first) {
      edgec += active.order_of_key(seg.r);
      if (edgec > segc - 1) {
        cout << "NO" << endl;
        return 0;
      }

      for (auto u : active) {
        if (u > seg.r) {
          break;
        }

        if (find(u) == find(seg.r)) {
          cout << "NO" << endl;
          return 0;
        }

        merge(u, seg.r);
      }
      
      active.insert(seg.r);
    } else if (seg.r == cur.first) {
      active.erase(seg.r);
    }
  }

  if (edgec != segc - 1) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}