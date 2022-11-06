#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxb = 19;
const int N = (1 << maxb);
const int maxn = N + 20;
const int mod = 998244353;
const int maxk = 6;

int cnt[maxn] , fac[maxn] , caf[maxn];

int b[maxk] , dp[maxk][maxn] , r[maxn];

int p1[maxn] , p2[maxn];

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

int c(int s , int r)
{
	if(r < 0 || r > s)
		return 0;

	return 1LL * fac[s] * caf[r] % mod * caf[s - r] % mod;
}

void rev(int* a)
{
	for(int i = 0; i < N; i++)
		if(r[i] < i)
			swap(a[r[i]] , a[i]);
}

void mul(int* a , int val)
{
	rev(a);
	for(int len = 2; len <= N; len *= 2)
	{
		int wn = bpw(3 , (mod - 1) / len);
		if(val == -1)
			wn = bpw(wn , mod - 2);

		for(int i = 0; i < N; i += len)
		{
			int nxt = len / 2;
			int pw = 1;
			for(int j = 0; j < nxt; j++)
			{
				int x = (a[i + j] + 1LL * pw * a[i + j + nxt]) % mod;
				int y = (a[i + j] - 1LL * pw * a[i + j + nxt] % mod + mod) % mod;

				a[i + j] = x , a[i + j + nxt] = y;
				pw = 1LL * pw * wn % mod;
			}
		}
	}

	if(val == -1)
	{
		int rN = bpw(N , mod - 2);
		for(int i = 0; i < N; i++)
			a[i] = 1LL * a[i] * rN % mod;
	}
}

void solve(int ind)
{
	int x = 0 , y = 0;
	for(int i = 1; i < b[ind]; i++)
	{
		if(cnt[i] == 1)
			x++;
		else if(cnt[i] > 1)
			y++;
	}

	int tmp = 1;
	for(int i = 0; i < maxn; i++)
	{
		p1[i] = 1LL * c(x , i) * tmp % mod;
		tmp = 2LL * tmp % mod;
	}
	for(int i = 0; i < maxn; i++)
		p2[i] = c(2 * y , i);

	mul(p1 , 1);
	mul(p2 , 1);
	for(int i = 0; i < N; i++)
		p1[i] = 1LL * p1[i] * p2[i] % mod;
	mul(p1 , -1);

	for(int i = 0; i < maxn; i++)
		dp[ind][i] = p1[i];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for(int i = 0; i < N; i++)
	{
		int k = 0;
		for(int j = 0; j < maxb; j++)
			if(bit(i , j))
				k |= (1 << (maxb - j - 1));

		r[i] = k;
	}

	fac[0] = 1;
	for(int i = 1; i < maxn; i++)
		fac[i] = 1LL * fac[i - 1] * i % mod;

	caf[maxn - 1] = bpw(fac[maxn - 1] , mod - 2);
	for(int i = maxn - 1; i > 0; i--)
		caf[i - 1] = 1LL * caf[i] * i % mod;

	int n , k;
	cin >> n >> k;

	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		cnt[x]++;
	}

	for(int i = 0; i < k; i++)
	{
		cin >> b[i];
		solve(i);
	}

	int q;
	cin >> q;

	while(q--)
	{
		int x;
		cin >> x;
		x /= 2;

		int res = 0;
		for(int i = 0; i < k; i++)
			if(x > b[i])
				res = (res + dp[i][x - b[i] - 1]) % mod;

		cout << res << endl;
	}
}