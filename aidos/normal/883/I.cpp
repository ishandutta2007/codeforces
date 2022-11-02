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
#define MAXN 500005

int n, k;
int a[MAXN];
set <int> s;

inline bool can(int X) {
	s.clear();
	s.insert(-1);
	for (int i = 0, j = 0; i < n; ++i) {
		while(j < i && a[i] - a[j] > X) ++j;
		int kk = i - k + 1;
		if (j > kk) continue;
		auto it = s.lower_bound(j - 1);
		if (it != s.end() && *it < kk) {
			s.insert(i);
		}
	}
	return sz(s) >= 1 && *(--s.end()) == n - 1;
}

int main()
{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n);

	int l = -1, r = int(1e9) + 1;
	while(l + 1 < r) {
		int m = (l + r) / 2;
		if (!can(m))
			l = m;
		else
			r = m;
	}
	printf("%d\n", r);

	return 0;
}