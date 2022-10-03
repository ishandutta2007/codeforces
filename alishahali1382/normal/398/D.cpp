#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 50010, SQ=550;

int n, m, q, u, v, x, y, t, a, b;
int on[MAXN];
int ans[MAXN];
unordered_set<int> adj[MAXN];
char typ;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>q;
	for (cin>>x; x; x--) cin>>y, on[y]=1;
	while (m--){
		cin>>u>>v;
		if (adj[u].size()>adj[v].size()) swap(u, v);
		adj[u].insert(v);
		ans[v]+=on[u];
	}
	while (q--){
		cin>>typ>>u;
		if (typ=='O'){
			on[u]=1;
			for (int v:adj[u]) ans[v]++;
			continue ;
		}
		if (typ=='F'){
			on[u]=0;
			for (int v:adj[u]) ans[v]--;
			continue ;
		}
		if (typ=='A'){
			cin>>v;
			if (adj[u].size()>adj[v].size()) swap(u, v);
			adj[u].insert(v);
			ans[v]+=on[u];
			continue ;
		}
		if (typ=='D'){
			cin>>v;
			if (!adj[u].count(v)) swap(u, v);
			adj[u].erase(v);
			ans[v]-=on[u];
			continue ;
		}
		int res=ans[u];
		for (int v:adj[u]) res+=on[v];
		cout<<res<<'\n';
	}
	
	return 0;
}