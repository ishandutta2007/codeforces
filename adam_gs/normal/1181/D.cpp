#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=5e5+7;
vector<pair<ll,int>>pyt[LIM];
vector<int>V[LIM];
ll ile[LIM], sum[LIM], nowe[LIM], ans[LIM], tr[4*LIM], N=1;
void upd(int v) {
	v+=N;
	while(v) {
		++tr[v];
		v/=2;
	}
}
int cnt(int v, int k) {
	if(v>=N) return v-N;
	if(tr[2*v]<k) return cnt(2*v+1, k-tr[2*v]);
	return cnt(2*v, k);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, m, q;
	cin >> n >> m >> q;
	while(N<m) N*=2;
	rep(i, n) {
		ll a;
		cin >> a; --a;
		++ile[a];
	}
	rep(i, m) {
		++nowe[ile[i]];
		V[ile[i]].pb(i);
	}
	rep(i, n) {
		sum[i+1]=sum[i]+nowe[i];
		nowe[i+1]+=nowe[i];
	}
	rep(i, q) {
		ll x;
		cin >> x; x-=n;
		if(x>sum[n]) {
			x-=sum[n]+1;
			ans[i]=x%m;
			continue;
		}
		ll p=1, k=n;
		while(p<k) {
			ll sr=(p+k)/2;
			if(sum[sr]<x) p=sr+1; else k=sr;
		}
		x-=sum[p-1];
		pyt[p].pb({x, i});
	}
	rep(i, n) {
		for(auto j : V[i]) upd(j);
		for(auto j : pyt[i+1]) ans[j.nd]=cnt(1, j.st);
	}
	rep(i, q) cout << ans[i]+1 << '\n';
}