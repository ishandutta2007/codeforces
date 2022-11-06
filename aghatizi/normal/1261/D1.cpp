#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

const int N = (1 << 20);
const int maxn = N + 20;
const int mod = 998244353;

int a[maxn];

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

void rev(vector<int> &a)
{
	int N = a.size() , maxb = __builtin_ctz(N);
	for(int i = 0; i < N; i++)
	{
		int k = 0;
		for(int j = 0; j < maxb; j++)
			if((i >> j) & 1)
				k |= (1 << (maxb - 1 - j));

		if(i < k)
			swap(a[i] , a[k]);
	}
}

void mul(vector<int> &a , int val)
{
	int N = a.size();
	assert((N&(-N)) == N);
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , k;
	cin >> n >> k;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	int cnt1 = 0 , cnt2 = 0;
	for(int i = 0; i < n; i++)
	{
		int x = a[i] , y = a[(i + 1) % n];
		if(x == y)
			cnt1++;
		else
			cnt2++;
	}

	if(k == 1)
		return cout << 0 << endl , 0;

	vector<int> shit;
	shit.resize(N);
	shit[0] = 1;
	shit[1] = k - 2;
	shit[2] = 1;
	
	mul(shit , 1);
	for(int i = 0; i < N; i++)
		if(shit[i])
			shit[i] = bpw(shit[i] , cnt2);
	mul(shit , -1);

	int res = 0;
	for(int i = n - cnt1 + 1; i < N; i++)
		res = (res + shit[i]) % mod;

	res = 1LL * res * bpw(k , cnt1) % mod;
	cout << res << endl;
}