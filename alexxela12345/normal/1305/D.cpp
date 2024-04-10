#define _GLIBCXX_DEBUG
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

vector<set<int>> g;
set<int> pos;
  
int ans;

void dfs(int v) {
  pos.erase(v);
  for (int u : g[v]) {
    g[u].erase(v);
    if (u != ans) {
      dfs(u);
    }
  }
  g[v].clear();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  g.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].insert(b);
    g[b].insert(a);
  }
  for (int i = 0; i < n; i++) {
    pos.insert(i);
  }
  while (pos.size() > 1) {
    if (pos.size() == 2) {
      int a = *pos.begin();
      int b = *pos.rbegin();
      cout << "? " << a + 1 << " " << b + 1 << endl;
      cin >> ans;
      ans--;
      cout << "! " << ans + 1 << endl;
      return 0;
    } else {
      int a, b;
      for (int el : pos) {
        if (g[el].size() >= 2) {
          a = *g[el].begin();
          b = *g[el].rbegin();
          break;
        }
      }
      cout << "? " << a + 1 << " " << b + 1 << endl;
      cin >> ans;
      ans--;
      if (a != ans) {
        dfs(a);
      }
      if (b != ans) {
        dfs(b);
      }
    }
  }
  cout << "! ";
  cout << *pos.begin() + 1 << endl;
}