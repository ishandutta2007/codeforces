#include <bits/stdc++.h>
#define P 1000000007

using namespace std;

typedef long long ll;

ll X[155][155], F[2][155][155], n, m, ans = 0;

int main()
{
	scanf("%lld%lld", &n, &m);
	for(int i = 0; i <= m; i++) X[i][1] = 1;
	for(int i = 1; i <= n; i++) X[1][i] = 1;
	for(int i = 2; i <= m; i++)
		for(int j = 2; j <= n; j++)
			X[i][j] = (X[i][j - 1] + 2 * X[i - 1][j] - X[i - 2][j]) % P;
	for(int i = 0; i <= m; i++)
		for(int j = 1; j <= n; j++)
			X[i][j] = (X[i][j] + X[i][j - 1]) % P;
	for(int T = 1, a = 0, b = 1; T <= n; T++, swap(a, b)) {
		for(int i = 1; i <= m; i++)
			for(int j = 1; j <= m; j++)
				F[a][i][j] = (F[a][i][j] + F[a][i - 1][j] + F[a][i][j - 1] - F[a][i - 1][j - 1]) % P;
		for(int i = 1; i <= m; i++)
			for(int j = i; j <= m; j++)
				F[b][i][j] = (X[j - i][T] + F[a][i][j] - F[a][i][i - 1]) % P;
		for(int i = 1; i <= m; i++)
			for(int j = i; j <= m; j++)
				ans = (ans + F[b][i][j] * X[j - i][n - T + 1]) % P;
	}
	ans = (ans + ans) % P;
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			ans = (ans - (X[i][j] - X[i][j - 1]) * X[i][n + 1 - j] % P * (m - i + 1)) % P;
	return printf("%lld\n", (ans + P) % P), 0;
}