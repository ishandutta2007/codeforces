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
const int mod = 998244353;
const int MAXN = 150010, SQ=95;

ll n, m, k, u, v, x, y, t, a, b, ans, invn;
ll fen[MAXN];
ll lazy[MAXN];
int stt[MAXN], fnt[MAXN], timer=1;
int sz[MAXN];
vector<int> G[MAXN], big;
vector<pii> child[MAXN];

void upd(int pos, ll val){
	for (; pos<MAXN; pos+=pos&-pos) fen[pos]=(fen[pos]+val)%mod;
}
void Add(int l, int r, ll val){
	upd(l, +val);
	upd(r, -val);
}
ll Get(int pos){
	ll res=0;
	for (; pos; pos-=pos&-pos) res+=fen[pos];
	return res%mod;
}

ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return a*powmod(a*a%mod, b>>1)%mod;
	return powmod(a*a%mod, b>>1);
}

int dfs(int node, int par){
	stt[node]=timer++;
	for (int v:G[node]) if (v!=par){
		sz[node]+=dfs(v, node);
		child[node].pb({fnt[v], v});
	}
	fnt[node]=timer;
	return ++sz[node];
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
	dfs(1, 1);
	for (int i=1; i<=n; i++) if (child[i].size()>SQ) big.pb(i);
	invn=powmod(n, mod-2);
	while (m--){
		cin>>t;
		if (t==1){
			cin>>v>>x;
			Add(1, n+1, x*(sz[v]*invn%mod));
			Add(stt[v], fnt[v], -x*(sz[v]*invn%mod));
			Add(stt[v]+1, fnt[v], x*((n-sz[v]+1)*invn%mod));
			Add(stt[v], stt[v]+1, x);
			if (child[v].size()>SQ) lazy[v]=(lazy[v]+x)%mod;
			else{
				for (pii p:child[v]){
					int u=p.second;
					Add(stt[u], fnt[u], x*((sz[v]-sz[u]-1)*invn%mod));
				}
			}
			continue ;
		}
		cin>>v;
		ans=Get(stt[v]);
		for (int u:big) if (stt[u]<=stt[v] && fnt[v]<=fnt[u] && u!=v){
			int x=lower_bound(all(child[u]), pii(fnt[v], 0))->second;
			ans=(ans+lazy[u]*((sz[u]-sz[x]-1)*invn%mod))%mod;
		}
		if (ans<0) ans+=mod;
		cout<<ans<<'\n';
	}
	
	
	return 0;
}
/*
5 2
1 2
1 3
2 4
2 5
1 1 1
2 2


*/