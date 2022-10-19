#include<bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 1000000007;

int minp[100005];

ll ans = 1, m, invm;

ll sub(ll x, ll y) {
	return (x - y + MOD) % MOD; 
}

ll muli(ll x, ll y) {
	return (x * y) % MOD;
}

ll power(ll x, ll y) {
	if (y == 0) return 1; 
	ll tmp = power(x, y / 2);
	if (y % 2) {
		return muli(tmp, muli(tmp, x));
	} else {
		return muli(tmp, tmp);
	}
}

ll inv(ll x) {
	return power(x, MOD - 2);
}

void calc(int x) {
	int cnt = 0;
	int mmr = x;
	while(x != 1) {
		if (minp[x / minp[x]] == minp[x]) return;
		cnt++;
		x /= minp[x];
	}
	ll t = muli(m / mmr, invm);
	if (cnt % 2 == 0) {
		ans = sub(ans, muli(t, inv(sub(1, t))));
	} else {
		ans = (ans + muli(t, inv(sub(1, t)))) % MOD;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> m;
	for (int i = 2; i * i <= m; ++i) {
	    if (minp[i] == 0) { //if i is prime
	        for (int j = i * i; j <= m; j += i) {
	            if (minp[j] == 0) {
	                minp[j] = i;
	            }
	        }
	    }
	}
	for (int i = 2; i <= m; ++i) {
	    if (minp[i] == 0) {
	        minp[i] = i;
	    }
	}

	invm = inv(m);
	for (int i = 2; i <= m; i++) {
		calc(i);
	}
	cout << ans;
	return 0;
}