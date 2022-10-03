#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
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
const int MAXN = 2000010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans, mode;
pii E[MAXN];
bool mark[MAXN*2];
bool tmp[MAXN];
bool mark2[MAXN];
vector<pii> G[MAXN];
vector<pii> out;

void euler(int node){
	while (G[node].size()){
		pii p=G[node].back();
		G[node].pop_back();
		if (mark[p.second]) continue ;
		mark[p.second]=1;
		euler(p.first);
		mode^=1;
		if (mode){
			//debug2(node, p.first)
			if (node && p.first) out.pb({node, p.first}), mark2[p.second]=1;
			else tmp[node+p.first]=1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=m; i++){
		cin>>u>>v;
		E[i]={u, v};
		G[u].pb({v, i});
		G[v].pb({u, i});
	}
	for (int i=1; i<=n; i++) if (G[i].size()&1){
		G[0].pb({i, ++m});
		G[i].pb({0, m});
	}
	for (int i=0; i<=n; i++) euler(i), mode=0;
	for (int i=1; i<=m; i++) if ((tmp[E[i].first] || tmp[E[i].second]) && !mark2[i]){
		out.pb(E[i]);
		tmp[E[i].first]=0;
		tmp[E[i].second]=0;
	}
	cout<<out.size()<<'\n';
	for (pii p:out) cout<<p.first<<' '<<p.second<<'\n';
	
	return 0;
}