#include<bits/stdc++.h>
#define int long long
#define N 1000015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,r1,r2,r3,d,dp[N][2],a[N];
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld%lld%lld%lld%lld",&n,&r1,&r2,&r3,&d);
 	rep(i,1,n) scanf("%lld",&a[i]);
 	dp[1][0] = min(a[1]*r1+r3,2*d+min((a[1]+1)*r1,r2)+min({r1,r2,r3}));
 	dp[1][1] = min((a[1]+1)*r1,r2);
 	//dp[0][0] = dp[0][1] = inf;
 	rep(i,2,n){
 		//cout << i << ": " << endl;
 		int lone = min((a[i]+1)*r1,r2),one = min({r1,r2,r3}),all = a[i]*r1+r3;
 		// if(dp[i-1][0]+min(lone+2*d+one,all) < dp[i-1][1]+min(lone+one,all)+one+2*d){
 		// 	puts("0 0");
 		// }else{puts("0 1");}
 		// if(dp[i-1][0]+lone < dp[i-1][1]+2*d+lone+one){
 		// 	puts("1 0");
 		// }else{puts("1 1");}
 		dp[i][0] = min(dp[i-1][0]+all,dp[i-1][1]+min(lone+one,all)+one+2*d)+d;
 		dp[i][1] = min(dp[i-1][0],dp[i-1][1]+2*d+one)+d+lone;
 	}
 	//cout << (dp[n][0] < dp[n][1]+2*d+min({r1,r2,r3})) << endl;
 	printf("%lld\n",min(dp[n][0],dp[n-1][1]+2*d+(a[n]+1)*r1+r3));
	return 0;
}