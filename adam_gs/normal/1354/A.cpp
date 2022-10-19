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
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	if(b>=a) {
		cout << b << '\n';
		return;
	}
	a-=b;
	if(d>=c) {
		cout << -1 << '\n';
		return;
	}
	cout << b+((a+c-d-1)/(c-d))*c << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}