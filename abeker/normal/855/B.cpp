#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 100005;
const ll INF = 4e18;

int N, P, Q, R;
int a[MAXN];
ll pref[MAXN], suff[MAXN];

int main() {
	scanf("%d%d%d%d", &N, &P, &Q, &R);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
	
	for (int i = 0; i < N; i++) {
		pref[i] = (ll)P * a[i];
		if (i)
			pref[i] = max(pref[i], pref[i - 1]);
	}
	
	for (int i = N - 1; i >= 0; i--) {
		suff[i] = (ll)R * a[i];
		if (i < N - 1)
			suff[i] = max(suff[i], suff[i + 1]);
	}
	
	ll sol = -INF;
	for (int i = 0; i < N; i++)
		sol = max(sol, pref[i] + suff[i] + (ll)Q * a[i]);
	
	printf("%lld\n", sol);
	
	return 0;
}