#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=107+7;
const ll INF=1e18+7;
ll T[LIM], n, h;
bool f(ll x) {
	ll ans=x;
	rep(i, n-1) ans+=min(x, T[i+1]-T[i]);
	return ans>=h;
}
void solve() {
	cin >> n >> h;
	rep(i, n) cin >> T[i];
	ll p=0, k=INF;
	while(p<k) {
		ll sr=(p+k)/2;
		if(f(sr)) k=sr; else p=sr+1;
	}
	cout << p << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}