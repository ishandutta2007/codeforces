#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

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

void rev(vector<int> &a , int N)
{
	int maxb = __builtin_ctz(N);
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

void mul(vector<int> &a , int val)
{
	int N = 1;
	while(N <= (int)a.size())
		N *= 2;
	if(val == -1)
		N = a.size();
	while((int)a.size() < N)
		a.pb(0);
	rev(a , N);

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
	int rn = bpw(N , mod - 2);
	if(val == -1)
		for(int i = 0; i < N; i++)
			a[i] = 1LL * a[i] * rn % mod;
}

vector<int> solve(int l , int r)
{
	if(r - l < 2)
	{
		vector<int> ans = {l , 1};
		return ans;
	}
	int m = (l + r) / 2;
	vector<int> a = solve(l , m) , b = solve(m , r);
	while(a.size() < b.size())
		a.pb(0);

	mul(a , 1) , mul(b , 1);
	for(int i = 0; i < (int)a.size(); i++)
		a[i] = 1LL * a[i] * b[i] % mod;
	mul(a , -1);
	return a;
}

int c(int s , int r)
{
	int res = 1;
	for(int i = r + 1; i <= s; i++)
		res = 1LL * res * i % mod;
	for(int i = 1; i <= s - r; i++)
		res = 1LL * res * bpw(i , mod - 2) % mod;

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , x , y;
	cin >> n >> x >> y;

	if(x + y - 2 > n - 1 || !x || !y)
		return cout << 0 << endl , 0;

	if(x + y - 2 == 0)
		return cout << (n == 1) << endl , 0;

	auto ans = solve(0 , n - 1);
	cout << 1LL * ans[x + y - 2] * c(x + y - 2 , x - 1) % mod << endl;
}