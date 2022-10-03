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
const int MAXN = 100010, FEN=MAXN*2;

struct edge{
	ll w, c;
};

struct Fenwick{
	int cnt[FEN];
	ll mul[FEN];
	vector<int> todo;
	Fenwick(){
		for (int i=0; i<FEN; i++) cnt[i]=0, mul[i]=1;	
	}
	void add(int pos, ll val){
		for (pos+=MAXN; pos<FEN; pos+=pos&-pos){
			cnt[pos]++;
			mul[pos]=mul[pos]*val%mod;
			todo.pb(pos);
		}
	}
	pll get(int pos){
		ll c=0, m=1;
		for (pos+=MAXN; pos; pos-=pos&-pos){
			c+=cnt[pos];
			m=m*mul[pos]%mod;
		}
		return {c, m};
	}
	void reset(){
		for (int x:todo) cnt[x]=0, mul[x]=1;
		todo.clear();
	}
} fen1, fen2;

ll n, m, k, u, v, w, c, t, ans=1;
int sz[MAXN];
bool dead[MAXN];
vector<pair<int, edge>> G[MAXN];

ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}

ll inv(ll x){
	return powmod(x, mod-2);
}

int dfs1(int node, int par){
	sz[node]=1;
	for (auto p:G[node]) if (!dead[p.first] && p.first!=par) sz[node]+=dfs1(p.first, node);
	return sz[node];
}

int Centroid(int node, int par, int n){
	for (auto p:G[node]) if (!dead[p.first] && p.first!=par && 2*sz[p.first]>n) return Centroid(p.first, node, n);
	return node;
}

void dfs2(int node, int par, int r, int b, ll val){
	pll p=fen1.get(2*b-r);
	ll tmp=p.second*powmod(val, p.first)%mod;
	ans=ans*tmp%mod;
	
	p=fen2.get(b-2*r-1);
	tmp=p.second*powmod(val, p.first)%mod;
	ans=ans*inv(tmp)%mod;
	
	for (auto p:G[node]) if (p.first!=par && !dead[p.first]){
		int v=p.first, w=p.second.w, c=p.second.c;
		dfs2(v, node, r+(c==0), b+(c==1), val*w%mod);
	}
}

void dfs3(int node, int par, int r, int b, ll val){
	fen1.add(r-2*b, val);
	fen2.add(2*r-b, val);
	for (auto p:G[node]) if (p.first!=par && !dead[p.first]){
		int v=p.first, w=p.second.w, c=p.second.c;
		dfs3(v, node, r+(c==0), b+(c==1), val*w%mod);
	}
}

void Decompose(int root){
	root=Centroid(root, root, dfs1(root, root));
	dead[root]=1;
	fen1.add(0, 1);
	fen2.add(0, 1);
	for (auto p:G[root]) if (!dead[p.first]){
		int v=p.first, w=p.second.w, c=p.second.c;
		dfs2(v, root, (c==0), (c==1), w);
		dfs3(v, root, (c==0), (c==1), w);
	}
	fen1.reset();
	fen2.reset();
	for (auto p:G[root]) if (!dead[p.first]) Decompose(p.first);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<n; i++){
		cin>>u>>v>>w>>c;
		G[u].pb({v, {w, c}});
		G[v].pb({u, {w, c}});
	}
	Decompose(1);
	cout<<ans<<'\n';
	
	return 0;
}