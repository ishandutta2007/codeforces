#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool can0 (const string &s) {
  int bal = 0;
  for (char c : s) {
    if (c == '(') bal++;
    else bal--;

    if (bal < 0) return false;
  }
  return true;
}

bool can1 (string s, pair<int, int> &ans) {
  int n = s.size();

  pair<int, int> mxpre = make_pair(0, 0);
  int bal = 0;
  for (int i = 0; i < n; i++) {
    char c = s[i];
    if (c == '(') bal++;
    else bal--;

    mxpre = max(mxpre, make_pair(bal, i + 1));
    
    if (bal < 0) break;
  }

  pair<int, int> mxpost = make_pair(0, n);
  bal = 0;
  for (int i = n - 1; i >= 0; i--) {
    char c = s[i];
    if (c == ')') bal++;
    else bal--;

    mxpost = max(mxpost, make_pair(bal, i));

    if (bal < 0) break;
  }

  int l = mxpre.second, r = mxpost.second;
  reverse(s.begin() + l, s.begin() + r);

  if (can0(s)) {
    ans = make_pair(l, r - 1);
    return true;
  }

  return false;
}

vector<pair<int, int>> solve2 (string s) {
  int n = s.size();

  pair<int, int> mxbal = make_pair(0, 0);
  int bal = 0;
  for (int i = 0; i < n; i++) {
    char c = s[i];
    if (c == '(') bal++;
    else bal--;

    mxbal = max(mxbal, make_pair(bal, i + 1));
  }

  int m = mxbal.second;
  return vector<pair<int, int>> {{0, m - 1}, {m, n - 1}};
}

void solve () {
  int n;
  cin >> n;

  string s;
  cin >> s;

  if (can0(s)) {
    cout << 0 << '\n';
    return;
  }

  pair<int, int> ans1;
  if (can1(s, ans1)) {
    cout << 1 << '\n';
    cout << 1 + ans1.first << " " << 1 + ans1.second << '\n';
    return;
  }

  auto ans = solve2(s);
  cout << ans.size() << '\n';
  for (auto pr : ans) {
    cout << 1 + pr.first << " " << 1 + pr.second << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}