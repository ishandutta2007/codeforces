#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

const int N = 1e5 + 5;

ll n, k;
int m;
ll ps[N];

int main() {
	scanf("%lld%d%lld", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%lld", ps + i);
		ps[i]--;
	}
	int p = 0, d = 0, ans = 0, nd = 0;
	while (p < m) {
		ll s = (ps[p + 1] - d) / k * k;
		nd = d;
		while (p < m && (ps[p + 1] - d) < s + k)
			p++, nd++;
		ans++, d = nd;
	}
	printf("%d\n", ans);
	return 0;
}