#include <bits/stdc++.h>
using namespace std;

string normalize(string s) {
  int cnt_b = 0;
  string t = "";
  for (char c : s) {
    if (c == 'B') {
      ++cnt_b;
    } else {
      t.push_back(c);
    }
  }
  cnt_b %= 2;
  if (cnt_b == 1) {
    t = "B" + t;
  }
  return t;
}

string clean(string s) {
  string t = "";
  for (char c : s) {
    if (!t.empty() && t.back() == c) {
      t.pop_back();
    } else {
      t.push_back(c);
    }
  }
  return t;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    string u, v;
    cin >> u >> v;
    u = normalize(u);
    v = normalize(v);
    u = clean(u);
    v = clean(v);
    cout << (u == v ? "YES\n" : "NO\n");
  }

  return 0;
}