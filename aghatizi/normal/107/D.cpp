#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 123 + 20;
const int maxm = 1e3 + 20;
const int mod = 12345;

struct matrix
{
	int val[maxn][maxn];
	int n;
	matrix(int nn, int x = 0)
	{
		n = nn;
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				if (i != j)
					val[i][j] = 0;
				else
					val[i][j] = x;
	}
	int* operator[] (int x)
	{
		return val[x];
	}
	matrix operator * (matrix b)
	{
		matrix ans(n, 0);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				for(int k=0; k<n; k++)
					ans[i][k] = (ans[i][k] + val[i][j] * b[j][k]) % mod;
		return ans;
	}
	matrix operator + (matrix b)
	{
		matrix ans(n , 0);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				ans[i][j] = (val[i][j] + b[i][j]);
		return ans;
	}
};

matrix operator ^ (matrix a, ll b)
{
	matrix ans(a.n, 1);
	while(b)
	{
		if (b & 1)
			ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}

vector<int> a[maxn];

int shit[maxn] , x[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n;
	int m;
	cin >> n >> m;

	int mul = 1;
	for(int i = 0; i < m; i++)
	{
		char ch;
		cin >> ch >> x[i];
		a[ch - 'A'].pb(i);
		shit[i] = mul;
		mul *= x[i];
	}

	matrix A(mul);
	for(int i = 0; i < mul; i++)
		for(int c = 0; c < 26; c++)
			if(!a[c].empty())
			{
				int tm = i;
				for(auto ind : a[c])
				{
					int tmp = tm % shit[ind];
					tm /= shit[ind];
					tm = tm / x[ind] * x[ind] + (((tm % x[ind]) + 1) % x[ind]);
					tm *= shit[ind];
					tm += tmp;
				}

				A[i][tm]++;
			}

	A = A ^ n;
	int res = 0;
	for(int i = 0; i < mul; i++)
	{
		bool f = 1;
		for(int c = 0; c < 26; c++)
			if(!a[c].empty())
			{
				bool g = 0;
				for(auto ind : a[c])
					if((i / shit[ind]) % x[ind] == 0)
						g = 1;

				f &= g;
			}

		if(f)
			res += A[0][i] , res %= mod;
	}

	cout << res << endl;
}