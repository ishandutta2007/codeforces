#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (register int i = a, end = b; i <= end; i++)
#define repd(i, a, b) for (register int i = a, end = b; i >= end; i--)
#define ll long long
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define INF (1<<30)

inline int read() {
	int w = 0, f = 1; char c;
	while (!isdigit(c = getchar())) f = c == '-' ? -1 : f;
	while (isdigit(c)) w = (w << 3) + (w << 1) + (c ^ 48), c = getchar();
	return w * f;
}

int a[5], ans = 0;

void dfs(int i, int A, int B) {
	if (i == 5) {
		if (A == B) ans = 1;
		return;
	}
	dfs(i+1, A+a[i], B);
	dfs(i+1, A, B+a[i]);
}

int main() {
	rep(i, 1, 4) a[i] = read();

	dfs(1, 0, 0);
	printf("%s", ans ? "YES" : "NO");

	return 0;
}