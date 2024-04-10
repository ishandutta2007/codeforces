#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll maxn = 100 + 10;
const ll mod = 1e9 + 7;
const ll inf = 1e15;

ll p[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	vector<pair<ll,ll>> a;
	for (ll i = 0; i < n; i++){
		ll k, c;
		cin >> k >> c;
		a.push_back({c, k});
	}
	sort(a.begin(), a.end());
	ll t;
	cin >> t;
	for (ll i = 0; i < t; i++)
		cin >> p[i];
	p[t] = inf;
	ll idx = 0;
	ll now = 0;
	ll answer = 0;
	for (ll i = 0; i < n; i++){
		ll c = a[i].first, k = a[i].second;
		while (k > 0){
			while (idx < t and p[idx] <= now)
				idx ++;
			ll tmp = min(k, p[idx] - now);
			answer += tmp * c * (idx+1);
			now += tmp;
			k -= tmp;
		}
	}
	cout << answer << endl;
}