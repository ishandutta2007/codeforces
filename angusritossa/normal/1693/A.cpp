#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
#define MAXN 200010
ll n, a[MAXN];
void solve() {
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	ll pre = 0;
	bool imposs = false;
	bool seen0 = false;
	for (int i = 0; i < n; i++) {
		// a[i] = nx-pre
		ll nx = a[i]+pre;
		pre = nx;
		if (pre < 0) imposs = true;
		if (seen0 && pre != 0) imposs = true;
		if (pre == 0) seen0 = true;
	}
	if (pre != 0) imposs = true;
	if (imposs) printf("NO\n");
	else printf("YES\n");
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
}