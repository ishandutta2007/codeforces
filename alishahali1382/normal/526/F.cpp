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
const int MAXN = 300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN];
pii seg[MAXN<<2];
int lazy[MAXN<<2];
vector<piii> mn, mx;

pii combine(pii x, pii y){
	if (x.first<y.first) return x;
	if (x.first>y.first) return y;
	return {x.first, x.second+y.second};
}

pii build(int id, int tl, int tr){
	if (tr-tl==1) return seg[id]={tl, 1};
	int mid=(tl+tr)>>1;
	return seg[id]=combine(build(id<<1, tl, mid), build(id<<1 | 1, mid, tr));
}

void add_lazy(int id, int lz){
	seg[id].first+=lz;
	lazy[id]+=lz;
}

void shift(int id){
	if (!lazy[id]) return ;
	add_lazy(id<<1, lazy[id]);
	add_lazy(id<<1 | 1, lazy[id]);
	lazy[id]=0;
}

void Add(int id, int tl, int tr, int l, int r, int val){
	if (tr<=l || r<=tl) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, val);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	Add(id<<1, tl, mid, l, r, val);
	Add(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=combine(seg[id<<1], seg[id<<1 | 1]);
}

pii Get(int id, int tl, int tr, int l, int r){
	if (tr<=l || r<=tl) return seg[0];
	if (l<=tl && tr<=r) return seg[id];
	shift(id);
	int mid=(tl+tr)>>1;
	return combine(Get(id<<1, tl, mid, l, r), Get(id<<1 | 1, mid, tr, l, r));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	seg[0]={inf, 0};
	mn.pb({{0, 1}, 0});
	mx.pb({{0, 1}, MAXN});
	cin>>n;
	for (int i=1; i<=n; i++) cin>>x>>y, A[x]=y;
	//for (int i=1; i<=n; i++) cerr<<A[i]<<" \n"[i==n];
	
	ll ans=0;
	// mx-mn+l = r
	build(1, 1, n+1);
	for (int i=1; i<=n; i++){
		while (mn.back().second>A[i]){
			Add(1, 1, n+1, mn.back().first.first, mn.back().first.second, mn.back().second-A[i]);
			mn.pop_back();
		}
		while (mx.back().second<A[i]){
			Add(1, 1, n+1, mx.back().first.first, mx.back().first.second, A[i]-mx.back().second);
			mx.pop_back();
		}
		mn.pb({{mn.back().first.second, i+1}, A[i]});
		mx.pb({{mx.back().first.second, i+1}, A[i]});
		pii p=Get(1, 1, n+1, 1, i+1);
		if (p.first==i) ans+=p.second;
	}
	cout<<ans<<'\n';
	
	return 0;
}