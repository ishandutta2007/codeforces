#ifndef LOCAL
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
    out << el << " ";
  }
  return out;
}

template<typename T1, typename T2> 
ostream &operator>>(ostream &out, pair<T1, T2> &p) {
  out << p.first << " " << p.second;
  return out;
}

vector<vector<int>> ops;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  while (true) {
    int n = s.size();
    vector<int> cnt1(n), cnt2(n);
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        cnt1[i] = 1;
      }
      if (i)
        cnt1[i] += cnt1[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == ')') {
        cnt2[i] = 1;
      }
      if (i != n - 1) {
        cnt2[i] += cnt2[i + 1];
      }
    }
    int max_cnt = 0;
    for (int i = 0; i < n - 1; i++) {
      int cnt = min(cnt1[i], cnt2[i + 1]);
      if (cnt > max_cnt) {
        max_cnt = cnt;
      }
    }
    if (max_cnt == 0)
      break;
    vector<int> inds;
    int cur = 0;
    int i;
    for (i = 0; i < n; i++) {
      if (s[i] == '(') {
        cur++;
        inds.push_back(i + 1);
      }
      if (cur == max_cnt) {
        break;
      }
    }
    cur = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == ')') {
        cur++;
        inds.push_back(i + 1);
      }
      if (cur == max_cnt) {
        break;
      }
    }
    reverse(inds.begin() + cur, inds.end());
    ops.push_back(inds);
    reverse(inds.begin(), inds.end());
    for (int el : inds)
      s.erase(s.begin() + el - 1);
  }
  cout << ops.size() << endl;
  for (auto &el : ops) {
    cout << el.size() << endl;
    cout << el << endl;
  }
}