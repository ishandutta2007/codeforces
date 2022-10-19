#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
const int LIM=1e5+7, MOD=1e9+7;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		ll a[n], b[n], c[n], ans=0, l=-1, x=-1, y=-1;
		rep(i, n) cin >> c[i];
		rep(i, n) cin >> a[i];
		rep(i, n) cin >> b[i];
		for(int i=n-1; i>=0; --i) {
			if(x>y) swap(x, y);
			if(x==y) {
				ans=max(ans, l+1);
				l=c[i];
			} else {
				ans=max(ans, l+y-x+1);
				l=max(l+x+c[i]-y+1, c[i]);
			}
			x=a[i];
			y=b[i];
		}
		cout << ans << '\n';
	}
}