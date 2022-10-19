#include<bits/stdc++.h>
#define ll long long
#define N 500015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int t,n,m,p[N],q[N],cur,bel[N],tot,rt[N];
set<int> e[N],s[N];
void solve(int u){
	int v = 1;
	e[u].insert(n+1);
	for(auto vv:e[u]){
		if(v == u) v++;
		if(v == vv) v++;
		else break;
	}
	// printf("find: %d %d\n",u,v);
	if(!bel[v]){
		bel[u] = bel[v] = ++tot; rt[tot] = u;
		s[tot].insert(u); s[tot].insert(v);
	}else{
		if(s[bel[v]].size() == 2 || rt[bel[v]] == v){
			rt[bel[v]] = v; bel[u] = bel[v];
			s[bel[v]].insert(u);
		}else{
			s[bel[v]].erase(v);
			bel[u] = bel[v] = ++tot; rt[tot] = u;
			s[tot].insert(u); s[tot].insert(v);
		}
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		rep(i,1,n) bel[i] = rt[i] = 0; cur = tot = 0;
		rep(i,1,n) e[i].clear(),s[i].clear();
		rep(i,1,m){
			int u,v; scanf("%d%d",&u,&v);
			e[u].insert(v); e[v].insert(u);
		}
		rep(i,1,n){
			if((int)e[i].size() == n-1) p[i] = q[i] = ++cur;
			else{
				if(!bel[i]) solve(i);
			}
		}
		rep(i,1,tot){
			// printf("i: %d rt[i]: %d\n",i,rt[i]);
			p[rt[i]] = ++cur;
			for(auto u:s[i]){
				// printf("%d ",u);
				if(u == rt[i]) continue;
				q[u] = cur,p[u] = ++cur;
			}
			// printf("\n");
			q[rt[i]] = cur;
		}
		rep(i,1,n) printf("%d ",p[i]); printf("\n");
		rep(i,1,n) printf("%d ",q[i]); printf("\n");
	}
	return 0;
}