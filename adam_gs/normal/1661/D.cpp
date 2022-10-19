#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll LIM=3e5+7;
ll T[LIM], tra[4*LIM], trb[4*LIM], N=1;
void spl(int v, ll x) {
	tra[2*v]+=tra[v];
	tra[2*v+1]+=tra[v]+x*trb[v];
	trb[2*v]+=trb[v];
	trb[2*v+1]+=trb[v];
	tra[v]=trb[v]=0;
}
void upd(int v, ll l, ll r, int a, int b, ll x, ll y) {
	if(r<a || l>b) return;
	if(a<=l && r<=b) {
		tra[v]+=x;
		trb[v]+=y;
		return;
	}
	spl(v, (r-l+1)/2);
	int mid=(l+r)/2;
	upd(2*v, l, mid, a, b, x, y);
	upd(2*v+1, mid+1, r, a, b, x+((r-l+1)/2)*y, y);
}
void cnt(int v, int l, int r, int x) {
	if(l==r) return;
	spl(v, (r-l+1)/2);
	int mid=(l+r)/2;
	if(x<=mid) cnt(2*v, l, mid, x);
	else cnt(2*v+1, mid+1, r, x);
}
void solve() {
	int n, k;
	cin >> n >> k;
	while(N<n) N*=2;
	ll ans=0;
	rep(i, n) cin >> T[i];
	for(int i=n-1; i>=0; --i) {
		cnt(1, 0, N-1, i);
		if(tra[N+i]<T[i]) {
			ll p=max(i-k+1, 0);
			ll d=i-p+1;
			ll z=(T[i]-tra[N+i]+d-1)/d;
			ans+=z;
			upd(1, 0, N-1, p, p+k-1, z*(1-p), z);
		}
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}