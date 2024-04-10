#include <bits/stdc++.h>

using namespace std;

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
#define sz(s) (int(s.size()))
#define fname "a"
#define MAXN 3000003

int n, k;
pair <int, int> a[MAXN];


int main()
{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &a[i].f, &a[i].s);

	sort(a, a + n, [](const pair<int, int>& a, const pair<int, int>& b) {
								return min(a.f * 2, a.s) - min(a.f, a.s) < min(b.f * 2, b.s) - min(b.f, b.s);
						});

	ll ans = 0;
	for (int i = n - 1, j = 0; i >= 0; --i, ++j) {
		if (j < k) a[i].f *= 2;
		ans += min(a[i].f, a[i].s);
	}
	cout << ans << endl;

	return 0;
}