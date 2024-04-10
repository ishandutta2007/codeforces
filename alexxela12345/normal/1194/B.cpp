#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a, int b) {
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector<int> cnt1(n), cnt2(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == '.') {
        cnt1[i]++;
        cnt2[j]++;
      }
    }
  }
  int min_ans = INT_MAX;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int ans = cnt1[i] + cnt2[j];
      if (arr[i][j] == '.')
        ans--;
      min_ans = min(min_ans, ans);
    }
  }
  cout << min_ans <<  endl; }

signed main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}