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
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    set<int> kek;
    for (char c : s) {
      if (kek.count(c)) {
        kek.erase(c);
      } else {
        kek.insert(c);
      }
    }
    for (char c : t) {
      if (kek.count(c)) {
        kek.erase(c);
      } else {
        kek.insert(c);
      }
    }
    if (!kek.empty()) {
      cout << "No" << endl;
      continue;
    }
    cout << "Yes" << endl;
    vector<pair<int, int>> ops;
    for (int i = 0; i < n; i++) {
      if (s[i] == t[i]) {
        continue;
      }
      for (int j = i + 1; j < n; j++) {
        if (s[i] == s[j]) {
          ops.push_back({j + 1, i + 1});
          swap(s[j], t[i]);
          break;
        } else if (s[i] == t[j]) {
          ops.push_back({j + 1, j + 1});
          ops.push_back({j + 1, i + 1});
          swap(s[j], t[j]);
          swap(s[j], t[i]);
          break;
        }
      }
    }
    cout << ops.size() << endl;
    assert(s == t);
    for (auto &el : ops) {
      cout << el.first << " " << el.second << endl;
    }
  }
}