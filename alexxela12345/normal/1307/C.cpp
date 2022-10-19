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
  string s;
  cin >> s;
  map<string, int> cnt;
  map<char, int> cnt2;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    for (auto &el : cnt2) {
      string ss;
      ss.push_back(el.first);
      ss.push_back(s[i]);
      cnt[ss] += el.second;
    }
    cnt2[s[i]]++;
  }
  int max_ans = 0;
  for (auto &el : cnt) {
    max_ans = max(max_ans, el.second);
  }
  for (auto &el : cnt2) {
    max_ans = max(max_ans, el.second);
  }
  cout << max_ans << endl;
}