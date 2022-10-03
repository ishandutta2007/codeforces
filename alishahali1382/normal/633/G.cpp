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
const int MAXN = 100010, LIM=1000;

int n, M, q, k, u, v, x, y, t, a, b, ans;
bitset<LIM> sieve;
int A[MAXN];
int st[MAXN], fn[MAXN], timer;
vector<int> G[MAXN];

void dfs(int node, int par){
	st[node]=++timer;
	for (int v:G[node]) if (v!=par) dfs(v, node);
	fn[node]=timer;
}
struct node{
	bitset<LIM> B;
	int lazy=0;
	node(){}
	node operator +(node x){
		x.lazy=0;
		(x.B)|=B;
		return x;
	}
} seg[MAXN<<2];

void add_lazy(node &x, int val){
	x.B=(x.B<<val)|(x.B>>(M-val));
	x.lazy=(x.lazy+val)%M;
}

void shift(int id){
	if (!seg[id].lazy) return ;
	//debug(id)
	//debug2("FUCK THIS SHIT", seg[id].lazy)
	add_lazy(seg[id<<1], seg[id].lazy);
	add_lazy(seg[id<<1 | 1], seg[id].lazy);
	seg[id].lazy=0;
}

void update(int id, int tl, int tr, int l, int r, int val){
	if (r<tl || tr<l) return ;
	if (l<=tl && tr<=r){
		add_lazy(seg[id], val);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, l, r, val);
	update(id<<1 | 1, mid+1, tr, l, r, val);
	seg[id]=seg[id<<1] + seg[id<<1 | 1];
}

node get(int id, int tl, int tr, int l, int r){
	//cerr<<"get "<<tl<<' '<<tr<<"  "<<l<<' '<<r<<'\n';
	if (r<tl || tr<l) return node();
	if (l<=tl && tr<=r) return seg[id];
	shift(id);
	int mid=(tl+tr)>>1;
	return get(id<<1, tl, mid, l, r) + get(id<<1 | 1, mid+1, tr, l, r);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=0; i<MAXN*4; i++) seg[i].B.set(0);
	sieve.set(0);
	sieve.set(1);
	for (int i=2; i<LIM; i++) if (!sieve[i]){
		for (int j=i*i; j<LIM; j+=i) sieve.set(j);
	}
	sieve=~sieve;
	//debug(sieve)
	
	cin>>n>>M;
	for (int i=LIM-1; i>=M; i--) sieve[i]=0;
	for (int i=1; i<=n; i++) cin>>A[i], A[i]%=M;
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1, 1);
	for (int i=1; i<=n; i++) update(1, 1, n, st[i], st[i], A[i]);
	
	cin>>q;
	while (q--){
		cin>>t>>x;
		if (t==2) cout<<(get(1, 1, n, st[x], fn[x]).B&sieve).count()<<'\n';
		else{
			cin>>y;
			update(1, 1, n, st[x], fn[x], y%M);
		}
	}
	
	
	return 0;
}
/*
8 20
3 7 9 8 4 11 7 3
1 2
1 3
3 4
4 5
4 6
4 7
5 8
1
2 1

*/