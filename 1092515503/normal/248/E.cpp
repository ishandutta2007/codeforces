#include<bits/stdc++.h>
using namespace std;
const int MAXN=500100;
int n,num[100100],q,now[100100];
double f[100100][110],C[500500][10],res;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&num[i]),now[i]=num[i],f[i][num[i]]=1,res+=f[i][0];
	for(int i=0;i<=MAXN;i++)C[i][0]=1;
	for(int i=1;i<=MAXN;i++)for(int j=1;j<=min(i,5);j++)C[i][j]=C[i-1][j-1]+C[i-1][j];
	scanf("%d",&q);
	for(int i=1,u,v,w;i<=q;i++){
		scanf("%d%d%d",&u,&v,&w);
		res-=f[u][0];
		for(int j=0;j<=num[u];j++){
			double ans=0;
			for(int k=j;k<=min(j+w,now[u]);k++)ans+=f[u][k]*C[k][k-j]*C[now[u]-k][w-(k-j)];
			f[u][j]=ans/C[now[u]][w];
		}
		res+=f[u][0],now[u]-=w,now[v]+=w;
		printf("%.9lf\n",res);
	}
	return 0;
}