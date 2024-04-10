#include<bits/stdc++.h>
#define ll long long
#define N
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
#define SZ(x) ((int)x.size())
using namespace std;
int dp[35][35][55];
int f(int n,int m,int k){
	if(~dp[n][m][k]) return dp[n][m][k];
	if(k == 0) return 0;
	if(n*m < k) return inf;
	if(n*m == k) return 0;
	int res = inf;
	rep(i,1,n-1) rep(j,0,k) res = min(res,f(i,m,j)+f(n-i,m,k-j)+m*m);
	rep(i,1,m-1) rep(j,0,k) res = min(res,f(n,i,j)+f(n,m-i,k-j)+n*n);
	return dp[n][m][k] = res;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	memset(dp,-1,sizeof dp);
 	int t,n,m,k;
 	scanf("%d",&t);
 	while(t--){
 		scanf("%d%d%d",&n,&m,&k);
 		printf("%d\n",f(n,m,k));
 	}
	return 0;
}