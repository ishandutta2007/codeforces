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
#define MAXN 2000002
#define MAXV 1000000

int n;
int a[MAXN];
int dif[MAXN];

inline void solve() {
	memset(dif, 0, sizeof(dif));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < i; ++j)
			dif[a[i] - a[j]] = 1;

	vector <int> ans;
	for (int cur = 1; cur < MAXV && sz(ans) < n - 1; ++cur) {
		if (dif[cur]) continue;
		bool ok = 1;
		for (int j = 0; j < sz(ans); ++j) {
			if (dif[cur - ans[j]]) ok = 0;
		}
		if (ok) ans.pb(cur);
	}
	if (sz(ans) != n - 1) {
		puts("NO");
		return;
	}
	puts("YES");
	for (int i = 0; i < n; ++i) {
		printf("%d%c", !i ? 1 : ans[i - 1] + 1, " \n"[i + 1 == n]);
	}
}

int main()
{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif

	int tt;
	scanf("%d", &tt);
	for (int t = 0; t < tt; ++t)
		solve();

	return 0;
}