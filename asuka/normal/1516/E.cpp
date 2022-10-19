#include<bits/stdc++.h>
#define int long long
#define N 405
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
using namespace std;
const int mod = 1e9+7;
int f[N][N],g[N][N],c[N][N],ans[N],inv[N];
int C(int n,int i){
	if(i > n) return 0;
	int res = 1;
	rep(j,n-i+1,n) res = (res*j)%mod;
	rep(j,1,i) res = (res*inv[j])%mod;
	return res;
}
int n,k;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld%lld",&n,&k);
	inv[1]=1;
    rep(i,2,k<<1) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	rep(i,0,k<<1) c[i][0] = 1;
	rep(i,0,k<<1) f[i][0] = 1;
	rep(i,1,k<<1) rep(j,1,i) f[i][j] = (f[i-1][j]+(i-1)*f[i-1][j-1])%mod;
	rep(i,1,k<<1) rep(j,1,i) c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod;
	rep(i,1,k<<1) rep(j,1,i){
		rep(l,0,i) g[i][j] = (g[i][j] + (((l&1?mod-1:1)*c[i][l])%mod)*f[i-l][j])%mod;
	}
	ans[0] = 1;
	rep(j,1,k){
		rep(i,1,k<<1) ans[j] = (ans[j] + C(n,i)*g[i][j])%mod;
	}
	per(j,0,k) for(int i = j+2;i <= k;i += 2) ans[i] = (ans[i] + ans[j])%mod;
	rep(j,1,k) printf("%lld ",ans[j]);
	return 0;
}