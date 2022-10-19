#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,dsu[1510],vsz[1510],esz[1510],cnt,f[3010][1510],lim[1510];
struct edge{
	int x,y,z;
	friend bool operator<(const edge&u,const edge&v){return u.z<v.z;}
}e[2000000];
int find(int x){return dsu[x]==x?x:dsu[x]=find(dsu[x]);}
list<int>v[1510],u[3010];
void ae(int x,int y){
	x=find(x),y=find(y);
	if(x==y){
		esz[x]++;
		if(esz[x]==vsz[x]*(vsz[x]-1)/2)u[++cnt].swap(v[x]),v[x].push_back(cnt);
		return;
	}
	if(vsz[x]<vsz[y])swap(x,y);
	dsu[y]=x,vsz[x]+=vsz[y],esz[x]+=esz[y]+1,v[x].splice(v[x].begin(),v[y]);
	if(esz[x]==vsz[x]*(vsz[x]-1)/2)u[++cnt].swap(v[x]),v[x].push_back(cnt);
}
void dfs(int x){
	if(x<=n){f[x][lim[x]=1]=1;return;}
	f[x][0]=1;
	for(auto y:u[x]){
		dfs(y);
//		for(int i=0;i<=lim[x];i++)printf("%d ",f[x][i]);puts("");
//		for(int i=0;i<=lim[y];i++)printf("%d ",f[y][i]);puts("");
		for(int i=lim[x];i>=0;f[x][i--]=0)for(int j=lim[y];j>=0;j--)(f[x][i+j]+=1ll*f[x][i]*f[y][j]%mod)%=mod;
		lim[x]+=lim[y];
	}
	f[x][0]=0,(++f[x][1])%=mod;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)for(int j=1,x;j<=n;j++){
		scanf("%d",&x);
		if(i<j)m++,e[m].x=i,e[m].y=j,e[m].z=x;
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++)dsu[i]=i,vsz[i]=1,v[i].push_back(i);
	cnt=n;
//	for(int i=1;i<=m;i++)printf("(%d,%d:%d)",e[i].x,e[i].y,e[i].z);
	for(int i=1;i<=m;i++)ae(e[i].x,e[i].y);
//	for(int i=1;i<=n;i++)printf("%d %d %d\n",dsu[i],vsz[i],esz[i]);
	dfs(cnt);
	for(int i=1;i<=n;i++)printf("%d ",f[cnt][i]);
	return 0;
}