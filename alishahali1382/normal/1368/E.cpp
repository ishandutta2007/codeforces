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

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=200010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int deg[MAXN];
int ted[MAXN];
vector<int> G[MAXN], vec[7], out;

void Solve(){
	cin>>n>>m;
	for (int i=1; i<=n; i++) G[i].clear(), deg[i]=0, ted[i]=0;
	out.clear();
	k=0;
	while (m--){
		cin>>u>>v;
		G[u].pb(v);
	}
	for (int i=1; i<=n; i++){
		if (!ted[i]){
			for (int v:G[i]){
				deg[v]++;
				for (int u:G[v]) ted[u]++;
			}
		}
		else{
			out.pb(i);
			k++;
			for (int v:G[i]) ted[v]-=deg[i];
		}
	}
	cout<<k<<'\n';
	for (int v:out) cout<<v<<' ';cout<<'\n';
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