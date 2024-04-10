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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> starts;
  vector<int> endd;
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;
    vector<int> arr(l);
    cin >> arr;
    bool good = false;
    for (int j = 0; j < l - 1; j++) {
      if (arr[j] < arr[j + 1]) {
        good = 1;
        break;
      }
    }
    if (good)
      continue;
    starts.push_back(arr[0]);
    endd.push_back(arr.back());
  }
  sort(starts.begin(), starts.end());
  int ans = n * n;
  for (int el : endd) {
    ans -= upper_bound(starts.begin(), starts.end(), el) - starts.begin();
  }
  cout << ans << endl;
}