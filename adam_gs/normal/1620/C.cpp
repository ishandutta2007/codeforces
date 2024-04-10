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
	ll n, k, x;
	string s;
	cin >> n >> k >> x >> s; --x;
	vector<ll>V;
	ll akt=0;
	for(auto i : s) {
		if(i=='*') ++akt;
		else {
			if(akt*k) V.pb(akt*k);
			V.pb(0);
			akt=0;
		}
	}
	if(akt*k) V.pb(akt*k);
	string ans="";
	reverse(all(V));
	for(auto i : V) {
		if(!i) ans+="a";
		else {
			rep(j, x%(i+1)) ans+="b";
			x/=i+1;
		}
	}
	reverse(all(ans));
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}