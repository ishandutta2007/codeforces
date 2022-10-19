#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll n, x;
		cin >> n >> x;
		vector<pair<ll,ll>>V;
		rep(i, n) {
			ll a;
			cin >> a;
			V.pb({a, 1});
		}
		int l=0;
		while(l<V.size()) {
			if(V[l].st%x==0) {
				V.pb({V[l].st/x, V[l].nd*x});
			} else break;
			++l;
		}
		ll ans=0;
		for(auto i : V) ans+=i.st*i.nd;
		cout << ans << '\n';
	}
}