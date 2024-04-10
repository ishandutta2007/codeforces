#include<bits/stdc++.h>
#define ll long long
#define N 200015
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
#define all(x) x.begin(),x.end()
using namespace std;
int T,n,dep[N],Min[N],ans;
VI e[N],tmp[N];
void dfs(int u,int fa){
	//printf("%d\n",u);
	dep[u] = dep[fa]+1;
	tmp[u].clear();
	for(auto v:e[u]){
		if(v == fa) continue;
		dfs(v,u);
		tmp[u].pb(Min[v]);
		//cout <<u <<  " -> "<< v << endl; cout << "sz: " << tmp[u].size() << " Min_v " << Min[v] <<endl;
	}
	sort(all(tmp[u]));
	int sz = tmp[u].size();
	if(sz == 0) Min[u] = dep[u];
	else{ 
		if(u != fa) Min[u] = tmp[u][0];
		if(u != fa && sz > 1) ans = max(ans,- dep[u] + tmp[u][sz-1] + 1);
	}
	//cout << u << " $$$ " << sz << endl;
	if(u == fa && sz > 0) ans = max(ans,- dep[u] + tmp[u][sz-1]);
	if(u == fa && sz > 1) ans = max(ans,- dep[u] + tmp[u][sz-2] + 1);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&T);
 	while(T--){
 		scanf("%d",&n);
 		rep(i,1,n) dep[i] = 0,Min[i] = inf,e[i].clear(); ans = 0;
 		rep(i,2,n){
 			int u,v; scanf("%d%d",&u,&v);
 			e[u].pb(v);
 			e[v].pb(u);
 		}
 		dfs(1,1);
 		printf("%d\n",ans);
 	}
	return 0;
}