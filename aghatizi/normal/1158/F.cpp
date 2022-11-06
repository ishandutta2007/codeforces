#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxn = 3e3 + 20;
const int maxc = 10;
const int maxm = (1 << maxc) + 20;
const int mod = 998244353;

int res[maxn] , dp[maxn][maxn] , pd[2][maxn][maxm] , cnt[maxn] , pw[maxn];
int a[maxn] , inv[maxn];

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
	if(b & 1)
		x = 1LL * x * a % mod;

	return x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	pw[0] = 0;
	for(int i = 1; i < maxn; i++)
	{
		pw[i] = 1LL * (pw[i - 1] + 1) * 2 % mod;
		mkay(pw[i] -= 1);
		inv[i] = 1LL * pw[i] * bpw(pw[i - 1] , mod - 2) % mod;
	}

	int n , c;
	cin >> n >> c;

	for(int i = 1; i <= n; i++)
//		a[i] = i % c;
		cin >> a[i] , a[i]--;

	if(c <= maxc)
	{
		pd[0][0][0] = 1;
		for(int i = 0; i < n; i++)
		{
			int x = (i & 1);
			for(int j = 0; j <= i / c + 3; j++)
				for(int mask = 0; mask < (1 << c); mask++)
					pd[x ^ 1][j][mask] = 0;
			for(int j = 0; j <= i / c; j++)
			{
				for(int mask = 0; mask < (1 << c) - 1; mask++)
				{
					mkay(pd[x ^ 1][j][mask | (1 << a[i + 1])] += pd[x][j][mask]);
					mkay(pd[x ^ 1][j][mask] += pd[x][j][mask]);
				}
				mkay(pd[x ^ 1][j + 1][0] += pd[x ^ 1][j][(1 << c) - 1]);
			}
		}

		for(int j = 0; j <= n; j++)
		{
			int s = 0;
			for(int mask = 0; mask < (1 << c) - 1; mask++)
				mkay(s += pd[n & 1][j][mask]);

			if(!j)
				mkay(s -= 1);
			cout << s << " ";
		}
		cout << endl;
		return 0;
	}

	dp[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		memset(cnt , 0 , sizeof cnt);
		int tmp = c - 1 , shit = 1;
		for(int k = i - 1; k >= 0; k--)
		{
			int x = a[k + 1];
			if(x != a[i])
			{
				cnt[x]++;
				if(cnt[x] == 1)
					tmp--;
				else
					shit = 1LL * shit * inv[cnt[x]] % mod;
			}

			if(!tmp)
				for(int j = 1; j <= k / c + 1; j++)
					dp[i][j] = (dp[i][j] + 1LL * dp[k][j - 1] * shit) % mod;
		}
	}

	for(int i = 0; i <= n; i++)
	{
		memset(cnt , 0 , sizeof cnt);
		for(int k = i + 1; k <= n; k++)
			cnt[a[k]]++;

		int all = pw[n - i];
		mkay(all += 1);

		int bad = 1;
		for(int i = 0; i < c; i++)
			bad = 1LL * bad * pw[cnt[i]] % mod;

		mkay(all -= bad);
		for(int j = 0; j <= i / c; j++)
			mkay(res[j] += 1LL * dp[i][j] * all % mod);
	}

	mkay(res[0] -= 1);
	for(int i = 0; i <= n; i++)
		cout << res[i] << " ";
	cout << endl;
}