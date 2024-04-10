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
const int mod=1e9+7;
int n,m,f[100100][210],g[210],sz[100100],fac[210],res[210],S[210][210],ans;
vector<int>v[100100];
void dfs(int x,int fa){
	f[x][0]=2;//choose or not.
	for(auto y:v[x])if(y!=fa){
		dfs(y,x),sz[y]=min(sz[y]+1,m);
		for(int i=1;i<=sz[y];i++)g[i]=(f[y][i]+f[y][i-1])%mod;
		for(int i=1;i<=sz[y];i++)f[y][i]=g[i],g[i]=0;
		for(int i=0;i<=sz[x];i++)for(int j=0;j<=sz[y]&&i+j<=m;j++)
			g[i+j]=(1ll*f[x][i]*f[y][j]+g[i+j])%mod;
		sz[x]=min(sz[x]+sz[y],m);
		for(int i=0;i<=sz[x];i++)(f[x][i]+=g[i])%=mod,g[i]=0;
	}
	(f[x][0]+=mod-1)%=mod;
	for(int i=0;i<=sz[x];i++)(res[i]+=f[x][i])%=mod;
	for(auto y:v[x])if(y!=fa)for(int i=0;i<=sz[y];i++)(res[i]+=mod-f[y][i])%=mod;//elimilate states from solely one son.
	// printf("%d:\n",x);for(int i=0;i<=m;i++)printf("%d ",f[x][i]);puts("");
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	fac[0]=1;for(int i=1;i<=m;i++)fac[i]=1ll*fac[i-1]*i%mod;
	S[0][0]=1;
	for(int i=1;i<=m;i++)for(int j=1;j<=i;j++)S[i][j]=(1ll*j*S[i-1][j]+S[i-1][j-1])%mod;
	dfs(1,0);
	for(int i=0;i<=m;i++)ans=(1ll*S[m][i]*fac[i]%mod*res[i]+ans)%mod;
	printf("%d\n",ans);
	return 0;
}