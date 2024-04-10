#include<bits/stdc++.h>
using namespace std;
const int N=609;
int d[N][N],x[N],y[N];
bool b[N];
basic_string<int>f[N],g[N];
int main(){
	int n,m,i,j,k,s,t;
	scanf("%d%d",&n,&m),memset(d,9,sizeof d);
	for(i=1;i<=n;++i)d[i][i]=0;
	for(i=1;i<=m;++i)scanf("%d%d",x+i,y+i),d[x[i]][y[i]]=d[y[i]][x[i]]=1;
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)for(k=1;k<j;++k)d[j][k]=d[k][j]=min(d[j][k],d[j][i]+d[i][k]);
	for(i=1;i<=n;++i,puts("")){
		for(j=1;j<=n;++j)f[j]=g[j]={};
		for(j=1;j<=m;++j)if(d[i][x[j]]+1==d[i][y[j]])f[y[j]]+=x[j];else if(d[i][y[j]]+1==d[i][x[j]])f[x[j]]+=y[j];
		for(j=1;j<=n;++j){
			for(memset(b,0,n+1),k=j;b[k]=1,k!=i;k=f[k][0])if(f[k].size()>1){printf("0 ");goto gg;}
			for(k=s=1;k<=n;++k)if(!b[k]){
				t=0;
				for(int l:f[k])if(d[j][l]+1==d[j][k])++t;
				s=s*1ll*t%998244353;
			}
			printf("%d ",s);
			gg:;
		}
	}
	return 0;
}