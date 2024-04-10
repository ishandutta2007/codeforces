#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> tag(n);
    for (int i = 0; i < n; i++) cin >> tag[i];
    vector<ll> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<ll> dp(n);
    for (int j = 0; j < n; j++) {
      for (int i = j-1; i >= 0; i--) {
        if (tag[j] != tag[i]) {
          ll a = dp[i];
          ll b = dp[j];
          dp[j] = max(b, a+abs(s[i]-s[j]));
          dp[i] = max(a, b+abs(s[i]-s[j]));
        }
      }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
  }
}