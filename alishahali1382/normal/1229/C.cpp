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
const int MAXN = 100010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll deg[MAXN];
vector<int> vec[MAXN];

void add(int v, int u){
	ans-=vec[v].size()*(deg[v]-vec[v].size());
	vec[v].pb(u);
	ans+=vec[v].size()*(deg[v]-vec[v].size());
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	while (m--){
		cin>>u>>v;
		if (u>v) swap(u, v);
		vec[u].pb(v);
		deg[v]++;
		deg[u]++;
	}/*
	for (int i=1; i<=n; i++){
		cerr<<i<<" : ";for (int v:vec[i]) cerr<<v<<' ';cerr<<'\n';
	}*/
	for (int i=1; i<=n; i++) ans+=(deg[i]-vec[i].size())*vec[i].size();
	int q;cin>>q;
	cout<<ans<<'\n';
	while (q--){
		cin>>v;
		ans-=(deg[v]-vec[v].size())*vec[v].size();
		for (int u:vec[v]) add(u, v);
		vec[v].clear();
		vec[v].shrink_to_fit();
		cout<<ans<<'\n';
	}
	
	return 0;
}