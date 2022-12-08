#include <bits/stdc++.h>

#define fst first
#define snd second

using namespace std;
typedef long long ll;

const int N=2e5+5;
ll ans[N];
int n, A[N];
map<int,ll> cnt[N];
vector<int> g[N];

void dfs(int u, int p=-1){
	cnt[u][A[u]]=1;
	ans[A[u]]++;
	for(int v:g[u])if(v!=p){
		dfs(v,u);
		for(auto p:cnt[v])
			for(auto p2:cnt[u])
				ans[__gcd(p2.fst,p.fst)]+=p2.snd*p.snd;
		for(auto p:cnt[v])cnt[u][__gcd(p.fst,A[u])]+=p.snd;
		cnt[v].clear();
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> n;
	for(int x=0; x<n; x++)
	    cin>>A[x];
	for(int x=0; x<n-1; x++){
		int u,v; cin >> u >> v; u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0,0);
	for(int x=1; x<N; x++)
	    if(ans[x])
	       cout<<x<<" "<<ans[x]<<"\n";
}