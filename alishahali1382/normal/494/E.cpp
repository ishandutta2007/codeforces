#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")

using namespace std;
#define all(x) x.begin(), x.end()
#define pb push_back

const int MAXN=100010;

struct Node{
	int mn=0;
	bool cnt=0, sz=0;
};

Node Merge(Node x, Node y){
	Node z;
	z.mn=min(x.mn, y.mn);
	if (z.mn==x.mn) z.cnt^=x.cnt;
	if (z.mn==y.mn) z.cnt^=y.cnt;
	z.sz=(x.sz^y.sz);
	return z;
}

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], B[MAXN], C[MAXN], D[MAXN];
Node seg[MAXN<<2];
int lazy[MAXN<<2];
vector<pair<pair<int, int>, int>> vec[MAXN];
vector<int> compx, compy;

Node Build(int id, int tl, int tr){
	lazy[id]=0;
	if (tr-tl==1){
		seg[id].mn=0;
		seg[id].sz=seg[id].cnt=(compx[tr]-compx[tl])%2;
		return seg[id];
	}
	int mid=(tl+tr)>>1;
	return seg[id]=Merge(Build(id<<1, tl, mid), Build(id<<1 | 1, mid, tr));
}

inline void add_lazy(int id, int val){
	seg[id].mn+=val;
	lazy[id]+=val;
}

inline void shift(int id){
	if (!lazy[id]) return ;
	add_lazy(id<<1, lazy[id]);
	add_lazy(id<<1 | 1, lazy[id]);
	lazy[id]=0;
}

void Add(int id, int tl, int tr, int l, int r, int val){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, val);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	Add(id<<1, tl, mid, l, r, val);
	Add(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=Merge(seg[id<<1], seg[id<<1 | 1]);
}

inline int f(int x, int bit){
	return (x+(1<<bit)-1)>>bit;
}

bool Solve(int bit){
	compx.clear();
	compy.clear();
	for (int i=0; i<MAXN; i++) vec[i].clear();
	for (int i=1; i<=m; i++){
		int x=f(A[i], bit), y=f(B[i], bit), xx=f(C[i], bit), yy=f(D[i], bit);
		compx.pb(x);
		compx.pb(xx);
		compy.pb(y);
		compy.pb(yy);
	}
	sort(all(compx));
	sort(all(compy));
	compx.resize(unique(all(compx))-compx.begin());
	compy.resize(unique(all(compy))-compy.begin());
	compx.pb(1000000001);
	compy.pb(1000000001);
	for (int i=1; i<=m; i++){
		int x=f(A[i], bit), y=f(B[i], bit), xx=f(C[i], bit), yy=f(D[i], bit);
		x=lower_bound(all(compx), x)-compx.begin();
		y=lower_bound(all(compy), y)-compy.begin();
		xx=lower_bound(all(compx), xx)-compx.begin();
		yy=lower_bound(all(compy), yy)-compy.begin();
		vec[y].pb({{x, xx}, +1});
		vec[yy].pb({{x, xx}, -1});
	}
	int res=0;
	n=compx.size()-1;
	Build(1, 0, n);
	for (int i=0; i+1<compy.size(); i++){
		for (auto p:vec[i]) Add(1, 0, n, p.first.first, p.first.second, p.second);
		if ((compy[i+1]-compy[i])%2 && seg[1].mn==0) res^=seg[1].sz^seg[1].cnt; 
	}
	return res%2;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for (int i=1; i<=m; i++) cin>>A[i]>>B[i]>>C[i]>>D[i], C[i]++, D[i]++;
	for (int i=0; (1<<i)<=k; i++) if (Solve(i)){
		cout<<"Hamed\n";
		return 0;
	}
	cout<<"Malek\n";
	
	return 0;
}