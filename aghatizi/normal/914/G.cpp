#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxn = (1 << 17) + 20;
const int maxb = 17;
const int N = (1 << maxb);
const int mod = 1e9 + 7;

int dp[4][maxn] , t[4][maxn] , f[maxn] , pd[maxn] , c[30][30] , ans[30];

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int bpw(int a , int b)
{
	if(!b)
		return 1;
	int x = bpw(a , b / 2);

	x = 1LL * x * x % mod;
	if(b&1)
		x = 1LL * x * a % mod;

	return x;
}

void fwht(int* a , int val)
{
	for(int len = 2; len <= N; len *= 2)
		for(int i = 0; i < N; i += len)
		{
			int nxt = len / 2;
			for(int j = 0; j < nxt; j++)
			{
				int x = a[i + j] , y = a[i + j + nxt];
				mkay(a[i + j] = x + y);
				mkay(a[i + j + nxt] = x - y);
			}
		}

	if(val == -1)
	{
		int inv = bpw(N , mod - 2);
		for(int i = 0; i < N; i++)
			a[i] = 1LL * a[i] * inv % mod;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	f[1] = 1;
	for(int i = 2; i < maxn; i++)
		mkay(f[i] = f[i - 1] + f[i - 2]);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		t[1][x]++;
		t[3][x]++;
	}

	for(int mask = 0; mask < N; mask++)
	{
		int tm = N - 1 - mask;
		for(int sm = mask; sm; sm = (sm - 1) & mask)
			mkay(t[2][tm | sm] += 1LL * t[1][tm] * t[1][sm] % mod);

		mkay(t[2][tm | 0] += 1LL * t[1][tm] * t[1][0] % mod);
	}

	fwht(t[3] , 1);
	for(int i = 0; i < N; i++)
		t[3][i] = 1LL * t[3][i] * t[3][i] % mod;
	fwht(t[3] , -1);

	for(int i = 0; i < N; i++)
		for(int j = 1; j <= 3; j++)
			dp[j][i] = 1LL * t[j][i] * f[i] % mod;

	for(int k = 1; k <= 3; k++)
		for(int j = 0; j < maxb; j++)
			for(int i = 0; i < N; i++)
				if(!bit(i , j))
					mkay(dp[k][i] += dp[k][i ^ (1 << j)]);

	for(int mask = 0; mask < N; mask++)
		mkay(ans[__builtin_popcount(mask)] += 1LL * dp[1][mask] * dp[2][mask] % mod * dp[3][mask] % mod);

	for(int i = 0; i < 30; i++)
		for(int j = 0; j <= i; j++)
		{
			if(!j || i == j)
				c[i][j] = 1;
			else
				mkay(c[i][j] = c[i - 1][j] + c[i - 1][j - 1]);
		}

	for(int i = 20; i >= 0; i--)
		for(int j = i + 1; j < 20; j++)
			mkay(ans[i] -= 1LL * ans[j] * c[j][i] % mod);

	cout << ans[1] << endl;
}