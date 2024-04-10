#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 100005;
const ll INF = (ll)1e18;

int N;
int a[MAXN];
ll pref[MAXN];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
	
	for (int i = 1; i < N; i++)
		a[i] = abs(a[i] - a[i + 1]);	
	
	for (int i = 1; i < N; i++)
		pref[i] = pref[i - 1] + (i % 2 ? a[i] : -a[i]);
	
	ll mx = -INF, mn = 0;
	ll sol = 0;
	for (int i = 1; i < N; i++) {
		sol = max(sol, max(pref[i] - mn, mx - pref[i]));
		if (i % 2)
			mx = max(mx, pref[i]);
		else
			mn = min(mn, pref[i]);
	}
	
	printf("%lld\n", sol);
	
	return 0;
}