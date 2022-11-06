#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

#define re register
#define rep(i, a, b) for (re int i = a; i <= b; ++i)
#define repd(i, a, b) for (re int i = a; i >= b; --i)
#define For(i, a, b, s) for (re int i = a; i <= b; s)
#define maxx(a, b) a = max(a, b)
#define minn(a, b) a = min(a, b)
#define LL long long
#define INF (1 << 30)

inline int read() {
	int w = 0, f = 1; char c = getchar();
	while (!isdigit(c)) f = c == '-' ? -1 : f, c = getchar();
	while (isdigit(c)) w = (w << 3) + (w << 1) + (c ^ '0'), c = getchar();
	return w * f;
}

int T, s, n, t;

int main() {
	T = read();
	while (T--) {
		n = read(), s = read(), t = read();
		printf("%d\n", max(n-s+1, n-t+1));
	}
	return 0;
}