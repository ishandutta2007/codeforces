#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  int l = 0;
  int r = n-1;
  vector<int> ans;
  while (l < r) {
    while (l <= n-1 && s[l] == ')') l++;
    while (r >= 0 && s[r] == '(') r--;
    if (l > r) break;
    ans.push_back(l+1);
    ans.push_back(r+1);
    l++;
    r--;
  }
  if (!ans.size()) {
    cout << "0\n";
    return 0;
  }
  sort(ans.begin(), ans.end());
  cout << "1\n";
  cout << ans.size() << '\n';
  for (int x: ans) cout << x << ' ';
  cout << '\n';
}