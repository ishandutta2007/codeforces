#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxb = 20;
const int N = (1 << maxb);
const int maxn = (1 << maxb) + 20;
const int prime[2] = {1004535809 , 998244353};
int mod;

bool is[maxn];
int a[maxn] , cnt[maxn];

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
				k |= 1 << (maxb - j - 1);

		if(i < k)
			swap(a[k] , a[i]);
	}
}

void mul(int* a , int val)
{
	rev(a);
	for(int eq = 2; eq <= N; eq *= 2)
	{
		int wn = bpw(3 , (mod - 1) / eq);
		assert(bpw(wn , eq) == 1);
		if(val == -1)
			wn = bpw(wn , mod - 2);

		for(int i = 0; i < N; i += eq)
		{
			int nxt = eq >> 1;
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
		for(int i = 0; i < N; i++)
			a[i] = 1LL * a[i] * bpw(N , mod - 2) % mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , k;
	cin >> n >> k;

	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		is[x] = 1;
	}

	for(int _ = 0; _ < 2; _++)
	{
		mod = prime[_];
		for(int i = 0; i < N; i++)
			a[i] = is[i];

		mul(a , 1);
		for(int i = 0; i < N; i++)
			a[i] = bpw(a[i] , k);

		mul(a , -1);
		for(int i = 0; i < N; i++)
			cnt[i] += (a[i] == 0);
	}

	for(int i = 0; i < N; i++)
		if(cnt[i] != 2)
			cout << i << " ";
	cout << endl;
}