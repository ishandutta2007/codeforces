#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = 998244353;
const int maxn = 3600 + 10;

int a[maxn], b[maxn], dp[maxn][maxn], pd[maxn][maxn], fac[maxn], rev[maxn];

int power(int a, int b){
	if (b == 0)
		return 1;
	int ret = power(a, b / 2);
	ret = 1ll * ret * ret % mod;
	if (b & 1)
		ret = 1ll * ret * a % mod;
	return ret;
}

int C(int n, int r){
	if (r > n)
		return 0;
	return 1ll * fac[n] * rev[r] % mod * rev[n-r] % mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	int h, w, n;
	cin >> h >> w >> n;
	for (int i = 0; i < n; i++){
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		a[r1] = a[r2] = 1;
		b[c1] = b[c2] = 1;
	}
	int freea = 0, freeb = 0;
	for (int i = 1; i <= h; i++)
		if (a[i] == 0)
			freea ++;
	for (int i = 1; i <= w; i++)
		if (b[i] == 0)
			freeb ++;

	a[0] = b[0] = 1;
	dp[0][0] = pd[0][0] = 1;
	for (int i = 1; i <= h; i++){
		dp[i][0] = 1;
		for (int j = 1; j * 2 <= i; j++){
			dp[i][j] = dp[i - 1][j];
			if (a[i] == 0 and a[i - 1] == 0)
				dp[i][j] = (dp[i][j] + dp[i - 2][j - 1]) % mod;
		}
	}
	for (int i = 1; i <= w; i++){
		pd[i][0] = 1;
		for (int j = 1; j * 2 <= i; j++){
			pd[i][j] = pd[i - 1][j];
			if (b[i] == 0 and b[i - 1] == 0)
				pd[i][j] = (pd[i][j] + pd[i - 2][j - 1]) % mod;
		}
	}
	int N = 3600;
	fac[0] = 1;
	for (int i = 1; i <= N; i++)
		fac[i] = 1ll * fac[i - 1] * i % mod;
	rev[N] = power(fac[N], mod - 2);
	for (int i = N - 1; i >= 0; i--)
		rev[i] = 1ll * rev[i + 1] * (i + 1) % mod;
	int answer = 0;
	for (int i = 0; i <= h; i++){
		for (int j = 0; j <= w; j++){
			if (i + 2 * j > freea or j + 2 * i > freeb)
				continue;
			int now = 1ll * pd[w][i] * dp[h][j] % mod * C(freea - 2 * j, i) % mod * C(freeb - 2 * i, j) % mod;
			now = 1ll * now * fac[j] % mod * fac[i] % mod;
			answer = (answer + now) % mod;
		}
	}
	cout << answer << endl;
}