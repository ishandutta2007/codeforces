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
#define MAXN 200002

int n;
int a[MAXN];
int b[MAXN];
int c[MAXN];
int d[MAXN];
set < pair<int, int> > s;
set <int> w;

int main()
{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif

	scanf("%d", &n);
	int t = int(1e9);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		c[i] = a[i] + b[i];
		s.insert({c[i], i});
	}

	ll ans = 0;
	while(!s.empty()) {
		pair <int, int> p = *s.begin();
		s.erase(s.begin());
		int limit = p.f;
		{
			auto it = w.lower_bound(p.s);
			if (it != w.end()) {
			   int pos = *it;
				limit = min(limit, d[pos] + abs(p.s - pos));
			}
		}
		{
			auto it = w.lower_bound(p.s);
			if (it != w.begin()) {
				--it;
			   int pos = *it;
				limit = min(limit, d[pos] + abs(p.s - pos));
			}
		}
		if (limit < a[p.s]) {
			puts("-1");
			return 0;
		}
		ans += limit - a[p.s];
		d[p.s] = limit;
		w.insert(p.s);
	}

	printf(I64"\n", ans);
	for (int i = 0; i < n; ++i)
		printf("%d%c", d[i], " \n"[i + 1 == n]);

	return 0;
}