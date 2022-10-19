#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
#define MOD 998244353
#define MAXN 100010
typedef long long ll;
pair<int, int> values(int a, int divide) {
	return { a/divide, (a+divide-1)/divide };
}
int n, a[MAXN];
int currentDivide[MAXN];
int pre[MAXN];
void doThing() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	// add elements to the back one at a time
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		// adding an element
		int j = i-1;
		currentDivide[i] = 1;
		pre[i] = i;
		while (j >= 0) {
			int bigger = values(a[j+1], currentDivide[j+1]).first;
			if (values(a[j], currentDivide[j]).second > bigger) {
				int opt = a[j]/bigger;
				while (values(a[j], opt).second > bigger) {
					opt++;
				}

				ll before = j+1;
				ll after = i - pre[j];
				ll am = before*after;
				am %= MOD;
				am *= (currentDivide[j]-1);
				ans += am;
				ans %= MOD;

				currentDivide[j] = opt;
				pre[j] = i;
			} else {
				break;
			}
			j--;
		}
	}
	// now, work out the sum
	for (int i = 0; i < n; i++) {
		ll before = i+1;
		ll after = n - pre[i];
		ll am = before*after;
		am %= MOD;
		am *= (currentDivide[i]-1);
		ans += am;
		ans %= MOD;
	}
	printf("%lld\n", ans);
}
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		doThing();
	}
}