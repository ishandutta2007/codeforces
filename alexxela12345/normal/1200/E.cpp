#include <bits/stdc++.h>
using namespace std;

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

int calc(string &s1, string &s2) {
  int lenn = min(s1.size(), s2.size());
  string s = s2 + "#" + s1.substr(s1.size() - lenn, s1.size());
  int n = s.size();
  vector<int> pref(n);
  for (int i = 1; i < n; i++) {
    int k = pref[i - 1];
    while (k > 0 && s[i] != s[k]) {
      k = pref[k - 1];
    }
    if (s[i] == s[k]) {
      k++;
    }
    pref[i] = k;
  }
  return pref.back();
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
  string ans;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int lenl = calc(ans, s);
    for (int i = lenl; i < (int) s.size(); i++) {
      ans.push_back(s[i]);
    }
  }
  cout << ans << endl;
  return 0;
}