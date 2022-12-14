#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;

ll n, m;
ll a[maxn], b[maxn];
map<ll, ll> mp1, mp2;

ll check(ll dis){
	ll ret = 0;
	for (ll i = 0; i < n; i++){
		mp1[a[i] % (2ll * dis)] ++;
		ret = max(ret, mp1[a[i] % (2ll * dis)]);
	}
	for (ll i = 0; i < m; i++){
		mp2[b[i] % (2 * dis)] ++;
		ret = max(ret, mp2[b[i] % (2ll * dis)]);
	}
	for (auto it : mp1)
		ret = max(ret, it.second + mp2[(it.first + dis) % (2ll * dis)]);
	mp1.clear();
	mp2.clear();
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	ll y;
	cin >> n >> y;
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	cin >> m >> y;
	for (ll i = 0; i < m; i++)
		cin >> b[i];
	ll answer = 2;
	for (ll i = 0; i <= 32; i++){
		answer = max(answer, check(1ll << i));
	}
	cout << answer << endl;
}