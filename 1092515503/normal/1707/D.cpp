/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int f[2010][2010],g[2010][2010],G[2010][2010],C[2010][2010],n,mod,d[2010];
//f:the number of ways of having a single node at time i.
//g:the number of ways of having (some none-empty things) at time i.
//h:the ... of having some empty things at time i.
vector<int>v[2010];
int pre[2010][2010],suf[2010][2010];
void dfs(int x){
	for(int i=0;i<n;i++)f[x][i]=1;
	for(int _=0;_<v[x].size();_++){
		int y=v[x][_];
		v[y].erase(find(v[y].begin(),v[y].end(),x));
		dfs(y);
		for(int i=0;i<n;i++)f[x][i]=1ll*f[x][i]*G[y][i]%mod;
	}
	for(int i=0;i<n;i++)pre[0][i]=suf[v[x].size()][i]=1;
	for(int _=0;_<v[x].size();_++){
		int y=v[x][_];
		for(int i=0;i<n;i++)pre[_+1][i]=1ll*pre[_][i]*G[y][i]%mod;
	}
	for(int _=(int)v[x].size()-1;_>=0;_--){
		int y=v[x][_];
		for(int i=0;i<n;i++)suf[_][i]=1ll*suf[_+1][i]*G[y][i]%mod;
	}
	for(int _=0;_<v[x].size();_++){
		int y=v[x][_];
		static int h[2010];
		for(int i=0;i<n;i++)h[i]=1ll*pre[_][i]*suf[_+1][i]%mod;
		for(int i=1;i<n;i++)(h[i]+=h[i-1])%=mod;
		for(int i=1;i<n;i++)(g[x][i]+=1ll*h[i-1]*g[y][i]%mod)%=mod;
	}
	for(int i=0;i<n;i++)(g[x][i]+=f[x][i])%=mod;
	G[x][0]=g[x][0];for(int i=1;i<n;i++)G[x][i]=(G[x][i-1]+g[x][i])%mod;
	// printf("%d:\n",x);
	// for(int i=0;i<n;i++)printf("%d ",f[x][i]);puts("");
	// for(int i=0;i<n;i++)printf("%d ",g[x][i]);puts("");
	// for(int i=0;i<n;i++)printf("%d ",G[x][i]);puts("");
}
int main(){
	scanf("%d%d",&n,&mod);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	for(int i=0;i<=n;i++)C[i][0]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	dfs(1);
	for(int i=1;i<n;i++){
		d[i]=f[1][i-1];
		for(int j=1;j<i;j++)(d[i]+=mod-1ll*d[j]*C[i][j]%mod)%=mod;
	}
	for(int i=1;i<n;i++)printf("%d ",d[i]);puts("");
	return 0;
}