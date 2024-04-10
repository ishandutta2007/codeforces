#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<string, int> cnt;
  int ans = 0;
  while (n--) {
    string row;
    cin >> row;
    ans = max(ans, ++cnt[row]);
  }
  cout << ans << '\n';
}