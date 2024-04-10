#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,lim,tp;
ll f[18][1<<18],g[19][1<<18];
char s[20][20];
void ORFMT(ll*a,int tp){for(int i=0;i<n;i++)for(int j=0;j<lim;j++)if(j&(1<<i))a[j]+=tp*a[j^(1<<i)];}
void ANDFMT(ll*a,int tp){}
ll h[19][1<<18],res[1<<18];
map<vector<int>,vector<int> >mp;
vector<int>v;
void dfs(int lef,int bon){
	if(!lef){
		ll ret=0;for(int i=0;i<lim;i++)if(__builtin_popcount((lim-1)^i)&1)ret-=h[tp][i];else ret+=h[tp][i];
		for(auto i:mp[v])res[i]+=ret;return;
	}
	for(int i=1;i<=min(lef,bon);i++){
		v.push_back(i);
		for(int j=0;j<lim;j++)h[tp+1][j]=h[tp][j]*g[i][j];
		tp++,dfs(lef-i,i),tp--;
		v.pop_back();
	}
}
int main(){
	scanf("%d",&n),lim=1<<n;
	for(int i=0;i<n;i++)scanf("%s",s[i]);
	for(int i=0;i<n;i++)f[i][1<<i]=1;
	for(int j=0;j<lim;j++)for(int i=0;i<n;i++)if(j&(1<<i))for(int k=0;k<n;k++)if(!(j&(1<<k))&&s[i][k]=='1')f[k][j|(1<<k)]+=f[i][j];
//	for(int i=0;i<n;i++){for(int j=0;j<lim;j++)printf("%d ",f[i][j]);puts("");} 
	for(int i=0;i<n;i++)for(int j=0;j<lim;j++)g[__builtin_popcount(j)][j]+=f[i][j];
//	for(int i=0;i<lim;i++)printf("%d ",g[__builtin_popcount(i)][i]);puts("");
	for(int i=0;i<=n;i++)ORFMT(g[i],1);
	for(int i=0;i<(1<<(n-1));i++){
		vector<int>v;
		int len=1;
		for(int j=0;j<n-1;j++)if(i&(1<<j))len++;else v.push_back(len),len=1;
		v.push_back(len);
//		printf("%d:",i);for(auto j:v)printf("%d ",j);puts("");
		sort(v.rbegin(),v.rend()),mp[v].push_back(i); 
	}
	h[0][0]=1,ORFMT(h[0],1),dfs(n,n);
//	for(int i=0;i<(1<<(n-1));i++)printf("%d ",res[i]);puts("");
	for(int i=0;i<n-1;i++)for(int j=0;j<(1<<(n-1));j++)if(j&(1<<i))res[j^(1<<i)]-=res[j];
	for(int i=0;i<(1<<(n-1));i++)printf("%lld ",res[i]);
	return 0;
}