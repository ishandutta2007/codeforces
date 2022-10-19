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
	ll a, s;
	cin >> a >> s;
	vector<ll>V;
	while(s) {
		ll x=a%10, y=s%10;
		a/=10; s/=10;
		if(y<x) {
			y+=10*(s%10);
			s/=10;
			if(y-x>=10 || y<x) {
				cout << -1 << '\n';
				return;
			}
		}
		V.pb(y-x);
	}
	if(a) {
		cout << -1 << '\n';
		return;
	}
	while(V.back()==0) V.pop_back();
	reverse(all(V));
	for(auto i : V) cout << i;
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}