#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,S,lim,res,ord[30],nex[30],g[30][30],id[30];
ll f[1<<22];
char s[200100];
int main(){
	scanf("%d%d%d",&S,&n,&m);
	scanf("%s",s);for(int i=0;i<S;i++)s[i]-='A',id[s[i]]=1;
	for(int i=1;i<=n;i++)id[i]+=id[i-1];
	for(int i=0;i<n;i++)id[i]--;
	for(int i=n-1;i>=1;i--)if(id[i]==id[i-1])id[i]++;
	id[0]=0; 
	for(int i=0;i<n;i++)scanf("%lld",&f[1<<id[i]]),ord[i]=i;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&g[id[i]][id[j]]);
	n=id[n],lim=(1<<n);
//	for(int i=0;i<n;i++)printf("%d ",f[1<<id[i]]);puts("");
//	for(int i=0;i<n;i++){for(int j=0;j<n;j++)printf("%d ",g[i][j]);puts("");}
	for(int i=0;i<S;i++)s[i]=id[s[i]];
	for(int i=0;i<n;i++)nex[i]=0x3f3f3f3f;
	for(int i=S-2;i>=0;i--){
		nex[s[i+1]]=i+1;
		sort(ord,ord+n,[](int u,int v){return nex[u]<nex[v];});
		for(int j=0,k=0;j<n&&nex[ord[j]]!=0x3f3f3f3f;j++){
			f[k]+=g[s[i]][ord[j]];
			f[k|(1<<s[i])]-=g[s[i]][ord[j]];
			f[k|(1<<ord[j])]-=g[s[i]][ord[j]];
			f[k|(1<<s[i])|(1<<ord[j])]+=g[s[i]][ord[j]];
			if(ord[j]==s[i])break;
			k|=(1<<ord[j]);
		}
	}
	for(int j=0;j<n;j++)for(int i=1;i<lim;i++)if(i&(1<<j))f[i]+=f[i^(1<<j)];
	for(int i=0;i<lim-1;i++)res+=(f[i]<=m);
	printf("%d\n",res);
	return 0;
}
/*
5 5 13
BADAD
4 1 876 2 978
1 2 876 3 876
2 3 76 4 96
64 876 86 756 876
3 4 65 10 76
65 4876 857 876 76
*/