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
	int n;
	cin >> n;
	ll sum=0, x=0;
	while(n--) {
		ll a;
		cin >> a;
		sum+=a;
		x^=2*a;
	}
	cout << 2 << '\n' << x/2 << " ";
	sum+=x/2;
	cout << sum << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}