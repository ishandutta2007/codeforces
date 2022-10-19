#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
void solve() {
	ll ans=0, n;
	cin >> n;
	while(n>0) {
		ll akt=1;
		while((akt-1)/2<n) {
			akt*=3;
		}
		akt/=3;
		ans+=akt;
		n-=akt;
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}