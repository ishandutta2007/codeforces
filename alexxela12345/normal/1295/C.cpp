#ifndef LOCAL
//#pragma GCC optimize("Ofast,inline,fast-math,unroll-loops,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
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

void solve() {
  string s;
  string t;
  cin >> s >> t;
  map<char, vector<int>> pos;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    pos[s[i]].push_back(i);
  }
  int ans = 0;
  int cur_pos = -1;
  for (int j = 0; j < (int) t.size(); j++) {
    if (pos[t[j]].empty()) {
      cout << -1 << endl;
      return;
    }
    if (cur_pos > *pos[t[j]].rbegin()) {
      ans++;
      cur_pos = *pos[t[j]].begin() + 1;
    } else {
      int kek = *lower_bound(pos[t[j]].begin(), pos[t[j]].end(), cur_pos);
      cur_pos = kek + 1;
    }
  }
  cout << ans + 1 << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}