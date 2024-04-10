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

int n, m, k, u, v, x, y, t, a, b;
int Mn[MAXN<<2], Mx[MAXN<<2];
int lazy[MAXN<<2];
int ans[MAXN];
vector<int> vec[MAXN];
vector<pii> query[MAXN];

void add_lazy(int id, int val){
	Mn[id]=min(Mn[id], val);
	Mx[id]=min(Mx[id], val);
	lazy[id]=min(lazy[id], val);
}

void shift(int id){
	add_lazy(id<<1, lazy[id]);
	add_lazy(id<<1 | 1, lazy[id]);
	lazy[id]=inf;
}

void Minimize(int id, int tl, int tr, int l, int r, int val){
	//if (id==1) cerr<<"Minimize "<<l<<' '<<r<<' '<<val<<'\n';
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, val);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	Minimize(id<<1, tl, mid, l, r, val);
	Minimize(id<<1 | 1, mid, tr, l, r, val);
	Mn[id]=max(Mn[id<<1], Mn[id<<1 | 1]);
	Mx[id]=max(Mx[id<<1], Mx[id<<1 | 1]);
}
/*
int BS(int id, int tl, int tr, int l, int r, int val){
	if (tr<=l || r<=tl) return 0;
	if (Mn[id]>val) return -1;
	if (tr-tl==1) return tr;
	shift(id);
	int mid=(tl+tr)>>1;
	if (l<=tl && tr<=r){
		if (Mx[id<<1]<=val) return BS(id<<1 | 1, mid, tr, l, r, val);
		return BS(id<<1, tl, mid, l, r, val);
	}
	int tmp=BS(id<<1, tl, mid, l, r, val);
	
	return min(, BS(id<<1 | 1, mid, tr, l, r, val));
}*/

int Get(int id, int tl, int tr, int l, int r){
	if (r<=tl || tr<=l) return 0;
	if (l<=tl && tr<=r) return Mx[id];
	shift(id);
	int mid=(tl+tr)>>1;
	return max(Get(id<<1, tl, mid, l, r), Get(id<<1 | 1, mid, tr, l, r));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(Mn, 63, sizeof(Mn));
	memset(Mx, 63, sizeof(Mx));
	memset(lazy, 63, sizeof(lazy));
	cin>>n>>m;
	while (m--){
		cin>>u>>v;
		vec[u].pb(v);
	}
	cin>>m;
	for (int i=1; i<=m; i++){
		cin>>x>>y;
		query[x].pb({y, i});
	}
	
	for (int i=n; i; i--){
		for (int j:vec[i]) Minimize(1, 1, n+1, i, j, j);
		for (pii p:query[i]){
			//ans[p.second]=BS(1, 1, n+1, i, p.first, p.first);
			int dwn=i, up=p.first+1;
			while (up-dwn>1){
				int mid=(dwn+up)/2;
				if (Get(1, 1, n+1, i, mid)<=p.first) dwn=mid;
				else up=mid;
			}
			ans[p.second]=dwn;
		}
	}
	/*
	for (int i=1; i<=n; i++) debug2(i, Get(1, 1, n+1, i, i+1))
	debug(Get(1, 1, n+1, 1, 4))
	//debug(BS(1, 1, n+1, 1, 4, 4))
	*/
	for (int i=1; i<=m; i++) cout<<ans[i]<<'\n';
	
	return 0;
}