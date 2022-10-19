#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 110
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
bool cant[MAXN];
ll val[MAXN];
vector<ll> fib;
vector<ll> pre;
int main() {
	int t;
	scanf("%d", &t);
	fib.push_back(1);
	fib.push_back(1);
	while (1) {
		ll v = fib[fib.size()-1] + fib[fib.size()-2];
		fib.push_back(v);
		if (v > 1e9) break;
	}
	ll s = 0;
	for (int i = 0; i < fib.size(); i++) {
		s += fib[i];
		pre.push_back(s);
	}
	for (int CASE = 0;  CASE < t; CASE++) {
		int n;
		scanf("%d", &n);
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lld", &val[i]);
			sum += val[i];
		}
		int choice = -1;
		for (int i = 0; i < fib.size(); i++) {
			if (sum == pre[i]) {
				choice = i;
			}
		}
		if (choice == -1) {
			printf("No\n");
			continue;
		}
		bool fail = false;
		fill_n(cant, MAXN, false);

		for (int i = choice; i >= 0; i--) {
			pair<ll, int> best = { -1, -1 };
			for (int j = 0; j < n; j++) {
				if (!cant[j]) {
					best = max(best, {val[j], j});
				}
				cant[j] = false;
			}
			//D("%lld %d %d\n", best.first, best.second, fib[i]);
			if (best.first < fib[i]) {
				fail = true;
				break;
			}
			val[best.second] -= fib[i];
			cant[best.second] = true;
		}
		if (!fail) printf("YES\n");
		else printf("NO\n");

	}
}