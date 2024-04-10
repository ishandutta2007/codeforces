#include<bits/stdc++.h>
using namespace std;
const int N=5009,M=1e5+9;
int f[19][M],lg[M],ne[N],he[N],m;
double g[N][N];
map<int,int>mp;
struct Q{
	int l,r,m;
	double p;
	inline bool operator<(Q a)const{return l<a.l||(l==a.l&&r>a.r);}
}q[N];
int qry(int l,int r){int i=lg[r-l+1];return max(f[i][l],f[i][r-(1<<i)+1]);}
void dfs(int x){
	int i,j;
	for(i=he[x];i;i=ne[i])dfs(i);
	double u,v=1;
	for(i=he[x];i;i=ne[i])v*=g[i][min(q[x].m-q[i].m,m)];
	g[x][0]=(1-q[x].p)*v;
	for(j=1;j<=m;++j){
		u=v=1;
		for(i=he[x];i;i=ne[i])u*=g[i][min(q[x].m+j-q[i].m-1,m)],v*=g[i][min(q[x].m+j-q[i].m,m)];
		g[x][j]=q[x].p*u+(1-q[x].p)*v;
	}
}
int main(){
	int n,i,j,k,l;
	scanf("%d%d",&n,&m),lg[0]=-1;
	for(i=1;i<=n;++i)scanf("%d",f[0]+i),lg[i]=lg[i>>1]+1;
	for(i=0;i<18;++i)
	for(j=1,k=(1<<i)+1,l=n-(1<<i+1)+2;j<l;++j,++k)
	f[i+1][j]=max(f[i][j],f[i][k]);
	for(i=1;i<=m;++i)scanf("%d%d%lf",&q[i].l,&q[i].r,&q[i].p),q[i].m=qry(q[i].l,q[i].r);
	q[++m]={0,n,qry(1,n),0},sort(q+1,q+m+1),mp[n]=1;
	for(i=2;i<=m;++i){
		j=mp.lower_bound(q[i].r)->second;
		ne[i]=he[j],he[j]=i;
		mp[q[i].r]=i;
	}
	dfs(1);
	double ans=g[1][0]*q[1].m;
	for(i=1;i<=m;++i)ans+=(q[1].m+i)*(g[1][i]-g[1][i-1]);
	printf("%.8lf",ans);
	return 0;
}