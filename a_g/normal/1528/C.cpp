#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 3e5+2;
int n;
int timer;
int ans;
vector<int> ca[N];
vector<int> cb[N];
int tin[N];
int tout[N];

ordered_set<pair<int, int>> o;

void dfs1(int v) {
  tin[v] = ++timer;
  for (int u: cb[v]) {
    dfs1(u);
  }
  tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

void dfs2(int v) {
  pair<int, int> vz = {tin[v], v};
  int k = o.order_of_key(vz);
  bool inserted = 1;
  pair<int, int> removed_element = {0, 0};
  if (k) {
    // find the ancestor of v, if it exists
    pair<int, int> uz = *o.find_by_order(k-1);
    if (is_ancestor(uz.second, v)) {
      o.erase(uz);
      removed_element = uz;
    }
  }

  if (k < o.size()) {
    // find a descendant of v, if it exists
    pair<int, int> uz = *o.find_by_order(k);
    if (is_ancestor(v, uz.second)) {
      inserted = 0;
    }
  }

  if (inserted) o.insert(vz);

  for (int u: ca[v]) {
    dfs2(u);
  }

  ans = max<int>(ans, o.size());
  if (inserted) o.erase(vz);
  if (removed_element.first) o.insert(removed_element);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      ca[i].clear();
      cb[i].clear();
    }
    for (int i = 2; i <= n; i++) {
      int p;
      cin >> p;
      ca[p].push_back(i);
    }
    for (int i = 2; i <= n; i++) {
      int p;
      cin >> p;
      cb[p].push_back(i);
    }

    timer = 0;
    dfs1(1);

    ans = 0;
    dfs2(1);

    cout << ans << '\n';
  }
}