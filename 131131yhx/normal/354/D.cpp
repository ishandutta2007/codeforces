#include <bits/stdc++.h>
#define int long long
#define M 100010

using namespace std;

typedef long long ll;

const int C = 780;

int Dp[2][C + 10], n, m, X[M], Y[M], tmp[M], S[C + 10], a = 0, b = 1;

bool cmp(int x, int y) {return Y[x] < Y[y] || Y[x] == Y[y] && X[x] > X[y];}

void cmin(int& x, int y) {if(x > y) x = y;}

#undef int
int main()
#define int long long
{
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= m; i++) scanf("%lld%lld", &X[i], &Y[i]), X[i] = n - X[i] + 1, tmp[i] = i;
	sort(tmp + 1, tmp + m + 1, cmp);
	memset(Dp, 63, sizeof Dp), Dp[a][0] = 0;
	for(int T = 1, t = 1; T <= n; T++, swap(a, b)) {
		memset(Dp[b], 63, sizeof Dp[b]), memset(S, 0, sizeof S);
		while(t <= m && Y[tmp[t]] == T) S[min(X[tmp[t++]], C + 1) - 1]++;
		for(int i = C; i >= 0; i--) S[i] += S[i + 1];
		for(int i = 0; i <= C; i++) Dp[b][i] = Dp[a][i + 1] + 3 * S[i];
		cmin(Dp[b][0], Dp[a][0] + 3 * S[0]);
		for(int i = 1; i <= C; i++) cmin(Dp[a][i], Dp[a][i - 1]);
		for(int i = 1; i <= C; i++) cmin(Dp[b][i], Dp[a][i] + 2 + 3 * S[i] + i * (i + 1) / 2);
	}
	return printf("%lld\n", min(Dp[a][1], Dp[a][0])), 0;
}