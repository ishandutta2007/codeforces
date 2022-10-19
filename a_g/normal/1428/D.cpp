#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int& x: a) cin >> x;
  vector<pair<int, int>> pts;

  bool ok = 1;
  int h = n;
  vector<int> stk, stk2;
  for (int i = n-1; i >= 0; i--) {
    if (a[i] == 0) continue;
    if (a[i] == 1) {
      stk.emplace_back(i);
      b[i] = h;
      pts.emplace_back(h--, i+1);
      continue;
    }
    if (a[i] == 2) {
      if (!stk.size()) {
        ok = 0;
        break;
      }
      int j = stk.back();
      stk.pop_back();
      pts.emplace_back(b[j], i+1);
      stk2.emplace_back(i);
      continue;
    }
    int j = -1;
    if (stk2.size()) {
      j = stk2.back();
      stk2.pop_back();
    }
    else if (stk.size()) {
      j = stk.back();
      stk.pop_back();
    }
    if (j == -1) {
      ok = 0;
      break;
    }
    stk2.emplace_back(i);
    pts.emplace_back(h, i+1);
    pts.emplace_back(h--, j+1);
  }
  if (!ok) {
    cout << "-1\n";
    return 0;
  }
  cout << pts.size() << '\n';
  for (pair<int, int>& p: pts) {
    cout << p.first << ' ' << p.second << '\n';
  }
}