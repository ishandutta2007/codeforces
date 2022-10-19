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
void solve() {
	ll n, x;
	cin >> n >> x;
	ll D[n], H[n], ma=0, roz=0;
	rep(i, n) {
		cin >> D[i] >> H[i];
		ma=max(ma, D[i]);
		roz=max(roz, D[i]-H[i]);
	}
	if(ma>=x) {
		cout << 1 << '\n';
		return;
	}
	if(roz==0) {
		cout << -1 << '\n';
		return;
	}
	cout << (x-ma+roz-1)/roz+1 << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}