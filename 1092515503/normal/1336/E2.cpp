#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
typedef long long ll;
int n,m,K,bin;
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
int f[60],g[60],C[60][60];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<=m;i++)C[i][0]=1;
	for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	for(int i=1;i<=n;i++)ins();
	func();
//	for(int i=0;i<m;i++,puts(""))for(int j=0;j<m;j++)printf("%d",(d[i]>>j)&1);
	for(int i=m-1;i>=0;i--)for(int j=i-1;j>=0;j--)if((d[i]>>j)&1)d[i]^=d[j];
//	printf("%d\n",K);
	if(K<=(m>>1)){
		ll x=0;f[0]++;
		for(int i=1;i<(1<<K);i++){
			for(int j=0;j<K;j++){
				x^=d[m-j-1];
				if(i&(1<<j))break;
			}
			f[__builtin_popcountll(x)]++;
		}
		bin=ksm(2,n-K);
	}else{
		for(int i=K;i<m;i++){
			for(int j=0;j<K;j++)d[m-i-1]|=((d[m-j-1]>>(m-i-1))&1)<<(m-j-1);
			d[m-i-1]|=1ll<<(m-i-1);
		}
//		for(int i=0;i<m;i++,puts(""))for(int j=0;j<m;j++)printf("%d",(d[i]>>j)&1);
		ll x=0;g[0]++;
		for(int i=1;i<(1<<m-K);i++){
			for(int j=0;j<m-K;j++){
				x^=d[j];
				if(i&(1<<j))break;
			}
			g[__builtin_popcountll(x)]++;
		}
//		for(int i=0;i<=m;i++)printf("%d ",g[i]);puts("");
		for(int i=0;i<=m;i++)for(int j=0;j<=m;j++){
			int coe=0;
			for(int k=0;k<=i;k++){
				int eoc=1ll*C[j][k]*C[m-j][i-k]%mod;
				if(k&1)(coe+=mod-eoc)%=mod;
				else(coe+=eoc)%=mod;
			}
			(f[i]+=1ll*coe*g[j]%mod)%=mod;
		}
		bin=ksm(2,(n+mod-1-m)%(mod-1));
//		for(int i=0;i<m;i++,puts(""))for(int j=0;j<m;j++)printf("%d",(d[i]>>j)&1);
	}
	for(int i=0;i<=m;i++)printf("%d ",1ll*f[i]*bin%mod);
	return 0;
}
/*
4 35
0 0 0 32247662483
*/