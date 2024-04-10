#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
const int mod=1e9+7;
int n,fac[200100],inv[200100],f[2010];
pair<int,int>p[2010];
int ksm(int x,int y){
	int z=1;
	for(;y;y>>=1,x=(1ll*x*x)%mod)if(y&1)z=(1ll*z*x)%mod;
	return z;
}
int C(int x,int y){
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main(){
	fac[0]=1;
	for(int i=1;i<=N;i++)fac[i]=(1ll*fac[i-1]*i)%mod;
	inv[N]=ksm(fac[N],mod-2);
	for(int i=N-1;i>=0;i--)inv[i]=(1ll*inv[i+1]*(i+1))%mod;
	scanf("%d%d%d",&p[1].first,&p[1].second,&n),n++,p[1].first--,p[1].second--;
	for(int i=2;i<=n;i++)scanf("%d%d",&p[i].first,&p[i].second),p[i].first--,p[i].second--;
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++){
		f[i]=C(p[i].first+p[i].second,p[i].first);
		for(int j=1;j<i;j++)if(p[j].first<=p[i].first&&p[j].second<=p[i].second)f[i]=(f[i]-1ll*f[j]*C(p[i].first-p[j].first+p[i].second-p[j].second,p[i].first-p[j].first)%mod+mod)%mod;
	}
	printf("%d\n",f[n]);
	return 0;
}