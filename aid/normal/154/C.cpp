#include <stdio.h>
#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <cstring>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int kN = 1000 * 1000;
const int kMod0 = 1000 * 1000 * 1000 + 7;
const int kMod1 = 1000 * 1000 * 1000 + 9;
const int kBase = 1000 * 1000 * 10;

vector<int> g[kN];

pll Hash(const vector<int>& a) {
  pll hash;
  for (auto x : a) {
    hash.first = (hash.first * kBase + x + 1) % kMod0;
    hash.second = (hash.second * kBase + x + 1) % kMod1;
  }
  return hash;
}

ll F(const vector<pll>& a) {
  ll res = 0;
  pll prev(-1, -1);
  ll cnt = 0;
  for (auto x : a) {
    if (prev != x) {
      res += cnt * (cnt - 1) / 2;
      prev = x;
      cnt = 1;
    } else {
      ++cnt;
    }
  }
  res += cnt * (cnt - 1) / 2;
  return res;
}

int main() {
  // std::ios_base::sync_with_stdio(false);
  int n, m;
  // cin >> n >> m;
  scanf("%d%d", &n, &m);
  vector<pii> a(m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    // cin >> u >> v;
    scanf("%d%d", &u, &v);
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<pll> hs(n);
  vector<pll> hashes(n);
  for (int i = 0; i < n; ++i) {
    sort(g[i].begin(), g[i].end());
    hs[i] = Hash(g[i]);
    g[i].push_back(i);
    sort(g[i].begin(), g[i].end());
    hashes[i] = Hash(g[i]);
  }
  sort(hs.begin(), hs.end());
  ll res = F(hs);
  for (int i = 0; i < n; ++i) {
    int u = i;
    for (int j = 0; j < g[i].size(); ++j) {
      int v = g[u][j];
      if (v >= u) {
        break;
      }
      if (hashes[u] == hashes[v]) {
        ++res;
      }
    }
  }
  cout << res; 
  return 0;
}