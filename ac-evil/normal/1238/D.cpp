#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF (1<<30)
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define rep(i, a, b) for (register int i = a, end = b; i <= end; ++i)
#define repd(i, a, b) for (register int i = a, end = b; i >= end; --i)

inline ll read() {
	ll w = 0, f = 1; char c;
	while (!isdigit(c = getchar())) f = c == '-' ? -1 : f;
	while (isdigit(c)) w = (w << 3) + (w << 1) + (c ^ 48), c = getchar();
	return w * f;
}

const int maxn = 300000 + 5;

int n;
char str[maxn];
ll ans = 0;

int s[maxn], top = 0, num = -1;

int main() {
	n = read();
	scanf("%s", str);

	rep(i, 0, n-1) {
		int v = 'A' == str[i];
		if (v != num) { s[++top] = 1, num = v; }
		else s[top]++;
	}

	ans = 1ll*n*(n+1)/2;
	rep(i, 1, top) ans -= s[i];
	rep(i, 1, top-1) ans -= s[i] + s[i+1] - 1;

	printf("%lld", ans);


	return 0;
}