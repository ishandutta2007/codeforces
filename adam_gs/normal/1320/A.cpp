#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	map<ll,ll>mp;
	ll ans=0;
	rep(i, n) {
		ll a;
		cin >> a;
		mp[i-a]+=a;
		ans=max(ans, mp[i-a]);
	}
	cout << ans << '\n';
}