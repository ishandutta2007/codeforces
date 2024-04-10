#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
const int LIM=1e5+7, MOD=1e9+7;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {		
		ll x, y;
		cin >> x >> y;
		ll ans=0, l=1;
		while(l*(l+2)<=x && l<=y) ++l;
		while(l) {
			ll p=l+1, k=y;
			if(p>k || p*l+l>x) {
				--l;
				continue;
			}
			while(p<k) {
				ll sr=(p+k+1)/2;
				if(sr*l+l>x) k=sr-1; else p=sr;
			}
			ans+=p-l;
			--l;
		}
		cout << ans << '\n';
	}
}