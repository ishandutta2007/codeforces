#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
#define all(a) a.begin(), a.end()
ll pow(ll a,ll b,ll c){ll w=1;while(b){if(b&1)w=(w*a)%c;b/=2;a=(a*a)%c;}return w;}
const int LIM=2e5+7, MAXA=3e5+7;
ll ile[4*MAXA], N=1, b[LIM], odejmij[4*MAXA];
void dodaj(int v) {
	v+=N;
	while(v) {
		++ile[v];
		v/=2;
	}
}
void upd(int l, int r, ll x) {
	l+=N; r+=N;
	odejmij[l]+=x;
	if(l!=r) odejmij[r]+=x;
	while(l/2!=r/2) {
		if(l%2==0) odejmij[l+1]+=x;
		if(r%2==1) odejmij[r-1]+=x;
		l/=2; r/=2;
	}
}
ll cnt(int v) {
	v+=N;
	ll ans=0;
	while(v) {
		ans+=odejmij[v];
		v/=2;
	}
	return ans;
}
ll licz(int l, int r) {
	l+=N; r+=N;
	ll ans=ile[l];
	if(l!=r) ans+=ile[r];
	while(l/2!=r/2) {
		if(l%2==0) ans+=ile[l+1];
		if(r%2==1) ans+=ile[r-1];
		l/=2; r/=2;
	}
	return ans;
}
void solve() {
	while(N<MAXA) N*=2;
	int n;
	cin >> n;
	ll suma=0;
	rep(i, n) {
		ll a;
		cin >> a;
		suma+=a;
		dodaj(a);
		b[i]+=suma+a*i-cnt(a);
		for(ll j=1; j*a<MAXA; ++j) {
			b[i]-=a*licz(j*a, MAXA-1);
			upd(j*a, MAXA-1, a);
		}
	}
	rep(i, n) {
		if(i) b[i]+=b[i-1];
		cout << b[i] << " ";
	}
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	while(t--) solve();
}