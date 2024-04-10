#include<bits/stdc++.h>
#define ll long long
#define N 505
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
int n,mod;
int C[N][N],pd[N],dp[N][N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&mod);
	pd[0] = 1;
	rep(i,1,n) pd[i] = (pd[i-1]*2)%mod;
	rep(i,0,n) C[i][0] = 1;
	rep(i,1,n) rep(j,1,i) C[i][j] = (C[i-1][j]+C[i-1][j-1])%mod;
	dp[0][0] = 1;
	rep(i,0,n-1) rep(j,0,i){
		rep(k,1,n){
			if(i+k > n) continue;
			(dp[i+k+1][j+k] += ((1ll*dp[i][j]*C[j+k][k])%mod*1ll*pd[k-1])%mod) %= mod;
		}
	}
	int res = 0;
	rep(i,1,n) (res += dp[n+1][i]) %= mod;
	printf("%d\n",res);
	return 0;
}