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
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
bool mark[MAXN];
vector<int> G[MAXN];

int Solve(){
	cin>>n>>m;
	fill(mark, mark+2*n+1, 0);
	for (int i=0; i<2*n; i++) G[i].clear();
	ans=k=0;
	for (int i=1; i<=m; ++i){
		cin>>x>>y;
		if (x==y){
			m--;
			i--;
			continue ;
		}
		G[x].pb(y);
		G[y].pb(x);
	}
	for (int i=1; i<=n; i++) if (G[i].size()==1 && !mark[i]){
		int v=i;
		while (1){
			mark[v]=1;
			if (!mark[G[v][0]]) v=G[v][0];
			else{
				if (G[v].size()==1) break ;
				v=G[v][1];
			}
		}
	}
	for (int i=1; i<=n; i++) if (G[i].size()==2 && !mark[i]){
		ans++;
		int v=i;
		while (1){
			mark[v]=1;
			if (!mark[G[v][0]]) v=G[v][0];
			else{
				if (G[v].size()==1 || mark[G[v][1]]) break ;
				v=G[v][1];
			}
		}
	}
	
	cout<<ans+m<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}
/*
4
3 1
2 3

3 2
2 1
1 2

5 3
2 3
3 1
1 2

5 4
4 5
5 1
2 2
3 3

1
5 3
2 3
3 1
1 2

*/