#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
const int N=1000005,inf=2e9;
int T,n,fa[N],s[N];
long long ans=0;
vector<int> g[N];
il void ckMin(it&p,ct q){p=(p<q?p:q);}
il void dfs(ct x){for(const int &j : g[x]) ckMin(s[x],s[j]),dfs(j);}
int main(){
	scanf("%d",&n);it i;
	for(i=2;i<=n;++i) scanf("%d",&fa[i]),g[fa[i]].push_back(i);
	for(i=1;i<=n;++i) scanf("%d",&s[i]),~s[i]?0:s[i]=inf;
	dfs(1);
	for(i=1;i<=n;++i) if(s[i]<s[fa[i]]) return puts("-1"),0;
	for(i=1;i<=n;++i) s[i]<inf?ans+=s[i]-s[fa[i]]:0;
	printf("%lld",ans);
	return 0;
}