#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	int a, b, c, m;
	cin >> a >> b >> c >> m;
	cout << ((2*max(a, max(b, c))-a-b-c-1<=m && m<=a+b+c-3)?"YES":"NO") << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}