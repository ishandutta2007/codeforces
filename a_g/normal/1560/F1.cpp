#include <bits/stdc++.h>
using namespace std;

const string INF = "9999999999999999999999";

string mingtr(string& s, set<char>& digits) {
  char m = *digits.begin();
  if (s.size() == 0) return s;
  for (char c: digits) {
    if (c == s[0]) {
      string t = s.substr(1);
      string v = mingtr(t, digits);
      if (v != INF) {
        v.insert(v.begin(), c);
        return v;
      }
    }
    else if (c > s[0]) {
      string ans;
      ans.push_back(c);
      while (ans.size() < s.size()) ans.push_back(m);
      return ans;
    }
  }
  return INF;
}

void solve() {
  string n;
  int k;
  cin >> n >> k;
  if (k == 10) {
    cout << n << endl;
    return;
  }
  int m = n.size();

  string pref;
  set<char> digits;
  for (int i = 0; i < m; i++) {
    if (digits.size() == k-1) break;
    digits.insert(n[i]);
    pref.push_back(n[i]);
  }
  string suff = n.substr(pref.size());

  string best = INF;
  for (char c = '0'; c <= '9'; c++) {
    if (!digits.count(c)) {
      digits.insert(c);
      best = min(best, mingtr(suff, digits));
      digits.erase(c);
    }
  }
  cout << pref << best << endl;
}

int main () {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}