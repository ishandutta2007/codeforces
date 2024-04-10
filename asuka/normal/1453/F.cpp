#include<bits/stdc++.h>
#define ll long long
#define N 6005
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
int n,a[N],dp[N][N],T;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
	 	rep(i,1,n) scanf("%d",&a[i]);
	 	rep(i,1,n) rep(j,i,n) dp[i][j] = inf;
	 	rep(i,1,n) dp[1][i] = 0;
	 	rep(i,2,n){
	 		int cnt = 0;
	 		per(j,1,i-1){
	 			if(j+a[j] >= i){
	 				dp[i][j+a[j]] = min(dp[i][j+a[j]],dp[j][i-1]+cnt++);
	 			}
	 		}
	 		rep(j,i+1,n) dp[i][j] = min(dp[i][j],dp[i][j-1]);
	 	}
	 	printf("%d\n",dp[n][n]);
	}
	return 0;
}