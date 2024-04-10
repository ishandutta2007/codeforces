#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
typedef long long ll;
int n,m,K;
ll d[60];
void ins(){
	ll x;scanf("%lld",&x);
	for(int i=m-1;i>=0;i--)if((x>>i)&1){
		if(!d[i]){d[i]=x,K++;return;}
		x^=d[i];
	}
}
void func(){
	static int o[60];
	for(int i=0;i<m;i++)o[i]=i;
	sort(o,o+m,[](int x,int y){return d[x]<d[y];});
	static ll p[60];
	for(int i=0;i<m;i++)p[i]=d[o[i]];
	for(int i=0;i<m;i++){
		d[i]=0;
		for(int j=0;j<m;j++)if((p[i]>>o[j])&1)d[i]|=1ll<<j;
	}
}
int res[60];
int f[2][60][1<<17];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)ins();
	func();
//	for(int i=0;i<m;i++,puts(""))for(int j=0;j<m;j++)printf("%d",(d[i]>>j)&1);
	for(int i=m-1;i>=0;i--)for(int j=i-1;j>=0;j--)if((d[i]>>j)&1)d[i]^=d[j];
//	printf("%d\n",K);
	if(K<=(m>>1))for(int i=0;i<(1<<K);i++){
		ll x=0;
		for(int j=0;j<K;j++)if(i&(1<<j))x^=d[m-j-1];
		res[__builtin_popcountll(x)]++;
	}else{
		int lim=1<<(m-K);
		f[0][0][0]=1;
		for(int i=0;i<K;i++){
			memset(f[!(i&1)],0,sizeof(f[!(i&1)]));
			for(int j=0;j<=i;j++)for(int k=0;k<lim;k++)
				(f[!(i&1)][j][k]+=f[i&1][j][k])%=mod,
				(f[!(i&1)][j+1][(k^d[m-i-1])&(lim-1)]+=f[i&1][j][k])%=mod;
		}
		for(int j=0;j<=K;j++)for(int k=0;k<lim;k++)(res[j+__builtin_popcount(k)]+=f[K&1][j][k])%=mod;
	}
	int bin=ksm(2,n-K);
	for(int i=0;i<=m;i++)printf("%d ",1ll*res[i]*bin%mod);
	return 0;
}
/*
4 35
0 0 0 32247662483
*/