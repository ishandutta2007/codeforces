#include<bits/stdc++.h>
#define ll long long
#define N 200015
#define inf 0x3f3f3f3f
#define pb push_back
using namespace std;
int n,m,p,fa[N],cnt[N],dep[N];
vector<int> e[N];
bool gkp[N];
void dfs(int u){
	gkp[u] = 1;
	for(int i = 0;i < e[u].size();++i){
		int v = e[u][i];
		if(gkp[v]){
			if(dep[v]-dep[u]>=p-1){
				vector<int> c;
				while(u != v){
					c.pb(v);
					v = fa[v];
				}
				c.pb(u);
				puts("2");
				cout << c.size() << endl;
				for(int j = 0;j < c.size();++j) cout << c[j] << ' ';
				exit(0);
			}
		}else{
			dep[v] = dep[u]+1;
			fa[v] = u;
			dfs(v);
		}
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= m;++i){
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
		e[v].pb(u);
	}
	while(p*p<n) p++;
	dfs(1);
	for(int i = 1;i <= n;++i)
		cnt[dep[i]%(p-1)]++;
	int pos = max_element(cnt,cnt+p-1)-cnt;
	vector<int> ans;
	for(int i = 1;i <= n;++i)
		if(dep[i]%(p-1)==pos) ans.pb(i);
	ans.resize(p);
	puts("1");
	for(int i = 0;i < ans.size();++i) cout << ans[i] << ' '; 
	return 0;
}