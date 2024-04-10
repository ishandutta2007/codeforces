#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")

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
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans=inf;
ll A[MAXN];
int dist[MAXN];
int par[MAXN];
vector<int> G[MAXN];
queue<int> q;

void bfs(int root){
	memset(dist, 63, sizeof(dist));
	memset(par, 0, sizeof(par));
	dist[root]=0;
	q.push(root);
	while (q.size()){
		int v=q.front();
		q.pop();
		for (int x:G[v]){
			if (dist[v]+1<dist[x]){
				dist[x]=dist[v]+1;
				par[x]=v;
				q.push(x);
			}
			else if (x!=par[v]) ans=min(ans, dist[v]+dist[x]+1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	sort(A+1, A+n+1);
	reverse(A+1, A+n+1);
	while (A[n]==0) n--;
	if (n>=200) kill(3) 
	for (int i=1; i<=n; i++) for (int j=i+1; j<=n; j++) if (A[i]&A[j]){
		G[i].pb(j);
		G[j].pb(i);
	}
	
	for (int i=1; i<=n; i++) bfs(i);
	if (ans==inf) ans=-1;
	cout<<ans<<'\n';
	
	return 0;
}