#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops,no-stack-protector,fast-math")

using namespace std;
typedef pair<int, int> pii;
#define pb push_back

const int inf=1000000010;
const int MAXN=100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN], B[MAXN], ans[MAXN*3];
vector<pii> Q[MAXN];

struct SEGMENT{
	int seg[MAXN<<1];
	SEGMENT(){
		memset(seg, -63, sizeof(seg));
	}
	void Set(int pos, int val){
		seg[pos+MAXN]=max(seg[pos+MAXN], val);
		for (pos+=MAXN; pos>1; pos>>=1) seg[pos>>1]=max(seg[pos], seg[pos^1]);
	}
	int Get(int l, int r){
		int res=seg[0];
		for (l+=MAXN, r+=MAXN; l<r; l>>=1, r>>=1){
			if (l&1) res=max(res, seg[l++]);
			if (r&1) res=max(res, seg[--r]);
		}
		return res;
	}
} seg1, seg2;

inline int getlb(int x){
	return lower_bound(B, B+n+2, x)-B;
}
inline int getub(int x){
	return upper_bound(B, B+n+2, x)-B;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], B[i]=A[i];
	cin>>m;
	for (int i=1; i<=m; i++){
		cin>>x>>y;
		Q[y].pb({x, i});
	}
	B[n+1]=inf;
	sort(B, B+n+2);
	for (int i=1; i<=n; i++){
		int last=-inf, xid=getlb(A[i]);
		while (1){
			int pos=seg1.Get(getub((A[i]+last)/2), xid+1);
			if (pos<0) break ;
			seg2.Set(pos, -(A[i]-A[pos]));
			last=A[pos];
		}
		last=2*inf-A[i];
		while (1){
			int pos=seg1.Get(xid, getlb((A[i]+last+1)/2));
			if (pos<0) break ;
			seg2.Set(pos, -(A[pos]-A[i]));
			last=A[pos];
		}
		seg1.Set(xid, i);
		for (pii p:Q[i]) ans[p.second]=-seg2.Get(p.first, n);
	}
	for (int i=1; i<=m; i++) cout<<ans[i]<<'\n';
	
	return 0;
}