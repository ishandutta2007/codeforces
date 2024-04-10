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
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=1000010, LOG=20;

inline void fix(int &x){
	if (x>=mod) x-=mod;
	if (x<0) x+=mod;
}
struct Segment{
	int seg[MAXN<<2], lazy1[MAXN<<2], cnt[MAXN<<2];
	bool lazy2[MAXN<<2];
	void Build(int id, int tl, int tr){
		lazy1[id]=lazy2[id]=0;
		if (tr-tl==1){
			cnt[id]=1;
			seg[id]=0;
			return ;
		}
		int mid=(tl+tr)>>1;
		Build(id<<1, tl, mid);
		Build(id<<1 | 1, mid, tr);
		cnt[id]=cnt[id<<1] + cnt[id<<1 | 1];
		seg[id]=seg[id<<1] + seg[id<<1 | 1];
	}
	//void shift(int);
	void add_lazy1(int id, int val){
		if (id>=4*MAXN) return ;
		if (lazy2[id]) shift(id);
		fix(lazy1[id]+=val);
		seg[id]=(seg[id] + 1ll*cnt[id]*val)%mod;
	}
	void add_lazy2(int id){
		if (id>=4*MAXN) return ;
		lazy2[id]=1;
		lazy1[id]=0;
		seg[id]=0;
	}
	void shift(int id){
		if (lazy2[id]){
			lazy2[id]=0;
			add_lazy2(id<<1);
			add_lazy2(id<<1 | 1);
		}
		if (lazy1[id]){
			add_lazy1(id<<1, lazy1[id]);
			add_lazy1(id<<1 | 1, lazy1[id]);
			lazy1[id]=0;
		}
	}
	void Add(int id, int tl, int tr, int l, int r, int val){
		if (r<=tl || tr<=l) return ;
		if (l<=tl && tr<=r){
			add_lazy1(id, val);
			return ;
		}
		shift(id);
		int mid=(tl+tr)>>1;
		Add(id<<1, tl, mid, l, r, val);
		Add(id<<1 | 1, mid, tr, l, r, val);
		fix(seg[id]=seg[id<<1] + seg[id<<1 | 1]);	
	}
	void Set0(int id, int tl, int tr, int l, int r){
		if (r<=tl || tr<=l) return ;
		if (l<=tl && tr<=r){
			add_lazy2(id);
			return ;
		}
		shift(id);
		int mid=(tl+tr)>>1;
		Set0(id<<1, tl, mid, l, r);
		Set0(id<<1 | 1, mid, tr, l, r);
		cnt[id]=cnt[id<<1] + cnt[id<<1 | 1];
		fix(seg[id]=seg[id<<1] + seg[id<<1 | 1]);
	}
	void SetDead(int id, int tl, int tr, int pos, int typ){
		if (pos<tl || tr<=pos) return ;
		if (tr-tl==1){
			cnt[id]=typ;
			seg[id]*=typ;
			return ;
		}
		shift(id);
		int mid=(tl+tr)>>1;
		Set0(id<<1, tl, mid, pos, typ);
		Set0(id<<1 | 1, mid, tr, pos, typ);
		fix(seg[id]=seg[id<<1] + seg[id<<1 | 1]);	
	}
	int Get(int id, int tl, int tr, int pos){
		if (pos<tl || tr<=pos) return 0;
		if (tr-tl==1) return seg[id];
		shift(id);
		int mid=(tl+tr)>>1;
		return Get(id<<1, tl, mid, pos) + Get(id<<1 | 1, mid, tr, pos);
	}
} seg;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
vector<int> bad[MAXN], v1[MAXN];
vector<pii> v0[MAXN];
set<int> st;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k;
	while (k--){
		cin>>x>>y>>a>>b;
		bad[y].pb(a+1);
		bad[b+1].pb(x);
		v0[y].pb({x, a+1});
		v1[b+1].pb(x);
	}
	seg.Build(1, 0, MAXN);
	seg.Add(1, 0, MAXN, 1, n+1, 1);
	for (pii p:v0[1]){
		seg.Set0(1, 0, MAXN, p.first, n+1);
		seg.SetDead(1, 0, MAXN, p.first, 0);
		st.insert(p.first);
	}
	st.insert(n+1);
	for (int i=2; i<=m; i++){
		//cerr<<"dp["<<i-1<<"]: ";for (int j=1; j<=n; j++) cerr<<seg.Get(1, 0, MAXN, j)<<' ';cerr<<'\n';
		//cerr<<'\n';
		for (int x:v1[i]) seg.SetDead(1, 0, MAXN, x, 1), st.erase(x);
		for (pii p:v0[i]) st.insert(p.first);
		sort(all(bad[i]));
		reverse(all(bad[i]));
		bad[i].resize(unique(all(bad[i]))-bad[i].begin());
		for (int x:bad[i]){
			int delta=seg.Get(1, 0, MAXN, x-1);
			seg.Add(1, 0, MAXN, x, *st.lower_bound(x), delta);
		}
		sort(all(v0[i]));
		//debugv(st)
		for (pii p:v0[i]){
			//debugp(p)
			int delta=-seg.Get(1, 0, MAXN, p.second-1);
			seg.Add(1, 0, MAXN, p.second, *st.lower_bound(p.second), delta);
			seg.Set0(1, 0, MAXN, p.first, p.second);
			seg.SetDead(1, 0, MAXN, p.first, 0);
		}
	}
	fix(ans=seg.Get(1, 0, MAXN, n));
	cout<<ans<<'\n';
	
	return 0;
}
/*
15 10 5
11 4 11 4
5 8 5 8
14 2 14 2
8 5 8 5
12 3 12 3

ans : 5


4 4 2
2 3 2 3
3 2 3 2


6 8 5
5 7 5 7
3 1 3 1
2 8 2 8
5 8 5 8
4 1 4 3

ans : 1
*/