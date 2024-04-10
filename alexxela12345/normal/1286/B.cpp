#ifndef LOCAL
#pragma GCC optimize("Ofast,inline,fast-math,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;

#define max(a, b) (a < b) ? b : a

template<typename T>
istream &operator>>(istream &in, vector<T> &arr) {
  for (auto &el : arr) {
    in >> el;
  }
  return in;
}

template<typename T1, typename T2> 
istream &operator>>(istream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}

template<typename T>
ostream &operator<<(ostream &out, vector<T> &arr) {
  for (auto &el : arr) {
    out << el;
  }
  return out;
}

template<typename T1, typename T2> 
ostream &operator>>(ostream &out, pair<T1, T2> &p) {
  out << p.first << " " << p.second;
  return out;
}

int n;
vector<vector<int>> g;
vector<int> c;
vector<int> tin;
vector<int> tout;
vector<int> ord;
vector<int> sz;
int cur_time = 0;

map<int, int> dfs(int v) {
  tin[v] = cur_time++;
  ord.push_back(v);
  int cc = c[v];
  sz[v] = 1;
  map<int, int> m;
  for (int u : g[v]) {
    auto mm = dfs(u);
    sz[v] += sz[u];
    int add = m.size();
    for (auto pp : mm) {
      m[pp.first] = pp.second + add;
    }
  }
  for (auto &el : m) {
    if (el.second >= cc + 1) {
      el.second++;
    }
  }
  m[v] = cc + 1;
  tout[v] = cur_time;
  return m;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  sz.resize(n);
  tin.resize(n);
  tout.resize(n);
  g.resize(n);
  c.resize(n);
  int root = -1;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p >> c[i];
    if (p == 0)
      root = i;
    else
      g[p - 1].push_back(i);
  }
  auto m = dfs(root);
  for (int i = 0; i < n; i++) {
    if (c[i] >= sz[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    assert(m.find(i) != m.end());
    int cntt = 0;
    for (int j = tin[i] + 1; j < tout[i]; j++) {
      if (m[ord[j]] < m[i]) {
        cntt++;
      }
    }
    assert(cntt == c[i]);
    cout << m[i] << " ";
  }
  cout << endl;
}