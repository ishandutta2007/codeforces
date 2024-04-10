#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
  int n;
  cin >> n;
  vector<int>T(n), dp(n+1);
  rep(i, n) cin >> T[i];
  dp[0]=1;
  rep(i, n) {
    if(dp[i] && i+T[i]<n) dp[i+T[i]+1]=1;
    if(T[i]<=i && dp[i-T[i]]) dp[i+1]=1;
  }
  cout << (dp[n]?"YES":"NO") << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}