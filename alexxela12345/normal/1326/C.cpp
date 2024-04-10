#ifndef DEBUG
#pragma GCC optimize("Ofast,inline,fast-math,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define max(a, b) (a < b) ? b : a

const int MOD = 998244353;

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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  cin >> arr;
  vector<int> inds;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] > n - k) {
      ans += arr[i];
      inds.push_back(i);
    }
  }
  assert((int) inds.size() == k);
  cout << ans << " ";
  int ans2 = 1;
  for (int i = 0; i < k - 1; i++) {
    ans2 *= inds[i + 1] - inds[i];
    ans2 %= MOD;
  }
  cout << ans2 << endl;
}