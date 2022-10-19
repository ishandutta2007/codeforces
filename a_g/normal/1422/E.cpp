#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+2;
int len[maxn];
string answers[maxn];

string convert(string& t) {
  int n = t.size();
  if (n > 10) {
    string ans = "";
    for (int i = 1; i <= 5; i++) ans.push_back(t[n-i]);
    ans += "...";
    for (int i = 1; i >= 0; i--) ans.push_back(t[i]);
    return ans;
  }
  else {
    string copy = t;
    reverse(copy.begin(), copy.end());
    return copy;
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  string t, u;
  bool valid = 1;
  for (int i = n-1; i >= 0; i--) {
    char c = s[i];
    if (valid && t.size() && c == t.back() && (u.size() == 1 || u[u.size()-2] < c)) {
      t.pop_back();
      valid = 0;
      if (t.empty() || u.back() != t.back()) u.pop_back();
    }
    else {
      t.push_back(c);
      if (!u.size() || u.back() != c) u.push_back(c);
      valid = 1;
    }
    len[i+1] = t.size();
    answers[i+1] = convert(t);
  }
  for (int i = 1; i <= n; i++) {
    cout << len[i] << " " << answers[i] << '\n';
  }
}