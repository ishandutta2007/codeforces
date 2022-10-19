#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
int n,a[139],m;
long long s,k,po[39],b[39];
long long ans;
map<long long ,int> f[39];
inline void dfs1(const int & x,const int &y,const long long &z){
	if(z>k) return; 
	if(x==n/2+1) {f[y][z]++;return;}
	dfs1(x+1,y,z);dfs1(x+1,y,z+a[x]);
	if(a[x]<=18&&y<m) dfs1(x+1,y+1,z+b[x]);
}
inline void dfs2(const int &x,const int &y,const long long &z){
	if(z>k) return; 
	if(x==n+1){
		for(register int i=0;i<=m-y;i++) if(f[i].count(k-z))ans+=f[i][k-z];
		return;
	}
	dfs2(x+1,y,z);dfs2(x+1,y,z+a[x]);
	if(a[x]<=18&&y<m) dfs2(x+1,y+1,z+b[x]);
}
int main(){
	register int i;
//	freopen("1.in","r",stdin);
	po[1]=1;
	for(i=2;i<=19;i++)po[i]=po[i-1]*i;
	scanf("%d%d%lld",&n,&m,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++) b[i]=a[i]>18?0:po[a[i]];
	dfs1(1,0,0);
	dfs2(n/2+1,0,0);
	printf("%lld\n",ans);
}