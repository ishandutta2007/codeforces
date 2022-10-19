#ifndef DEBUG
#pragma GCC optimize("Ofast,inline,fast-math,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
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

string get(string s) {
  string ss = s;
  ss.push_back('#');
  reverse(s.begin(), s.end());
  ss = ss + s;
  int n = ss.size();
  vector<int> pref(n);
  reverse(s.begin(), s.end());
  for (int i = 1; i < n; i++) {
    int k = pref[i - 1];
    while (k > 1 && ss[i] != ss[k]) {
      k = pref[k - 1];
    }
    if (ss[i] == ss[k]) {
      k++;
    }
    pref[i] = k;
  }
  string ans;
  for (int i = 0; i < pref.back(); i++) {
    ans.push_back(s[i]);
  }
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int l = 0;
    int r = n - 1;
    string ansl;
    while (l < r && s[l] == s[r]) {
      ansl.push_back(s[l]);
      l++;
      r--;
    }
    string s2 = s.substr(l, n - 2 * l);
    string a = get(s2);
    reverse(s2.begin(), s2.end());
    string b = get(s2);
    if (b.size() > a.size()) {
      swap(a, b);
    }
    cout << ansl;
    cout << a;
    reverse(ansl.begin(), ansl.end());
    cout << ansl << endl;
  }
}