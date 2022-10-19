#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
const int mod=1e9+7;
int n,cnt[10010000],pri[10010000],mu[10010000],g[10010000],bin[500100],res;
void sieve(){
	mu[1]=1;
	for(int i=2;i<=N;i++){
		if(!pri[i])pri[++pri[0]]=i,mu[i]=-1;
		for(int j=1;j<=pri[0]&&i*pri[j]<=N;j++){
			pri[i*pri[j]]=true;
			if(!(i%pri[j]))break;
			mu[i*pri[j]]=-mu[i];
		}
	}
}
int main(){
	scanf("%d",&n),sieve();
	bin[0]=1;for(int i=1;i<=n;i++)bin[i]=(bin[i-1]<<1)%mod;
	for(int i=1,x;i<=n;i++)scanf("%d",&x),cnt[x]++;
	for(int i=1;i<=pri[0];i++)for(int j=N/pri[i];j;j--)cnt[j]+=cnt[pri[i]*j];
//	for(int i=1;i<=5;i++)printf("%d ",cnt[i]);puts("");
//	for(int i=1;i<=5;i++)printf("%d ",mu[i]);puts("");
	for(int i=1;i<=N;i++)g[i]=bin[cnt[i]]-1,cnt[i]=(mod+cnt[i]*mu[i])%mod;
//	for(int i=1;i<=5;i++)printf("%d ",cnt[i]);puts("");
	for(int i=1;i<=pri[0];i++)for(int j=1;j*pri[i]<=N;j++)(cnt[pri[i]*j]+=cnt[j])%=mod;
//	for(int i=1;i<=5;i++)printf("%d ",cnt[i]);puts("");
	for(int i=1;i<=pri[0];i++)for(int j=1;j*pri[i]<=N;j++)(g[j]+=mod-g[pri[i]*j])%=mod;
//	for(int i=1;i<=5;i++)printf("%d ",g[i]);puts("");
	for(int i=2;i<=N;i++)res=(1ll*cnt[i]*g[i]+res)%mod; 
	printf("%d\n",res);
	return 0;
}