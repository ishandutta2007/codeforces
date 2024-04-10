#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 32;
const int maxb = 60;
const int mod = 1e9 + 7;
const ll inf = 2e18;

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

struct matrix
{
	int val[maxn][maxn];
	int n;
	matrix(int nn=0, int x = 0)
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
					mkay(ans[i][k] += 1LL * val[i][j] * b[j][k] % mod);
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
	bool operator == (matrix b)
	{
		if(n != b.n)
			return 0;

		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(val[i][j] != b[i][j])
					return 0;
		return 1;
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

int k;

matrix a[maxb] , shift[maxb];

ll val[maxb];

matrix get(ll n , int ind)
{
	if(!n)
		return matrix(k + 1 , 1);

	for(int i = ind; i >= 0; i--)
		if(n >= val[i])
		{
			matrix tmp = get(n % val[i] , i - 1);
			int x = n / val[i];

			matrix ans = a[i];
			for(int j = 1; j < x; j++)
			{
				ans = ans * shift[k - 1];
				ans = ans * a[i];
			}
			ans = ans * shift[k - 1];
			ans = ans * tmp;
			ans = ans * shift[x - 1];
			return ans;
		}

	cout << 1/0 << endl;
	return matrix(k + 1 , -800);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n;
	cin >> n >> k;
	
	val[0] = 1;
	
	int last = maxb;
	for(int i = 1; i < maxb; i++)
	{
		if(val[i - 1] >= inf / k)
		{
		    val[i] = inf;
		    last = i;
		    break;
		}
		else
			val[i] = val[i - 1] * k;
	}

	shift[0] = matrix(k + 1 , 1);
	shift[1] = matrix(k + 1);

	for(int i = 0; i < k; i++)
		shift[1][i][(i - 1 + k) % k] = 1;
	shift[1][k][k] = 1;

	for(int i = 2; i < k; i++)
		shift[i] = shift[i - 1] * shift[1];

	for(int i = 0; i < maxb; i++)
		a[i] = matrix(k + 1 , 1);

	for(int i = 0; i <= k; i++)
		a[0][i][0] = 1;

	for(int i = 1; i < last; i++)
	{
		matrix tmp = a[i - 1];

		a[i] = a[i - 1];

		for(int j = 1; j < k; j++)
		{
			a[i] = a[i] * shift[k - 1];
			a[i] = a[i] * tmp;
		}

		a[i] = a[i] * shift[k - 1];
	}

	matrix ans(k + 1);
	ans[0][k] = 1;

	ans = ans * get(n , last - 1);

	int res = 0;
	for(int i = 0; i <= k; i++)
		mkay(res += ans[0][i]);

	cout << res << endl;
}