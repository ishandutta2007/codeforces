#include<bits/stdc++.h>
#define int long long
#define N 200015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
using namespace std;
int n,a[N],dp[N][3][2][2];
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld",&n);
 	rep(i,1,n) scanf("%lld",&a[i]);
 	memset(dp,-0x3f,sizeof dp);
 	if(n == 1) {printf("%lld\n",a[1]); return 0;}
 	dp[1][2][0][0] = -a[1]; dp[1][1][1][0] = a[1];
 	rep(i,1,n-1){
 		rep(j,0,2){
 			dp[i+1][(j+1)%3][1][1] = max(dp[i+1][(j+1)%3][1][1],max({dp[i][j][1][1],dp[i][j][1][0],dp[i][j][0][1]})+a[i+1]);
 			dp[i+1][(j+1)%3][1][0] = max(dp[i][j][0][0]+a[i+1],dp[i+1][(j+1)%3][1][0]);
 			dp[i+1][(j+2)%3][0][1] = max(dp[i+1][(j+2)%3][0][1],max({dp[i][j][0][0],dp[i][j][0][1],dp[i][j][1][1]})-a[i+1]);
 			dp[i+1][(j+2)%3][0][0] = max(dp[i][j][1][0]-a[i+1],dp[i+1][(j+2)%3][0][0]);
 		}
 	}
 	printf("%lld\n",max(dp[n][1][0][1],dp[n][1][1][1]));
	return 0;
}