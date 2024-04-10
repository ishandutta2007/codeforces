#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
ll a[200010], b[200010];
int main() {
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; i++) scanf("%lld", a+i);
	ll res = 0;
	for(int i=1; i<=n; i++) {
		ll q = (b[i] + k - 1) / k;
		ll rem = k * q - b[i];
		a[i] -= min(a[i], rem);
		res += q;
		if(i == n) {
			res += (a[i] + k - 1) / k;
		} else b[i+1] = a[i];
	}
	printf("%lld", res);
	return 0;
}