#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
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
const int MAXN = 200010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
piii E[MAXN];
bool mark[MAXN];
map<ll, ll> dist;
vector<ll> vec;
vector<pii> G[MAXN];
priority_queue<pll, vector<pll>, greater<pll>> pq;

void djkasra(int root){
	dist.clear();
	pq.push({dist[root]=0, root});
	while (pq.size()){
		int v=pq.top().second;
		pq.pop();
		if (mark[v]) continue ;
		mark[v]=1;
		for (auto p:G[v]) if (!dist.count(p.first) || dist[p.first]>dist[v]+p.second) pq.push({dist[p.first]=dist[v]+p.second, p.first});
	}
	for (auto p:dist){
		//cerr<<root<<' '<<p.first<<" -> "<<p.second<<endl;
		if (root<p.first) vec.pb(p.second);
		mark[p.first]=0; 
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k;
	for (int i=1; i<=m; i++) cin>>E[i].second.first>>E[i].second.second>>E[i].first;
	sort(E+1, E+m+1);
	m=min(m, k);
	for (int i=1; i<=m; i++){
		int u=E[i].second.first, v=E[i].second.second, w=E[i].first;
		G[u].pb({v, w});
		G[v].pb({u, w});
	}
	for (int i=1; i<=n; i++) djkasra(i);
	sort(all(vec));
	cout<<vec[k-1]<<'\n';
	
	return 0;
}