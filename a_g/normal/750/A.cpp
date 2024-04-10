#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  int time = 240-k;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (5*i <= time) {
      ans++;
      time -= 5*i;
    }
  }
  cout << ans << '\n';
}