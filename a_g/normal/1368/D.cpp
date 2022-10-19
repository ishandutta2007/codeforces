#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> c(20);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    for (int j = 0; j < 20; j++) {
      if ((a>>j)&1) c[j]++;
    }
  }
  vector<int> a(n);
  for (int j = 0; j < 20; j++) {
    for (int i = 0; i < c[j]; i++) {
      a[i] += 1<<j;
    }
  }
  long long ans = 0;
  for (int x: a) {
    ans += 1LL * x * x;
  }
  cout << ans << '\n';
}