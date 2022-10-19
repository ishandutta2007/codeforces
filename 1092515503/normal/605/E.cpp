#include<bits/stdc++.h>
using namespace std;
double f[1010],p[1010];
int n;
double g[1010][1010];
bool vis[1010];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%lf",&g[i][j]),g[i][j]/=100;
	for(int i=1;i<=n;i++)f[i]=p[i]=1;
	f[n]=p[n]=0;
	for(int t=1;t<=n;t++){
		int x=-1;double mn=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=n;i++)if(!vis[i]&&mn>f[i]/(1-p[i]))x=i,mn=f[i]/(1-p[i]);
		vis[x]=true;
		for(int y=1;y<=n;y++)if(!vis[y])f[y]+=mn*g[y][x]*p[y],p[y]*=1-g[y][x];
	}
	printf("%lf\n",f[1]/(1-p[1]));
	return 0;
}