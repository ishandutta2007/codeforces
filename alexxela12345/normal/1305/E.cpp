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
    out << el << " ";
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
  int n, m;
  cin >> n >> m;
  vector<int> arr;
  int cur = 0;
  while (cur + (int) arr.size() / 2 <= m && (int) arr.size() < n) {
    cur += arr.size() / 2;
    arr.push_back(arr.size() + 1);
  }
  int rem = m - cur;
  if ((int) arr.size() == n && rem) {
    cout << -1 << endl;
    return 0;
  }
  if ((int) arr.size() == n) {
    cout << arr << endl;
    return 0;
  }
  if (rem)
    arr.push_back(2 * arr.back() - 2 * rem + 1);
  assert(arr.back() > 0);
  int step = arr.back() + 1;
  cur = 1e9;
  while (arr.size() < n) {
    arr.push_back(cur);
    cur -= step;
  }
  sort(arr.begin(), arr.end());
  cout << arr << endl;
}