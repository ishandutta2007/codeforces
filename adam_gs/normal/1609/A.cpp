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
	ll n;
	cin >> n;
	ll ile=0, ans=0, ma=0;
	while(n--) {
		ll a;
		cin >> a;
		while(a%2==0) {
			a/=2;
			++ile;
		}
		ma=max(ma, a);
		ans+=a;
	}
	ans-=ma;
	while(ile--) ma*=2;
	ans+=ma;
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}