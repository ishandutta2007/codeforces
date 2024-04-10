#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5e5 + 5;

int N;
int cnt[2 * MAXN], cum[2 * MAXN];
int prv[2 * MAXN];

void load() {
	scanf("%d", &N);
	while (N--) {
		int len;
		scanf("%d", &len);
		cnt[len]++;
	}
}

int calc(int y) {
	ll sum = 0;
	vector <int> cands;
	for (int i = y - 1; i < MAXN + y; i += y) {
		sum += (ll)(cum[i] - (i == y - 1 ? 0 : cum[i - y])) * (i / y); 
		int mx1 = prv[i];
		if (mx1 > i - y)
			cands.push_back(mx1);
		int mx2 = cnt[mx1] > 1 ? mx1 : prv[mx1 - 1];
		if (mx2 > i - y)
			cands.push_back(mx2);
	}
	
	int lo = 1, hi = MAXN;
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2;
		int opt = -1;
		int opt1 = -1, opt2 = -1;
		for (auto it : cands) {
			if (it >= mid) {
				if (it % y >= opt1 % y) {
					opt2 = opt1;
					opt1 = it;
				}
				else if (it % y > opt2 % y)
					opt2 = it;
			}
			if (it >= 2 * mid && it % y > opt % y)
				opt = it;
		}
		int best = 2 * MAXN;
		if (opt1 != -1 && opt2 != -1) 
			best = min(best, opt1 / y + opt2 / y - (opt1 - mid) / y - (opt2 - mid) / y);
		if (opt != -1)
			best = min(best, opt / y - (opt - 2 * mid) / y);
		if (best < 2 * MAXN && sum - best >= mid)
			lo = mid;
		else
			hi = mid - 1;
	}
	
	return lo > 1 ? lo : 0;
}

ll solve() {
	for (int i = 1; i < 2 * MAXN; i++) {
		prv[i] = cnt[i] ? i : prv[i - 1];
		cum[i] = cum[i - 1] + cnt[i];
	}
	
	ll sol = 0;
	for (int i = 2; i < MAXN; i++)	
		sol = max(sol, (ll)i * calc(i));
		
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}