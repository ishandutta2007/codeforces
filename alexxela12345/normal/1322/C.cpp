#ifndef LOCAL
#pragma GCC optimize("Ofast,inline,fast-math,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;

#define int long long

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

int gcd(int a, int b) {
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}

const int MOD = 1e9 + 7;
int p = 517;
const int MAXN = 1e6;
int ppow[MAXN];

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> h(n);
  vector<int> c(n);
  cin >> c;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    h[b - 1] += ppow[a - 1];
    h[b - 1] %= MOD;
  }
  map<int, int> mapa;
  for (int i = 0; i < n; i++) {
    if (h[i] == 0)
      continue;
    mapa[h[i]] += c[i];
  }
  int gg = 0;
  for (auto &el : mapa) {
    gg = gcd(el.second, gg);
  }
  cout << gg << '\n';
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ppow[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    ppow[i] = 1LL * ppow[i - 1] * p % MOD;
  }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}