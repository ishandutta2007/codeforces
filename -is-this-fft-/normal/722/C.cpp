#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;

int root [MAX_N];
ll sz [MAX_N];

int find (int u) {
  if (root[u] != u) {
    root[u] = find(root[u]);
  }
  return root[u];
}

void merge (int u, int v) {
  u = find(u);
  v = find(v);

  if (u == v) {
    return;
  }

  root[u] = v;
  sz[v] += sz[u];
}

ll arr [MAX_N];
bool alive [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    root[i] = i;
    sz[i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  vector<int> ord (n);
  for (int i = 0; i < n; i++) {
    cin >> ord[i];
  }
  reverse(ord.begin(), ord.end());

  ll cur = 0;
  vector<ll> ans;
  for (int u : ord) {
    ans.push_back(cur);
    
    alive[u] = true;
    sz[u] = arr[u];

    if (alive[u - 1]) {
      merge(u - 1, u);
    }

    if (alive[u + 1]) {
      merge(u + 1, u);
    }

    cur = max(cur, sz[find(u)]);
  }

  reverse(ans.begin(), ans.end());

  for (auto u : ans) {
    cout << u << '\n';
  }
}