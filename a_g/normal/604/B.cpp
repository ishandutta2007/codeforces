#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  int ans = 0;
  if (2*k > n) ans = max(ans, s[n-1]);
  for (int i = 0; i < n-k; i++) {
    ans = max(ans, s[i]+s[2*(n-k)-1-i]);
  }
  cout << ans << endl;
}