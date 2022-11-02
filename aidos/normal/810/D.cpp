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

char c[10];

inline bool ask(int l, int r) {
	printf("1 %d %d\n", l, r);
	fflush(stdout);
	scanf("%s", c);
	return c[0] == 'T';
}

inline int get(int l, int r) {
	if (l > r) return 1;
	while(l < r) {
		int m = (l + r) / 2;
		if (ask(m, m + 1))
			r = m;
		else
			l = m + 1;
	}
	return l;
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int ans1 = get(1, n), ans2;
	int t1 = get(1, ans1 - 1), t2 = get(ans1 + 1, n);
   if (t1 != ans1 && ask(t1, t2)) ans2 = t1; else ans2 = t2;
	printf("2 %d %d\n", ans1, ans2);
	fflush(stdout);
	return 0;
}