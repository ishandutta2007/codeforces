#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int N;
int par[MAXN], dep[MAXN];
int sum[MAXN], up[MAXN];
int a[MAXN];

int main() {
	scanf("%d", &N);
	dep[1] = 1;
	for (int i = 2; i <= N; i++) {
		scanf("%d", par + i);
		assert(par[i] < i);
		dep[i] = dep[par[i]] ^ 1;
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", sum + i);
		assert((sum[i] == -1) ^ dep[i]);
	}
	
	ll ans = 0;
	memset(a, INF, sizeof a);
	for (int i = 1; i <= N; i++) 
		if (dep[i]) {
			up[i] = sum[i] - sum[par[par[i]]];
			if (up[i] < 0) {
				puts("-1");
				return 0;
			}
			a[par[i]] = min(a[par[i]], up[i]);
			ans += up[i];
		}
	
	for (int i = 2; i <= N; i++)
		if (dep[i])
			ans -= a[par[i]];
		else if (a[i] < INF)
			ans += a[i];
	
	printf("%lld\n", ans);
	
	return 0;
}