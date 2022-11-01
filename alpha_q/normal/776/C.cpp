#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;
const ll INF = 1e14 + 10;

int n;
ll a[N], k;
set <ll> vals;
map <ll, vector <int>> pos;
vector <ll> powers;

int main (int argc, char const *argv[]) {
	scanf("%d %lld", &n, &k);
	vals.insert(0);
	pos[0].push_back(0);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", a + i);
		a[i] += a[i - 1];
		vals.insert(a[i]);
		pos[a[i]].push_back(i);
	}
	if (abs(k) == 1) {
		powers.push_back(1);
		if (k == -1) powers.push_back(-1);
	} else {
		ll cur = 1;
		while (abs(cur) < INF) {
			powers.push_back(cur);
			cur *= k;
		}
	}
	ll res = 0LL;
	for (int i = 0; i <= n; ++i) {
		ll now = a[i];
		for (ll power : powers) {
			ll sum = now + power;
			if (vals.count(sum)) {
				int idx = lower_bound(pos[sum].begin(), pos[sum].end(), i) - pos[sum].begin();
				res += pos[sum].size() - idx;
			}
		}
	}
	printf("%lld\n", res);
	return 0;
}