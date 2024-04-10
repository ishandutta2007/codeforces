#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define mp(a, b) make_pair(a, b)
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define rep(i, a, b) for (register int i = a, end = b; i <= end; ++i)
#define repd(i, a, b) for (register int i = a, end = b; i >= end; --i)
#define INf (1<<30)

inline int read() {
	int w = 0, f = 1; char c;
	while (!isdigit(c = getchar())) f = c == '-' ? -1 : f;
	while (isdigit(c)) w = (w << 3) + (w << 1) + (c ^ 48), c = getchar();
	return w * f;
}

int n, a, b, x, y;

int main() {
	n = read(), a = read(), x = read(), b = read(), y = read();
	if (a == b) { printf("YES"); return 0; }
	while (a != x && b != y) {
		a = a%n+1, b = (b+n-2)%n+1;
		if (a == b) { printf("YES"); return 0; }
	}
	printf("NO");
	return 0;
}