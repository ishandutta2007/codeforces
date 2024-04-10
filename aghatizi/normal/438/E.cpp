#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int mod = 7 * 17 * (1 << 23) + 1;

int r[maxn];

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

vector<int> operator * (vector<int> a , vector<int> b)
{
	if(a.size() < b.size())
		a.swap(b);

	int N = 1;
	while(N <= (int)a.size())
		N *= 2;

	a.resize(N) , b.resize(N);

	if(N <= 500)
	{
		vector<int> ans;
		ans.resize(N);
		for(int i = 0; i < N / 2; i++)
			for(int j = 0; j < N / 2; j++)
				ans[i + j] = (ans[i + j] + 1LL * a[i] * b[j]) % mod;

		return ans;
	}
	mul(a , 1) , mul(b , 1);
	for(int i = 0; i < N; i++)
		a[i] = 1LL * a[i] * b[i] % mod;
	mul(a , -1);

	return a;
}

vector<int> operator * (vector<int> a , int x)
{
	x = (x % mod + mod) % mod;
	for(auto &y : a)
		y = 1LL * y * x % mod;
	return a;
}

vector<int> operator + (vector<int> a , vector<int> b)
{
	for(int i = 0; i < (int)a.size(); i++)
		a[i] = (a[i] + b[i]) % mod;
	return a;
}

vector<int> inv(vector<int> a)
{
	int N = a.size();
	if(N == 1)
	{
		a[0] = bpw(a[0] , mod - 2);
		return a;
	}

	// 2B - AB^2
	vector<int> b;
	for(int i = 0; i < N / 2; i++)
		b.pb(a[i]);
	b = inv(b);
	b.resize(N);

	a = a * b; a.resize(N);
	a = a * b; a.resize(N);
	return b * 2 + a * -1;
}

vector<int> sqr(vector<int> a)
{
	int N = a.size();
	if(N == 1)
	{
		assert(a[0] == 1 || a[0] == 0);
		return a;
	}

	// b/2 + a/2b
	vector<int> b;
	for(int i = 0; i < N / 2; i++)
		b.pb(a[i]);
	b = sqr(b);
	b.resize(N);

	a = a * inv(b * 2);
	a.resize(N);

	return b * bpw(2 , mod - 2) + a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	int om = m;
	m = 1;
	while(m <= om)
		m *= 2;

	vector<int> c;
	c.resize(m);
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		if(x <= m)
			c[x] = 1;
	}
	c = c * -4;
	c[0] = (c[0] + 1) % mod;
	c = sqr(c);

	c[0] = (c[0] + 1) % mod;
	c = inv(c) * 2;

	for(int i = 1; i <= om; i++)
		cout << c[i] << endl;
}