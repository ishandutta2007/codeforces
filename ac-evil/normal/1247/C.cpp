#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (int i = a, end = b; i <= end; i++)
#define repd(i, a, b) for (int i = a, end = b; i >= end; i--)
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define INF (1<<30)

int N, P;

int bit(int x) {
	int res = 0;
	while (x) { res += x & 1, x >>= 1; }
	return res;
}

int main() {
	//freopen("ques.in", "r", stdin);
	//freopen("ques.out", "w", stdout);
	scanf("%d%d", &N, &P);
	rep(i, 0, 30) {
		if (N-i*P < 0) continue;
		if (bit(N-i*P) <= i && i <= N-i*P) { printf("%d", i); return 0; }
	}
	printf("-1");
	return 0;
}