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

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

struct fen{
	ll BIT[MAXN];
	void upd(int i, ll x){ for (; i<MAXN; i+=i&(-i)) BIT[i]+=x;}
	void update(int l, int r, ll x){
		upd(l, x);
		upd(r+1, -x);
	}
	ll get(int i){
		ll res=0;
		for (; i; i-=i&(-i)) res+=BIT[i];
		return res;
	}
} B1, B2;

int n, m, k, u, v, x, t, d, type;
int h[MAXN], st[MAXN], fn[MAXN], timer;
vector<int> G[MAXN];

void dfs(int node){
	st[node]=++timer;
	for (int i:G[node]) if (!st[i]) h[i]=h[node]+1, dfs(i);
	fn[node]=timer;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	h[1]=1;
	dfs(1);
	while (m--){
		cin>>type>>v;
		if (type){
			cout<<B1.get(h[v])+B2.get(st[v])<<'\n';
			continue ;
		}
		cin>>x>>d;
		if (h[v]-d>1) B2.update(st[v]-d, min(fn[v], st[v]+d), x);
		else{
			int dd=d-h[v]+1;
			B1.update(1, dd+1, x);
			int l=st[v]-h[v]+1+dd+1, r=min(fn[v], st[v]+d);
			if (l<=r) B2.update(l, r, x);
		}
	}
	
	
	return 0;
}