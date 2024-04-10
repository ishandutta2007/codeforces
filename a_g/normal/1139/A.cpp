#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if ((s[i]-'1')&1) {
      ans += i+1;
    }
  }
  cout << ans << '\n';
}