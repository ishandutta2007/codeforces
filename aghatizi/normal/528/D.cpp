#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxb = 18;
const int N = (1 << maxb);
const int maxn = N + 20;
const int mod = 998244353;

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

void rev(int* a)
{
	for(int i = 0; i < N; i++)
	{
		int k = 0;
		for(int j = 0; j < maxb; j++)
			if(bit(i , j))
				k |= 1 << (maxb - 1 - j);

		if(i < k)
			swap(a[i] , a[k]);
	}
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
			int nxt = len / 2 , pw = 1;
			for(int j = 0; j < nxt; j++)
			{
				int x = a[i + j] , y = a[i + j + nxt];
				a[i + j] = (x + 1LL * pw * y) % mod;
				a[i + j + nxt] = (x - 1LL * pw * y % mod + mod) % mod;
				pw = 1LL * pw * wn % mod;
			}
		}
	}

	if(val == -1)
	{
		int inv = bpw(N , mod - 2);
		for(int i = 0; i < N; i++)
			a[i] = 1LL * a[i] * inv % mod;
	}
}

int c[300] , a[maxn] , b[maxn] , ans[maxn];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	c['A'] = 0 , c['T'] = 1 , c['C'] = 2 , c['G'] = 3;

	int n , m , k;
	string s , t;
	cin >> n >> m >> k >> s >> t;
	k++;

	for(auto &ch : s)
		ch = c[ch];
	for(auto &ch : t)
		ch = c[ch];

	for(int x = 0; x < 4; x++)
	{
		memset(a , 0 , sizeof a);
		memset(b , 0 , sizeof b);
		int sum = 0;
		for(int i = 0; i < n; i++)
		{
			sum += (s[i] == x);
			if(i - k >= 0)
				sum -= (s[i - k] == x);

			a[i] |= (sum > 0);
		}

		sum = 0;
		for(int i = n - 1; i >= 0; i--)
		{
			sum += (s[i] == x);
			if(i + k < n)
				sum -= (s[i + k] == x);

			a[i] |= (sum > 0);
		}

		for(int i = 0; i < m; i++)
			b[i] = (t[i] == x);
		reverse(b , b + m);

		mul(a , 1);
		mul(b , 1);
		for(int i = 0; i < N; i++)
			a[i] = 1LL * a[i] * b[i] % mod;
		mul(a , -1);

		for(int i = m - 1; i < n; i++)
			ans[i] += a[i];
	}

	int res = 0;
	for(int i = m - 1; i < n; i++)
		res += (ans[i] == m);

	cout << res << endl;
}