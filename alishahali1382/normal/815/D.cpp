#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops,no-stack-protector,fast-math")

using namespace std;
typedef long long ll;

const int MAXN = 500010;

ll n, m, k, p, q, r, ans;
int A[MAXN], B[MAXN], C[MAXN];
int maxb[MAXN], maxc[MAXN];
ll seg[MAXN<<2];
int lazy[MAXN<<2], Mn[MAXN<<2], Mx[MAXN<<2];
vector<int> vec[MAXN];

void add_lazy(int id, int len, int lz){
	seg[id]=1ll*len*lz;
	lazy[id]=Mn[id]=Mx[id]=lz;
}

void shift(int id, int tl, int tr){
	if (!lazy[id]) return ;
	int mid=(tl+tr)>>1;
	add_lazy(id<<1, mid-tl, lazy[id]);
	add_lazy(id<<1 | 1, tr-mid, lazy[id]);
	lazy[id]=0;
}

void update(int id, int tl, int tr, int l, int r, int val){
	if (tr<=l || r<=tl || Mn[id]>=val) return ;
	if (l<=tl && tr<=r && Mx[id]<=val){
		add_lazy(id, tr-tl, val);
		return ;
	}
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, l, r, val);
	update(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=seg[id<<1]+seg[id<<1 | 1];
	Mn[id]=min(Mn[id<<1], Mn[id<<1 | 1]);
	Mx[id]=max(Mx[id<<1], Mx[id<<1 | 1]);
}

ll get(int id, int tl, int tr, int l, int r, ll val){
	if (r<=tl || tr<=l || Mx[id]<=val) return 0;
	if (l<=tl && tr<=r && Mn[id]>=val) return seg[id]-val*(tr-tl);
	shift(id, tl, tr);
	int mid=(tl+tr)>>1;
	return get(id<<1, tl, mid, l, r, val) + get(id<<1 | 1, mid, tr, l, r, val);
}

void Add(int x, int y){
	update(1, 1, MAXN, 1, x+1, y);
}

ll Get(int x, int y){
	return get(1, 1, MAXN, x+1, MAXN, y);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>p>>q>>r;
	for (int i=1; i<=n; i++) cin>>A[i]>>B[i]>>C[i], vec[A[i]].push_back(i);
	for (int a=p; a; a--){
		maxb[a]=maxb[a+1];
		maxc[a]=maxc[a+1];
		for (int id:vec[a]){
			maxb[a]=max(maxb[a], B[id]);
			maxc[a]=max(maxc[a], C[id]);
		}
	}
	for (int a=1; a<=p; a++){
		ans+=(q-maxb[a])*(r-maxc[a])-Get(maxb[a], maxc[a]);
		for (int id:vec[a]) Add(B[id], C[id]);
	}
	cout<<ans<<'\n';
	
	return 0;
}