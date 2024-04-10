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
const int MAXN = 1000010, LOG=20;

int n, m, k, u, v, x, y, s, t, a, b, ans;
int dist[MAXN];
int deg[MAXN];
bool mark[MAXN];
vector<int> G[MAXN];
deque<int> Q;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	while (m--){
		cin>>u>>v;
		deg[u]++;
		G[v].pb(u);
	}
	cin>>s>>t;
	
	memset(dist, 63, sizeof(dist));
	dist[t]=0;
	Q.pb(t);
	while (Q.size()){
		int v=Q.front();
		Q.pop_front();
		if (mark[v]) continue ;
		mark[v]=1;
		for (int x:G[v]){
			deg[x]--;
			if (deg[x]){
				if (dist[v]+1<dist[x]){
					dist[x]=dist[v]+1;
					Q.pb(x);
				}
			}
			else{
				if (dist[v]<dist[x]){
					dist[x]=dist[v];
					Q.push_front(x);
				}
			}
		}
	}
	
	if (dist[s]>inf) dist[s]=-1;
	cout<<dist[s]<<'\n';
	
	return 0;
}