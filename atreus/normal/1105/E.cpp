/**
 *    author:  Atreus
 *    created: 20.01.2019
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll maxn = 1e5 + 10;

ll type[maxn], a[maxn];
ll adj[50];
ll dp[(1 << 22) + 10], pd[(1 << 22) + 10];

map <string, ll> mp;

ll cntbit(ll mask){
	ll ret = 0;
	while (mask){
		ret ++;
		mask -= mask & -mask;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	ll cnt = 0;
	for (ll i = 0; i < n; i++){
		cin >> type[i];
		if (type[i] == 2){
			string s;
			cin >> s;
			if (!mp.count(s))
				mp[s] = cnt ++;
			a[i] = mp[s];
		}
	}
	for (ll i = 0; i < m; i++){
		ll last = 0, pre = 0;
		for (ll j = 0; j < n; j++){
			if (type[j] == 1){
				last = j;
				pre = 0;
			}
			if (type[j] == 2){
				if (pre and a[j] != i)
					adj[i] |= (1ll << a[j]);
				else if (!pre and a[j] == i){
					pre = 1;
					j = last;
				}
			}
		}
	}
	// mitm
	ll n1 = m / 2;
	for (ll mask = 0; mask < (1 << n1); mask++){
		dp[mask] = cntbit(mask);
		for (ll i = 0; i < n1; i++){
			if (mask & (1 << i)){
				ll submask = mask & adj[i];
				if (submask){
					dp[mask] = 0;
				}
			}
		}
	}
	ll answer = 0;
	for (ll mask = 0; mask < (1 << n1); mask++){
		for (ll i = 0; i < n1; i++){
			if (mask & (1 << i)){
				dp[mask] = max(dp[mask], dp[mask ^ (1 << i)]);
			}
		}
		answer = max(answer, dp[mask]);
	}
	ll n2 = (m + 1) / 2;
	for (ll x = 0; x < (1 << n2); x++){
		ll mask = (x << n1);
		pd[x] = cntbit(mask);
		for (ll i = 0; i < n2; i++){
			if (x & (1 << i)){
				ll submask = mask & adj[n1 + i];
				if (submask){
					pd[x] = 0;
				}
			}
		}
	}
	for (ll mask = 0; mask < (1 << n2); mask++)
		for (ll i = 0; i < n2; i++)
			if (mask & (1 << i))
				pd[mask] = max(pd[mask], pd[mask ^ (1 << i)]);
	for (ll mask = 0; mask < (1 << n2); mask++){
		answer = max(answer, pd[mask]);
		ll ad = 0;
		for (ll i = 0; i < n2; i++)
			if (mask & (1 << i))
				ad |= adj[i + n1];
		ad ^= (1 << n1) - 1;
		for (int i = n2 + n1 - 1; i >= n1; i--)
			if (ad & (1ll << i))
				ad ^= (1ll << i);
		answer = max(answer, pd[mask] + dp[ad]);
	}
	cout << answer << endl;
}