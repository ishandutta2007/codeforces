#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e6+7, INF=1e9+7;
int tr[4*LIM], lazy[4*LIM], N=1;
pair<int,pair<int,int>>T[LIM];
void spl(int v) {
	tr[2*v]=min(lazy[v], tr[2*v]);
	tr[2*v+1]=min(lazy[v], tr[2*v+1]);
	lazy[2*v]=min(lazy[2*v], lazy[v]);
	lazy[2*v+1]=min(lazy[2*v+1], lazy[v]);
	lazy[v]=INF;
}
void upd(int v, int l, int r, int a, int b, int x) {
	if(b<l || a>r) return;
	if(a<=l && r<=b) {
		tr[v]=min(tr[v], x);
		lazy[v]=min(lazy[v], x);
		return;
	}
	if(lazy[v]<INF) spl(v);
	int mid=(l+r)/2;
	upd(2*v, l, mid, a, b, x);
	upd(2*v+1, mid+1, r, a, b, x);
	tr[v]=max(tr[2*v], tr[2*v+1]);
}
int cnt(int v, int l, int r, int a, int b) {
	if(b<l || a>r) return 0;
	if(a<=l && r<=b) return tr[v];
	if(lazy[v]<INF) spl(v);
	int mid=(l+r)/2;
	int ans=max(cnt(2*v, l, mid, a, b), cnt(2*v+1, mid+1, r, a, b));
	tr[v]=max(tr[2*v], tr[2*v+1]);
	return ans;
}
void solve() {
	int n, m;
	cin >> n >> m;
	while(N<m) N*=2;
	rep(i, 2*N) tr[i]=lazy[i]=INF;
	rep(i, n) cin >> T[i].nd.st >> T[i].nd.nd >> T[i].st;
	sort(T, T+n);
	reverse(T, T+n);
	int ans=INF, koniec=INF;
	rep(i, n) {
		upd(1, 0, N-1, T[i].nd.st-1, T[i].nd.nd-2, T[i].st);
		if(T[i].nd.nd==m) {
			koniec=T[i].st;
		}
		ans=min(ans, max(cnt(1, 0, N-1, 0, m-2), koniec)-T[i].st);
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}