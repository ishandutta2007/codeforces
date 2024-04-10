#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(ll a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	string s;
	cin >> s;
	ll ans=0, akt=0, mi=0;
	rep(i, s.size()) {
		++akt;
		if(s[i]=='-') akt-=2;
		if(akt<mi) {
			mi=akt;
			ans+=i+1;
		}
	}
	ans+=s.size();
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}