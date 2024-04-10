#ifndef DEBUG
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
  vector<int> arr(n);
  cin >> arr;
  sort(arr.begin(), arr.end());
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i] == arr[i - 1]) {
      cnt++;
    }
  }
  string first_win = "sjfnb";
  string second_win = "cslnb";
  if (cnt > 1) {
    cout << second_win << endl;
    return 0;
  }
  int cnt2 = 0;
  if (cnt == 1) {
    for (int i = 1; i < n; i++) {
      if (arr[i] == arr[i - 1]) {
        if (i > 1 && arr[i - 2] + 1 == arr[i]) {
          cout << second_win << endl;
          return 0;
        }
        if (arr[i] == 0) {
          cout << second_win << endl;
          return 0;
        }
        arr[i - 1]--;
        cnt2 = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cnt2 += arr[i] - i;
  }
  string ans = (cnt2 % 2 == 0) ? second_win : first_win;
  cout << ans << endl;
}