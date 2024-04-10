#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (register int i = a, end = b; i <= end; i++)
#define repd(i, a, b) for (register int i = a, end = b; i >= end; i--)
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define INF (1<<30)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define fst first
#define snd second
#define pii pair<int, int>

inline int read() {
    int w = 0, f = 1; char c;
    while (!isdigit(c = getchar())) f = c == '-' ? -1 : f;
    while (isdigit(c)) w = (w << 3) + (w << 1) + (c ^ 48), c = getchar();
    return w * f;
}

int N, M, K, a[40];

void inc(int &a, int b) {
	a += b;
	if (a >= M) a -= M;
}

int Left[(1<<18)+5], Right[(1<<18)+5];

int main() {
	N = read(), M = read();
	rep(i, 1, N) a[i] = read() % M;
	int K = N>>1;
	for (register int S = 0; S < 1<<K; ++S)
		rep(x, 1, K) if (S & (1<<x-1)) inc(Left[S], a[x]);
	for (register int S = 0; S < 1<<N-K; ++S)
		rep(x, K+1, N) if (S & (1<<x-K-1)) inc(Right[S], a[x]);
	sort(Left, Left+(1<<K));
	sort(Right, Right+(1<<N-K));
	int ans = 0;
	for (register int i = 0, j = (1<<N-K) - 1; i < 1 << K; i++) {
		while (~j && Left[i] + Right[j] >= M) j--;
		chkmax(ans, Left[i] + Right[j]);
	}
	printf("%d", ans);

	return 0;
}