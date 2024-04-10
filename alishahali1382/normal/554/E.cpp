#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define pb push_back
const int mod = 1000000007;
const int MAXN = 100010;

int par[MAXN];
int get(int x){
	if (par[x]==x) return x;
	return par[x]=get(par[x]);
}
void join(int x, int y){
	par[get(x)]=get(y);
}

int n, m, k, u, v, x, y, t, a, b, c, ans=1, cnt;
pii E[MAXN];
int color[MAXN];
vector<int> G[MAXN];

bool dfs(int node, int c){
	color[node]=c;
	for (int i:G[node]){
		if (color[i]==c) return 0;
		if (!color[i] && !dfs(i, 3-c)) return 0; 
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) par[i]=i;
	while (m--){
		cin>>u>>v>>c;
		if (c==1) join(u, v);
		else E[t++]={u, v};
	}
	for (int i=0; i<t; i++){
		int u=get(E[i].first), v=get(E[i].second);
		G[u].pb(v);
		G[v].pb(u);
	}
	for (int i=1; i<=n; i++){
		if (par[i]!=i || color[i]) continue ;
		cnt++;
		if (!dfs(i, 1)) return cout<<0<<endl, 0;
	}
	while (--cnt) ans=(2*ans)%mod;
	cout<<ans<<endl;
	
	return 0;
}