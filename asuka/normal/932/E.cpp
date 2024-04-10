#include<bits/stdc++.h>
#define ll long long
#define N 5005
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
const int mod = 1e9+7;
int n,k,S[N][N],fac[N],inv[N];
int qpow(int a,int b){
	int res = 1;
	while(b){
		if(b&1) res = (ll) res*a%mod;
		a = (ll) a*a%mod;
		b >>= 1;
	}
	return res;
}
void init(){
	S[0][0] = fac[0] = inv[1] = 1;
	rep(i,2,k) inv[i] = (ll) (mod - mod/i) * inv[mod%i] % mod;
	rep(i,1,k) rep(j,1,i) S[i][j] = (S[i-1][j-1] + (ll)j * S[i-1][j])%mod;
	rep(i,1,k) fac[i] = (ll) fac[i-1]*i%mod;
}
int C(int x,int y){
	int res = 1;
	rep(i,x-y+1,x) res = (ll) res*i%mod;
	rep(i,1,y) res = (ll) res*inv[i]%mod;
	return res;
}
int ans;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&k);
	init();
	// rep(i,1,k) printf("%d\n",C[k][i]);
	rep(j,0,min(n,k)){
		// printf("%d %d %d %d\n",S[k][j],fac[j],C(n,j),qpow(2,n-j));
		(ans += (ll)S[k][j] * fac[j] % mod * C(n,j) % mod * qpow(2,n-j) % mod) %= mod;
		// printf("%d\n",ans);
	}
	printf("%d\n",ans);
	return 0;
}