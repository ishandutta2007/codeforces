#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;
int K;

bool ask(ll l, ll r) {
	printf("%lld %lld\n", l, r);
	fflush(stdout);
	char ans[5];
	scanf("%s", ans);
	return ans[0] == 'Y';
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	
	scanf("%lld%d", &N, &K);
	
	ll lo = 1, hi = N;
	while (1) {
		if (hi - lo > 41) {
			ll mid = (lo + hi) / 2;
			if (ask(lo, mid)) 
				hi = mid;
			else
				lo = mid + 1;
		}
		else {
			ll pos = uniform_int_distribution <ll> (lo, hi)(rng);
			if (ask(pos, pos))
				return 0;
		}
		lo = max(1ll, lo - K);
		hi = min(N, hi + K);
	}
	
	return 0;
}