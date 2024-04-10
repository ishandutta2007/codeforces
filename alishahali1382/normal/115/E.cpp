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
const int MAXN = 200010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN];
ll seg[MAXN<<2];
ll lazy[MAXN<<2];
vector<pii> vec[MAXN];

void add_lazy(int id, ll lz){
	seg[id]+=lz;
	lazy[id]+=lz;
}

void shift(int id){
	if (!lazy[id]) return ;
	add_lazy(id<<1, lazy[id]);
	add_lazy(id<<1 | 1, lazy[id]);
	lazy[id]=0;
}

void update(int id, int tl, int tr, int l, int r, ll val){
	//if (id==1) cerr<<"update "<<l<<' '<<r<<' '<<val<<endl;
	if (tr<=l || r<=tl) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, val);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, l, r, val);
	update(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=max(seg[id<<1], seg[id<<1 | 1]);
}

ll get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return -INF;
	if (l<=tl && tr<=r) return seg[id];
	shift(id);
	int mid=(tl+tr)>>1;
	return max(get(id<<1, tl, mid, l, r), get(id<<1 | 1, mid, tr, l, r));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=m; i++){
		cin>>a>>b>>x;
		vec[b].pb({a, x});
	}
	for (int i=1; i<=n; i++){
		update(1, 0, n+1, i, i+1, max(get(1, 0, n+1, 0, i), 0ll));
		update(1, 0, n+1, 0, i, -A[i]);
		for (pii p:vec[i]) update(1, 0, n+1, 0, p.first, p.second);
		//for (int j=0; j<=n; j++) cerr<<get(1, 0, n+1, j, j+1)<<" \n"[j==n];
		//cerr<<endl;
	}
	cout<<get(1, 0, n+1, 0, n+1)<<'\n';
	
	return 0;
}
/*
7 4
3 2 3 2 1 2 3
1 2 5
2 3 5
3 5 3
7 7 5

*/