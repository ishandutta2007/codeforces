#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
const int N=1000005;
struct ky{
	int v,w;
	bool operator < (const ky&p)const{return w<p.w;}
};
vector<ky> g[N];
vector<int> vec[N];
int n,m,k,u,v,x;
unsigned long long pw[N],s[20][20],sum,now;
ll ans;
il void dfs(ct x){
	if(x>k) return ans+=(now==sum),void();
	for(it i=0;i<x;++i) now+=s[x][i],dfs(x+1),now-=s[x][i];
}
int main(){ 
	scanf("%d%d%d",&n,&m,&k);it i;
	for(pw[0]=i=1;i<=n;++i) pw[i]=pw[i-1]*137,sum+=pw[i];
	for(i=1;i<=m;++i) scanf("%d%d%d",&u,&v,&x),g[u].push_back((ky){v,x});
	for(i=1;i<=n;++i) std::sort(g[i].begin(),g[i].end()),vec[g[i].size()].push_back(i);
	for(i=1;i<=k;++i)
		for(it j=0;j<i;++j)
			for(const int &x : vec[i]) 
				s[i][j]+=pw[g[x][j].v];
	dfs(1),printf("%lld",ans);
	return 0;
}