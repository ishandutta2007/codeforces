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
#define MOD 1000000007
#define MAXN 3000003

inline int add(int a, int b) {
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}

inline int sub(int a, int b) {
	a -= b;
	if (a < 0)
		a += MOD;
	return a;
}

inline int mult(int a, int b) {
	return (1LL * a * b) % MOD;
}

int n;
int a[MAXN];
int p2[MAXN];

int main()
{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif

	p2[0] = 1;
	for (int i = 1; i < MAXN; ++i)
		p2[i] = add(p2[i - 1], p2[i - 1]);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	sort(a, a + n);
	
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = add(ans, mult(p2[i], a[i]));
		ans = sub(ans, mult(p2[n - i - 1], a[i]));
	}

	printf("%d\n", ans);
		
	return 0;
}