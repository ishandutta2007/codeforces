#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
const int N=1e6;
int n,pri[N+10],mnp[N+10],f[N+10],fac[N+10],inv[N+10],s[N+10],res;
vector<int>v[N+10];
void sieve(){
	for(int i=2;i<=N;i++){
		if(!pri[i])pri[mnp[i]=++pri[0]]=i;
		for(int j=1;j<=pri[0]&&i*pri[j]<=N;j++){
			pri[i*pri[j]]=true,mnp[i*pri[j]]=j;
			if(!(i%pri[j]))break;
		}
	}
	for(int i=1;i<=pri[0];i++){
		int t=0;
		for(int j=1;j<=N;j*=pri[i])t++;
		v[i].resize(t);
	}
}
int C(int x,int y){return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;}
int main(){
	sieve();
	scanf("%d",&n);
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=ksm(fac[n]);for(int i=n;i;i--)inv[i-1]=1ll*inv[i]*i%mod;
	s[0]=C(n-1,0);for(int i=1;i<n;i++)s[i]=(s[i-1]+C(n-1,i))%mod;
	for(int i=1;i<=n;i++){
		f[i]=(s[n-1]+mod-s[i-1])%mod;
		if(i>=2)f[i]=(f[i]+mod-s[i-2])%mod;
	}
//	for(int i=0;i<n;i++)printf("%d ",s[i]);puts("");
//	for(int i=1;i<=n;i++)printf("%d ",f[i]);puts("");
	for(int i=1;i<=n;i++)(f[i]+=f[i-1])%=mod;
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		vector<int>u;
		while(x!=1)u.push_back(mnp[x]),x/=pri[mnp[x]];
		for(int l=0,r=0;l<u.size();l=r){
			while(r<u.size()&&u[r]==u[l])r++;
//			printf("%d:%d\n",u[l],r-l);
			v[u[l]][r-l]++;
		}
	}
	for(int i=1;i<=pri[0];i++){
		v[i][0]=n;
		for(int j=1;j<v[i].size();j++)v[i][0]-=v[i][j];
		for(int j=1;j<v[i].size();j++)v[i][j]+=v[i][j-1],res=(1ll*j*(f[v[i][j]]+mod-f[v[i][j-1]])+res)%mod;
	}
	printf("%d\n",(mod-res)%mod);
	return 0;
}