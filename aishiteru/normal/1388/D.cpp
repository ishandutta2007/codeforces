#include<stdio.h>
#include<queue>
#include<vector>
#define it register int
#define ct const int
#define il inline
using namespace std;
const int N=1000005;
int T,n,d[N],id,o[N],fa[N];
long long a[N],ans;
bool tag[N],inq[N];
vector<int> g[N];
il bool cmp(ct p,ct q){return a[p]>a[q];}
il void add(ct u,ct v){g[u].push_back(v);}
/*il void dfs(ct x){
	for(const int&i : g[x]) dfs(i);
	std::sort(g[x].begin(),g[x].end(),cmp);
	ct sz=g[x].size();
	for(it i=0;i<sz;++i){
		o[++id]=g[x][i],a[x]+=a[g[x][i]],ans+=a[g[x][i]];
		if(g[x][i]<0) break;
	}
	ans+=a[x];
}*/
il void dfs(ct x){
	d[x]=d[fa[x]]+1;
	for(const int &i : g[x]) dfs(i);
}
struct ky{
	int u;
	bool operator < (const ky&p)const{
		return d[u]^d[p.u]?d[u]<d[p.u]:a[u]<a[p.u];
	}
};
priority_queue<ky> q1;
struct kyl{
	int u;
	bool operator < (const kyl&p)const{
		return d[u]^d[p.u]?d[u]>d[p.u]:a[u]<a[p.u];
	}
};
priority_queue<kyl> q2;
int main(){ 
	scanf("%d",&n);it i;
	for(i=1;i<=n;++i) scanf("%lld",&a[i]);
	for(i=1;i<=n;++i) scanf("%d",&fa[i]),fa[i]>0?add(fa[i],i),0:fa[i]=0;
	//for(i=1;i<=n;++i) std::sort(g.begin(),g.end(),cmp);
	for(i=1;i<=n;++i) if(!fa[i]) dfs(i);
	for(i=1;i<=n;++i) if(a[i]>0) q1.push((ky){i}),inq[i]=1;
	register ky top;ans=0;
	//printf("%lld\n",ans);
	while(!q1.empty()){
		top=q1.top(),q1.pop(),ans+=a[top.u],a[fa[top.u]]+=a[top.u],o[++id]=top.u,tag[top.u]=1;
	//	printf("%d\n",top.u);
		if(fa[top.u]&&a[fa[top.u]]>0&&!inq[fa[top.u]]) q1.push((ky){fa[top.u]}),inq[fa[top.u]]=1;
	}
	for(i=1;i<=n;++i) if(!tag[i]) q2.push((kyl){i});
	register kyl top2;
	while(!q2.empty()) top2=q2.top(),q2.pop(),ans+=a[top2.u],o[++id]=top2.u;
	printf("%lld\n",ans);
	for(i=1;i<=n;++i) printf("%d ",o[i]);puts("");
	return 0;
}