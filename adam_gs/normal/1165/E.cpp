#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(ll a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
const ll MOD=998244353;
const int LIM=2e5+7;
ll a[LIM], b[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, ans=0;
	cin >> n;
	rep(i, n) {
		cin >> a[i];
		a[i]*=(i+1)*(n-i);
	}
	sort(a, a+n);
	reverse(a, a+n);
	rep(i, n) cin >> b[i];
	sort(b, b+n);
	rep(i, n) {
		a[i]=((a[i]%MOD)*b[i])%MOD;
		ans=(ans+a[i])%MOD;
	}
	cout << ans << '\n';
}