#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
vector<int> x[N];
vector<int> y[N];
int cnt[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int c;
      cin >> c;
      x[c].push_back(i);
      y[c].push_back(j);
      cnt[c]++;
    }
  }
  long long ans = 0;
  for (int c = 1; c < N; c++) {
    sort(x[c].begin(), x[c].end());
    sort(y[c].begin(), y[c].end());
    int m = -cnt[c]+1;
    for (int i = 0; i < cnt[c]; i++) {
      ans += 1LL * m * (x[c][i] + y[c][i]);
      m += 2;
    }
  }
  cout << ans << '\n';
}