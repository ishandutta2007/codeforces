#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n; ll x, t[N], res[N];

int main (int argc, char const *argv[]) {
	scanf("%d %lld", &n, &x);
	res[1] = 20, --x, t[1] = 1;
	printf("%lld\n", res[1]);
	for (int i = 2; i <= n; ++i) {
		scanf("%lld", t + i);
		t[i] -= x;
		res[i] = res[i - 1] + 20;
		ll z = max(0LL, t[i] - 90);
		int p = upper_bound(t + 1, t + i + 1, z) - t - 1;
		res[i] = min(res[i], 50 + res[p]);	
		z = max(0LL, t[i] - 1440);
		p = upper_bound(t + 1, t + i + 1, z) - t - 1;
		res[i] = min(res[i], 120 + res[p]);
		printf("%lld\n", res[i] - res[i - 1]);
	}
	return 0;
}