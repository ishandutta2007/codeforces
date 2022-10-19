#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=5e5+7, INF=1e9+7;
int tr[4*LIM][3], N;
ll T[LIM], jaka[LIM];
pair<ll,int>P[LIM];
void upd(int v, int x, int k) {
	v+=N;
	tr[v][k]=x;
	v/=2;
	while(v) {
		tr[v][k]=max(tr[2*v][k], tr[2*v+1][k]);
		v/=2;
	}
}
int cnt(int l, int r, int k) { 
	if(l>r) return -INF;
	l+=N; r+=N;
	int ans=max(tr[l][k], tr[r][k]);
	while(l/2!=r/2) {
		if(l%2==0) ans=max(ans, tr[l+1][k]);
		if(r%2==1) ans=max(ans, tr[r-1][k]);
		l/=2; r/=2;
	}
	return ans;
}
void solve() {
	int n;
	cin >> n;
	N=1;
	while(N<=n) N*=2;
	rep(i, 2*N) rep(j, 3) tr[i][j]=-INF;
	rep(i, n+1) {
		T[i]=0;
		P[i]={0, 0};
		jaka[i]=0;
	}
	rep(i, n) {
		cin >> T[i+1];
		T[i+1]+=T[i];
		P[i+1]={T[i+1], i+1};
	}
	sort(P, P+n+1);
	rep(i, n+1) jaka[P[i].nd]=i;
	rep(i, 3) upd(jaka[0], 0, i);
	int dp;
	for(int i=1; i<=n; ++i) {
		int p=0, k=n;
		while(p<k) {
			int sr=(p+k+1)/2;
			if(P[sr].st<T[i]) p=sr; else k=sr-1;
		}
		dp=-i;
		if(P[p].st<T[i]) dp=max(dp, i+cnt(0, p, 0));
		int po=0, ko=n;
		while(po<ko) {
			int sr=(po+ko)/2;
			if(P[sr].st>T[i]) ko=sr; else po=sr+1;
		}
		if(P[po].st>T[i]) dp=max(dp, -i+cnt(po, n, 2));
		while(p<=n && P[p].st<T[i]) ++p;
		while(po>=0 && P[po].st>T[i]) --po;
		if(p<po) dp=max(dp, cnt(p, po, 1));
		upd(jaka[i], dp-i, 0);
		upd(jaka[i], dp, 1);
		upd(jaka[i], dp+i, 2);
	}
	cout << dp << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}