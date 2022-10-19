#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
#define all(a) a.begin(), a.end()
int nwd(int a, int b) {
	if(!a) return b;
	return nwd(b%a, a);
}
void solve() {
	ll n;
	cin >> n;
	vector<ll>ans;
	ll xd=1;
	for(ll i=1; i<n; ++i) {
		if(nwd(n, i)==1) {
			ans.pb(i);
			xd*=i;
			xd%=n;
		}
	}
	if(xd!=1) cout << ans.size()-1 << '\n';
	else cout << ans.size() << '\n';
	for(auto i : ans) if(i==1 || i!=xd) cout << i << " ";
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	while(t--) solve();
}