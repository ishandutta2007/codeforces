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
const int MAXN = 210, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
bool mark[MAXN*MAXN];
vector<pii> G[MAXN];

void euler(int node){
	while (G[node].size()){
		int v=G[node].back().first, i=G[node].back().second;
		G[node].pop_back();
		if (mark[i]) continue ;
		mark[i]=1;
		euler(v);
		if (i<=m) cout<<v<<' '<<node<<'\n';
	}
}

void solve(){
	cin>>n>>m;
	ans=0;
	for (int i=0; i<=n; i++) G[i].clear();
	for (int i=1; i<=m; i++){
		cin>>u>>v;
		G[u].pb({v, i});
		G[v].pb({u, i});
		mark[i]=0;
	}
	int last=0, tmp=m;
	for (int i=1; i<=n; i++){
		if (G[i].size()%2==0) ans++;
		else{
			if (last==0) last=i;
			else{
				mark[++tmp]=0;
				G[last].pb({i, tmp});
				G[i].pb({last, tmp});
				last=0;
			}
		}
	}
	cout<<ans<<'\n';
	for (int i=1; i<=n; i++) euler(i);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) solve();
	
	return 0;
}
/*
1
12 8
10 2
9 2
6 9
10 6
8 2
4 10
11 2
4 11

*/