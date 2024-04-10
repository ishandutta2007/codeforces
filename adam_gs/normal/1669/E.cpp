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
	map<pair<char,char>,ll>mp;
	ll ans=0;
	while(n--) {
		char a, b;
		cin >> a >> b;
		rep(i, 11) {
			ans+=mp[{a, i+'a'}];
			ans+=mp[{i+'a', b}];
		}
		ans-=2*mp[{a, b}];
		++mp[{a, b}];
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}