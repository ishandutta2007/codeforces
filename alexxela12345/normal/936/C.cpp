#ifdef LOCAL
#define _GLIBCXX_DEBUG
#else
#pragma GCC optimize("Ofast,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,abm,mmx,popcnt")
#endif

#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define endl '\n'
#endif

typedef long long ll;
typedef long double ldb;

template<typename T1, typename T2>
istream& operator>>(istream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}

template<typename T1, typename T2>
ostream& operator<<(ostream &out, pair<T1, T2> &p) {
  out << p.first << " " << p.second;
  return out;
}

template<typename T>
istream& operator>>(istream& in, vector<T> &vec) {
  for (auto &el : vec) {
    in >> el;
  }
  return in;
}

template<typename T>
ostream& operator<<(ostream& out, vector<T> &vec) {
  for (auto &el : vec) {
    out << el << " ";
  }
  return out;
}

string do_op(string s, int k) {
  string t;
  for (int i = 0; i < k; i++) {
    t.push_back(s[s.size() - 1 - i]);
  }
  for (int i = 0; i < s.size() - k; i++) {
    t.push_back(s[i]);
  }
  return t;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef LOCAL
  cout << "Running local" << endl;
#endif
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  string ss = s;
  string tt = t;
  sort(ss.begin(), ss.end());
  sort(tt.begin(), tt.end());
  if (ss != tt) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> ops;
  for (int i = 0; i < n; i++) {
    int pos = 0;
    while (s[pos] != t[i]) {
      pos++;
    }
    ops.push_back(n - pos - 1);
    s = do_op(s, ops.back());
    ops.push_back(1);
    s = do_op(s, ops.back());
    ops.push_back(n);
    s = do_op(s, ops.back());
  }
  cout << ops.size() << endl;
  cout << ops << endl;
  assert(s == t);
  return 0;
}