#ifndef LOCAL
//#pragma GCC optimize("Ofast,inline,fast-math,unroll-loops,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;

int sign(int a) {
  if (a < 0) {
    return -1;
  }
  if (a == 0) 
    return 0;
  return 1;
}

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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    int x;
    int n;
    cin >> n >> x >> s;
    int sum = 0;
    x *= -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        sum--;
      } else {
        sum++;
      }
    }
    int ans = 0;
    int cur_sum = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        cur_sum--;
      } else {
        cur_sum++;
      }
      if (sum != 0) {
        if (sign(x - cur_sum) * sign(sum) >= 0 && (x - cur_sum) % sum == 0) {
          ans++;
        }
      } else {
        if (x == cur_sum) {
          ans++;
        }
      }
    }
    if (sum == 0 && ans) {
      ans = -1;
    } else if (x == 0) {
      ans++;
    }
    cout << ans << endl;
  }
}