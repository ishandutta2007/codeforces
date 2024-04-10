#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

ll W;
ll cnt[10];

void load() {
	scanf("%lld", &W);
	for (int i = 1; i <= 8; i++)
		scanf("%lld", cnt + i);
}

vector <int> gen(vector <pii> v) {
	bitset <1000> dp;
	dp.set(0);
	for (auto it : v) {
		bitset <1000> tmp = dp;
		while (it.second--) {
			tmp <<= it.first;
			dp |= tmp;
		}
	}
	
	vector <int> res;
	for (int i = 0; i < 1000; i++)
		if (dp.test(i))
			res.push_back(i);
	
	return res;
}

ll calc(int x) {
	vector <pii> lft, rig;
	for (int i = 1; i < x; i++)
		lft.push_back({i, min(cnt[i], 7ll)});
		
	ll sum = 0;
	for (int i = x + 1; i <= 8; i++) {
		rig.push_back({i, min(cnt[i], 7ll)});
		sum += cnt[i] * i;
	}
	
	vector <int> L = gen(lft);
	vector <int> R = gen(rig);
	
	ll res = 0;
	for (auto it1 : L)
		for (auto it2 : R) {
			ll tmp = it1 + sum - it2;
			if (tmp > W)
				continue;
			tmp += min(cnt[x], (W - tmp) / x) * x;
			res = max(res, tmp);
		}
	
	return res;
}

ll solve() {
	ll sol = 0;
	for (int i = 1; i <= 8; i++)
		sol = max(sol, calc(i));
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}