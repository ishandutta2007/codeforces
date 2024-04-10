#include<bits/stdc++.h>
using namespace std;
const int N=2009,M=1e5+3;
int d[N],u[M],v[M],p[N][1009];
void dfs(int x,int y,int z){if(x)swap(p[x][y],p[x][z]),dfs(p[x][z],z,y);}
int main(){
	int a,b,m,i,j,s=0,x,y;
	scanf("%d%d%d",&a,&b,&m);
	for(i=1;i<=m;++i)scanf("%d%d",u+i,v+i),++d[u[i]],++d[v[i]+=a];
	for(i=1;i<=a+b;++i)s=max(s,d[i]);
	for(i=1,printf("%d\n",s);i<=m;++i){
		for(j=1;j<=s;++j)if(!p[u[i]][j]){x=j;break;}
		for(j=1;j<=s;++j)if(!p[v[i]][j]){y=j;break;}
		p[u[i]][x]=v[i],p[v[i]][y]=u[i];
		if(x!=y)dfs(v[i],x,y);
	}
	for(i=1;i<=m;++i)for(j=1;j<=s;++j)if(p[u[i]][j]==v[i]){printf("%d ",j);break;}
	return 0;
}