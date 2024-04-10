#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
  int x = max(a.first, a.second);
  int y = max(b.first, b.second);
  if (x != y) return x < y;
  return a < b;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, d;
  cin >> n >> d;
  vector<pair<int, int>> z(n);
  for (int i = 0; i < n; i++) {
    cin >> z[i].first >> z[i].second;
  }
  sort(z.begin(), z.end(), cmp);
  int ans = 0;
  for (pair<int, int>& a: z) {
    if (a.first >= d) {
      ans++;
      d = max(d, a.second);
    }
  }
  cout << ans << '\n';
}