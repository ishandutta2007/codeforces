#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e5+2;
vector<vector<int>> divisors(maxn);

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  for (int i = 1; i < maxn; i++) {
    for (int j = 2*i; j < maxn; j+=i) {
      divisors[j].push_back(i);
    }
  }
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<int> dp(n, 1);
    int ans = 1;
    for (int i = 1; i < n; i++) {
      for (int j: divisors[i+1]) {
        if (s[j-1] < s[i]) {
          dp[i] = max(dp[i], dp[j-1]+1);
        }
      }
      ans = max(ans, dp[i]);
    }
    cout << ans << endl;
  }
}