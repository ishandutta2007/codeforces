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
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 200010, LOG=20;

int n, m, k, u, v, x, y, a, b, ans;
int P[MAXN], s, t;
int dist[MAXN];
int dp[MAXN][2];
vector<int> G[MAXN], GR[MAXN];
queue<int> Q;

void add_edge(int u, int v){
	G[u].pb(v);
	GR[v].pb(u);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	while (m--){
		cin>>u>>v;
		add_edge(u, v);
	}
	cin>>k;
	for (int i=1; i<=k; i++) cin>>P[i];
	
	memset(dist, 31, sizeof(dist));
	dist[P[k]]=0;
	Q.push(P[k]);
	while (Q.size()){
		int v=Q.front();
		Q.pop();
		for (int u:GR[v]) if (dist[v]+1<dist[u]){
			dist[u]=dist[v]+1;
			Q.push(u);
		}
	}
	
	for (int i=1; i<k; i++) if (dist[P[i]]!=dist[P[i+1]]+1) ans++;
	cout<<ans<<' ';
	ans=0;
	for (int i=1; i<k; i++){
		for (int v:G[P[i]]) if (dist[P[i]]==dist[v]+1 && v!=P[i+1]){
			ans++;
			break ;
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}