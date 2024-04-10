#include<stdio.h>
#include<map>
#include<vector>
#include<algorithm>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef double db;
#define rdb register db
#define cdb const db
const int N=1000005;
int n,m,Q,u[N],v[N],tot[N],T;
bool vs[N];
std::map<int,std::map<int,int>> f,s;
std::vector<int> vec;
struct ky{
	db x,y;
	ky(){}
	ky(cdb a,cdb b){x=a,y=b;}
	ky operator + (const ky&p)const{return ky(x+p.x,y+p.y);}
	ky operator - (const ky&p)const{return ky(x-p.x,y-p.y);}
	bool operator < (const ky&p)const{return x!=p.x?x<p.x:y<p.y;}
}a[N];
#define cky const ky
db cross(cky a,cky b){return a.x*b.y-a.y*b.x;}
db crs(cky a,cky b,cky c){return cross(b-a,c-a);}
db ang(cky a,cky b){return atan2(b.y-a.y,b.x-a.x);}
struct kyl{
	int u;db x;
	bool operator < (const kyl&p)const{return x<p.x;}
};
std::vector<kyl> g[N];
il void add(ct u,ct v){g[u].push_back((kyl){v,ang(a[v],a[u])}),f[u][v]=0,g[v].push_back((kyl){u,ang(a[u],a[v])}),f[v][u]=0;}
il int calc(ct u,ct v,ct x){return (ang(a[v],a[u])<ang(a[x],a[u])?0:tot[u])+s[u][x]-s[u][v]-f[u][x];}
int dfs(ct x,ct y){
	vs[x]=1;it sum=1;
	for(const auto &i : g[x]) 
		if(!vs[i.u]) sum+=dfs(i.u,x);
	if(y) f[y][x]+=sum,f[x][y]-=sum;
	return sum;
}
int main(){ 
	scanf("%d%d",&n,&m);T=n+1,a[T]=(ky){-1e10,0};it i,pos=1,x;
	for(i=1;i<=m;++i) scanf("%d%d",&u[i],&v[i]);
	for(i=1;i<=n;++i) scanf("%lf%lf",&a[i].x,&a[i].y),a[i]<a[pos]?pos=i:0;
	for(i=1;i<=m;++i) add(u[i],v[i]);add(T,pos);
	dfs(T,0);
	for(i=1;i<=T;++i) std::sort(g[i].begin(),g[i].end());
	for(i=1;i<=T;++i){
		s[i][i]=0,pos=i;
		for(const auto &j : g[i]) tot[i]+=f[i][j.u],s[i][j.u]=s[i][pos]+f[i][j.u],pos=j.u;
	}
	scanf("%d",&Q);
	while(Q--){
		scanf("%d",&pos),vec.clear();
		while(pos--) scanf("%d",&x),vec.push_back(x);
		ct sz=vec.size();rdb sum=0;it ans=sz;
		for(i=0;i<sz;++i) sum+=crs(a[0],a[vec[i?i-1:sz-1]],a[vec[i]]);
		if(sum>0) std::reverse(vec.begin(),vec.end());
		for(i=0;i<sz;++i) ans+=calc(vec[i],vec[i?i-1:sz-1],vec[(i+1>=sz?i+1-sz:i+1)]);
		printf("%d\n",ans);
	}
	return 0;
}