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
		int n;
		cin >> n;
		ll T[n], w[n], ans=0;
		rep(i, n) { cin >> T[i]; w[i]=0; }
		for(int i=n-1; i>=0; --i) {
			ll a=i+1;
			while(a<=n) {
				if(w[a-1]) { a+=w[a-1]; break; }
				a+=T[a-1];
			}
			w[i]=a-i-1;
			ans=max(ans, w[i]);
		}
		cout << ans << '\n';
	}
}