#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=200010, K=11;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
bool mark[K][K];
bool bad[K][K][K][K];
int val[K];
vector<pii> G[MAXN], vec[MAXN];

void BT(int deg){
	if (deg==k+1){
		for (int i=1; i<=k; i++) for (int j=1; j<=i; j++)
			if (bad[i][val[i]][j][val[j]]) return ;
//		for (int i=1; i<=k; i++) cerr<<val[i]<<" \n"[i==k];
		ans++;
		return ;
	}
	for (int i=0; i<deg; i++){
		val[deg]=i;
		BT(deg+1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k;
	while (m--){
		cin>>u>>v>>x;
		G[u].pb({x, v});
	}
	for (int v=1; v<=n; v++){
		sort(all(G[v]));
//		cerr<<v<<": ";for (pii p:G[v]) cerr<<p.second<<" ";cerr<<"\n";
		for (int i=0; i<G[v].size(); i++) vec[G[v][i].second].pb({G[v].size(), i});
	}
	for (int v=1; v<=n; v++){
		memset(mark, 0, sizeof(mark));
		for (pii p:vec[v]){
			int x=p.first, y=p.second;
//			if (v==3) debug2(x, y)
			if (mark[x][y]){
				bad[x][y][x][y]=1;
				continue ;
			}
			for (int xx=1; xx<=k; xx++) for (int yy=0; yy<xx; yy++) if (mark[xx][yy]){
				bad[x][y][xx][yy]=1;
				bad[xx][yy][x][y]=1;
			}
			mark[x][y]=1;
		}
	}
	BT(1);
	cout<<ans<<"\n";
	
	return 0;
}