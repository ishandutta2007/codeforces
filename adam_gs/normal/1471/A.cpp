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
		ll x, sum=0, ans=0;
		cin >> n >> x;
		while(n--) {
			ll a;
			cin >> a;
			sum+=a;
			ans+=(a+x-1)/x;
		}
		sum=(sum+x-1)/x;
		cout << sum << " " << ans << '\n';
	}
}