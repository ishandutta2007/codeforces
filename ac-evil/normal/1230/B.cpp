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
inline int get() {
	char c;
	while (!isdigit(c = getchar()));
	return c^48;
}

const int maxn = 200000 + 5;

int N, K;
int s[maxn];

int main() {
	N = read(), K = read();
	rep(i, 1, N) s[i] = get();
	int pt = 1;
	if (K) {
		if (N == 1) s[1] = 0;
		else {
			if (s[1] != 1) { s[pt] = 1; K--; }
			pt++;
			for (; pt <= N; pt++) {
				if (!K) break;
				if (s[pt]) s[pt] = 0, K--;
			}
		}
	}
	rep(i, 1, N) printf("%d", s[i]);

	return 0;
}