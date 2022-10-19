#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 5005;
ll a[maxn];
int p[maxn];
int dp[maxn];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[n+1-i];
    while (!(a[n+1-i]&1)) {
      a[n+1-i] /= 2;
      p[n+1-i]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = 1;
    for (int j = 1; j < i; j++) {
      // dp[i] = maximum number of kept elements among a[1], ..., a[i]
      // if the last element that was kept was a[i]
      if (a[i] % a[j] == 0 &&
          (i - j > p[j] || (p[i] == p[j] - i + j))
         ) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  cout << n-*max_element(dp+1, dp+n+1) << endl;
}