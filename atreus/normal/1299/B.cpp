#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 10;

struct poll{
	ll x;
	ll y;
	poll(ll x_ = 0, ll y_ = 0){
		x = x_, y = y_;
	}
};

ll x[maxn], y[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	if (n & 1)
		return cout << "NO\n", 0;
	for (ll i = 0; i < n / 2; i++){
		poll me = poll(x[i + 1] - x[i], y[i + 1] - y[i]);
		poll th = poll(x[(i + n/2 + 1) % n] - x[i + n/2], y[(i + n/2 + 1) % n] - y[i + n/2]);
		if (me.x != -1ll * th.x or me.y != -1 * th.y)
			return cout << "NO\n", 0;
	}
	cout << "YES\n";
}