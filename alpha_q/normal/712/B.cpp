#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

char s[N];
int n, l, r, u, d;

int main (int argc, char const *argv[]) {
	l = r = u = d = 0;
	scanf("%s", s + 1); n = strlen(s + 1);

	if (n & 1) {
		puts("-1");
		return 0;
	}

	for (int i = 1; i <= n; ++i) {
		if (s[i] == 'L') ++l;
		else if (s[i] == 'R') ++r;
		else if (s[i] == 'U') ++u;
		else ++d;
	}

	if ((u + d) & 1) {
		int avg = (u + d) >> 1;
		if (u > d) --u; else --d;
		int ans = 1 + min(abs(u - avg), abs(d - avg));
		if (l > r) ++r; else ++l;
		avg = (l + r) >> 1;
		ans += min(abs(l - avg), abs(r - avg));
		printf("%d\n", ans);
	} else {
		int avg = (u + d) >> 1;
		int ans = min(abs(u - avg), abs(d - avg));
		avg = (l + r) >> 1;
		ans += min(abs(l - avg), abs(r - avg));
		printf("%d\n", ans);
	}
	return 0;
}

/*

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, a[N], b[N];

int main (int argc, char const *argv[]) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	for (int i = 1; i <= n; ++i) printf("%d ", a[i] + a[i + 1]);
	puts("");
	return 0;
}

*/