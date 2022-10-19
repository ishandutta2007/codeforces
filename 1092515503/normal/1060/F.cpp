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
double C[60][60],fac[60],f[60][60],g[60],h[60];
int n,sz[60];
vector<int>v[60];
void dfs(int x,int fa){
	f[x][0]=1,sz[x]=0;
	for(auto y:v[x])if(y!=fa){
		dfs(y,x);
		for(int i=0;i<=sz[y]+1;i++)
			for(int j=1;j<=sz[y]+1;j++)
				if(j<=i)g[i]+=0.5*f[y][j-1];
				else g[i]+=f[y][i];
		// printf("(%d-%d)\n",x,y);
		// for(int i=0;i<=sz[y]+1;i++)printf("%lf ",g[i]);puts("");
		for(int i=0;i<=sz[x];i++)for(int j=0;j<=sz[y]+1;j++)
			h[i+j]+=C[i+j][j]*C[sz[x]-i+sz[y]+1-j][sz[x]-i]*f[x][i]*g[j];
		sz[x]+=sz[y]+1;
		for(int i=0;i<=sz[x];i++)f[x][i]=h[i],h[i]=g[i]=0;
		// for(int i=0;i<=sz[x];i++)printf("%lf ",f[x][i]);puts("");
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	for(int i=0;i<=n;i++)C[i][0]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)C[i][j]=C[i-1][j-1]+C[i-1][j];
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i;
	for(int i=1;i<=n;i++)dfs(i,0),printf("%lf\n",f[i][n-1]/fac[n-1]);
	return 0;
}