#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int f[N],sz[N],a[N];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
struct E{
	int x,y,z;
	bool operator<(E a)const{return z>a.z;}
}e[N];
int main(){
	long long ans=0;
	int n,m,i,j,k;
	scanf("%d%d",&n,&m),iota(f+1,f+n+1,1),fill(sz+1,sz+n+1,1);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<=m;++i)scanf("%d%d",&e[i].x,&e[i].y),e[i].z=min(a[e[i].x],a[e[i].y]);
	sort(e+1,e+m+1);
	for(i=1;i<=m;++i){
		j=gf(e[i].x),k=gf(e[i].y);
		if(j!=k)ans+=e[i].z*1ll*sz[j]*sz[k],f[j]=k,sz[k]+=sz[j];
	}
	printf("%.9lf",ans*2.0/n/(n-1));
	return 0;
}