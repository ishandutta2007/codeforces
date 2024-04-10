#ifndef DEBUG
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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> arr(n);
  cin >> arr;
  int ans = 0;
  for (int j = 0; j < 26; j++) {
    vector<int> a(n);
    int num = 1 << j;
    for (int i = 0; i < n; i++) {
      a[i] = arr[i] % (num << 1);
    }
    sort(a.begin(), a.end());
    // count a[i] + a[j] >= 3 * num
    // count 2 * num > a[i] + a[j] >= num
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
      int x = a[i];
      a.pop_back();
      cnt += a.end() - lower_bound(a.begin(), a.end(), 3 * num - x);
      cnt += upper_bound(a.begin(), a.end(), 2 * num - x - 1) - lower_bound(a.begin(), a.end(), num - x);
      cnt %= 2;
    }
    ans ^= (1 << j) * (cnt % 2);
  }
  cout << ans << endl;
}