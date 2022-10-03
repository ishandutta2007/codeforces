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

const int MAXN = 100010;

ll n, m, k, u, v, x, y, t, a, b, ans=1, mod;
bool mark[MAXN];
vector<int> G[MAXN];

ll dfs(int node){
	mark[node]=1;
	ll res=1;
	for (int i:G[node]) if (!mark[i]) res+=dfs(i);
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>mod;
	while (m--){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for (int i=1; i<=n; i++) if (!mark[i]){
		t++;
		ans=ans*dfs(i)%mod;
	}
	if (t==1) kill(1%mod)
	for (int i=0; i<t-2; i++) ans=ans*n%mod;
	cout<<ans<<'\n';
	
	return 0;
}