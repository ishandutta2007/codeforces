# include <bits/stdc++.h>

using namespace std;

const int xn = 1e3+10;

int n, k, ans, a[6][xn] ,t[6][xn] ,dp[xn];
 
bool check (int x ,int y){
  for (int i=0; i<k; i++)
    if (t[i][x] >= t[i][y]) return false;
  return true;
} 
 
int main (){
  ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
  cin >> n >> k ;
  for (int i=0; i<k; i++)
    for (int j=0; j<n; j++)
      cin >> a[i][j] ,t[i][a[i][j]] = j;
  for (int i=0; i<n; i++) dp[i] = 1;
  for (int i=0; i<n; i++)
    for (int j=0; j<i; j++)
      if (check(a[0][j] ,a[0][i])) dp[i] = max(dp[i] ,dp[j]+1);
  //ans = 0;
  for (int i=0; i<n; i++)
    ans = max(ans ,dp[i]);
  cout << ans << endl ; 
}