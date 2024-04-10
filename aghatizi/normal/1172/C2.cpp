#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;
const int maxm = 3e3 + 20;
const int mod = 998244353;

int w[maxn] , like[maxn] , res[maxn] , rev[maxm * 2] , pd[maxm][maxm];

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

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		cin >> like[i];

	int good = 0 , bad = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> w[i];
		if(like[i])
			good += w[i];
		else
			bad += w[i];
	}

	for(int i = -m; i <= m; i++)
		rev[i + maxn] = bpw(i + good + bad , mod - 2);

	for(int i = 0; i <= m; i++)
		for(int j = 0; i + j <= m && j <= bad; j++)
		{
			if(!i && !j)
				pd[i][j] = 1;

			// good
			mkay(pd[i + 1][j] += 1LL * pd[i][j] * (good + i) % mod * rev[i - j + maxn] % mod);
			// bad
			mkay(pd[i][j + 1] += 1LL * pd[i][j] * (bad - j) % mod * rev[i - j + maxn] % mod);
		}

	int tmp = 0 , tmp2 = 0;
	for(int g = 0; g <= m; g++)
	{
		int b = m - g;
		mkay(tmp += 1LL * pd[g][b] * g % mod * bpw(good , mod - 2) % mod);
		mkay(tmp2 -= 1LL * pd[g][b] * b % mod * bpw(bad , mod - 2) % mod);
	}

	for(int i = 0; i < n; i++)
	{
		res[i] = w[i];
		if(like[i])
			mkay(res[i] += 1LL * tmp * w[i] % mod);
		else
			mkay(res[i] += 1LL * tmp2 * w[i] % mod);
		cout << res[i] << endl;
	}

}