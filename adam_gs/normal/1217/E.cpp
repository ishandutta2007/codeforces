#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll INF=1e18+7;
const int LIM=2e5+7;
pair<ll,ll>tr[4*LIM][9];
int N=1;
void merge(int v, int k) {
	tr[v][k]=tr[2*v][k];
	if(tr[2*v+1][k].st<tr[v][k].st) {
		tr[v][k]={tr[2*v+1][k].st, tr[v][k].st};
	} else tr[v][k].nd=min(tr[v][k].nd, tr[2*v+1][k].st);
	tr[v][k].nd=min(tr[v][k].nd, tr[2*v+1][k].nd);
}
void mi(pair<ll,ll>&ans, pair<ll,ll>&x) {
	if(ans.st>x.st) ans={x.st, ans.st};
	else ans.nd=min(ans.nd, x.st);
	ans.nd=min(ans.nd, x.nd);
}
void upd(int v, ll x, int k)  {
	v+=N;
	tr[v][k]={x, INF};
	v/=2;
	while(v) {
		merge(v, k);
		v/=2;
	}
}
ll cnt(int l, int r, int k) {
	l+=N; r+=N;
	pair<ll,ll>ans=tr[l][k];
	if(l!=r) mi(ans, tr[r][k]);
	while(l/2!=r/2) {
		if(l%2==0) mi(ans, tr[l+1][k]);
		if(r%2==1) mi(ans, tr[r-1][k]);
		l/=2; r/=2;
	}
	return ans.st+ans.nd;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q;
	cin >> n >> q;
	while(N<n) N*=2;
	rep(i, 2*N) rep(j, 9) tr[i][j]={INF, INF};
	rep(i, n) {
		ll x;
		cin >> x;
		ll p=x;
		rep(j, 9) {
			if(p%10) upd(i, x, j);
			p/=10;
		}
	}
	while(q--) {
		ll t, a, b;
		cin >> t >> a >> b; --a;
		if(t==1) {
			ll p=b;
			rep(j, 9) {
				if(p%10) upd(a, b, j);
				else upd(a, INF, j);
				p/=10;
			}
		} else {
			--b;
			ll ans=INF;
			rep(j, 9) ans=min(ans, cnt(a, b, j));
			cout << (ans==INF?-1:ans) << '\n';
		}
	}
}