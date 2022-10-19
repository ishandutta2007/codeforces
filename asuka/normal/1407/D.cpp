#include<bits/stdc++.h>
#define ll long long
#define N 300015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,a[N],dp[N],up[N],down[N],su,sd;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&n);
 	rep(i,1,n) scanf("%d",&a[i]);
 	memset(dp,0x3f,sizeof dp);
 	dp[1] = 0;
 	up[1] = down[1] = 1;su = sd = 1;
 	rep(i,2,n){
 		dp[i] = min(dp[i-1]+1,dp[i]);
 		while(sd&&a[i]>a[down[sd]])  dp[i] = min(dp[i],dp[down[sd--]]+1);
 		while(su&&a[i]<a[up[su]]) dp[i] = min(dp[i],dp[up[su--]]+1);
 		dp[i] = min({dp[i],dp[down[sd]]+1,dp[up[su]]+1});
 		if(a[down[sd]] == a[i]) sd--;
 		if(a[up[su]] == a[i]) su--;
 		down[++sd] = i;up[++su] = i;
 	}
 	printf("%d\n",dp[n]);
	return 0;
}