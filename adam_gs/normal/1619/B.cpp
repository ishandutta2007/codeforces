#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	ll n, ans=0;
	cin >> n;
	for(ll i=1; i*i<=n; ++i) ++ans;
	for(ll i=1; i*i*i<=n; ++i) ++ans;
	for(ll i=1; i*i*i*i*i*i<=n; ++i) --ans;
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}