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

int n, k;
int s;
int a[111];

inline bool can(int x) {
	return ((1.0 * x * k + s) / (n + x) + 0.5) >= k;
}

int main()
{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		s += a[i];
	}

	int l = -1, r = int(1e9);
	while(l + 1 < r) {
		int m = (l + r) / 2;
		if (can(m))
			r = m;
		else
			l = m;
	}

	printf("%d\n", r);

	return 0;
}