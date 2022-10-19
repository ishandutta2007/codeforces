#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+6;
int seen[N];
int dp[N]; // gcd of all numbers in a which are divisible by k

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    seen[a] = 1;
  }

  int ans = -n;
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      if (seen[j]) dp[i] = __gcd(dp[i], j);
    }
    if (dp[i] == i) ans++;
  }
  cout << ans << '\n';
}