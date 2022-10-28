#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int SZ = 105;
const int MOD = 1e9 + 7;
 
int add(int a, int b)
{
	int res = a + b;
	if(res >= MOD)
		return res - MOD;
	return res;
}
 
int mult(int a, int b)
{
	long long res = a;
	res *= b;
	if(res >= MOD)
		return res % MOD;
	return res;
}
 
struct matrix
{
	int arr[SZ][SZ];
 
	void reset()
	{
		memset(arr, 0, sizeof(arr));
	}
 
	void makeiden()
	{
		reset();
		for(int i=0;i<SZ;i++)
		{
			arr[i][i] = 1;
		}
	}
 
	matrix operator + (const matrix &o) const 
	{
		matrix res;
		for(int i=0;i<SZ;i++)
		{
			for(int j=0;j<SZ;j++)
			{
				res.arr[i][j] = add(arr[i][j], o.arr[i][j]);
			}
		}
		return res;
	}
 
	matrix operator * (const matrix &o) const 
	{
		matrix res;
		for(int i=0;i<SZ;i++)
		{
			for(int j=0;j<SZ;j++)
			{
				res.arr[i][j] = 0;
				for(int k=0;k<SZ;k++)
				{
					res.arr[i][j] = add(res.arr[i][j] , mult(arr[i][k] , o.arr[k][j]));
				}
			}
		}
		return res;
	}
};
 
matrix power(matrix a, int b)
{
	matrix res;
	res.makeiden();
	while(b)
	{
		if(b & 1)
		{
			res = res * a;
		}
		a = a * a;
		b >>= 1;
	}
	return res;
}
 
const int N = 1e5 + 5;
 
int n, x;
int d[N], f[N], cache[N];
int res[SZ], res2[SZ];
 
int dp(int x)
{
	if(x < 0)
		return 0;
	if(x == 0)
		return 1;
	int &ans = cache[x];
	if(ans != -1)
		return ans;
	ans = 0;
	for(int i = 1; i <= 100; i++)
	{
		ans += f[i] * dp(x - i);
		ans %= MOD;
	}
	return ans;
}
 
int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n >> x;
	if(x == 0)
	{
		cout << 1;
		return 0;
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> d[i];
		f[d[i]]++;
	}
	if(x <= 100)
	{
		int sum = 0;
		for(int i = 0; i <= x; i++)
			sum += dp(i);
		sum %= MOD;
		cout << sum;
		return 0;
	}
	int g = 0;
	for(int i = 0; i <= 100; i++)
		g += dp(i);
	g %= MOD;
	for(int i = 0; i <= 100; i++)
		res[i] = dp(100 - i);
	res[101] = g;
	matrix mat;
	mat.reset();
	for(int i = 0; i < 100; i++)
		mat.arr[0][i] = f[i + 1];
	for(int i = 1; i <= 100; i++)
		mat.arr[i][i - 1] = 1;
	for(int i = 0; i < 100; i++)
		mat.arr[101][i] = f[i + 1];
	mat.arr[101][101] = 1;
	matrix expo = power(mat, x - 100);
	matrix ans;
	ans.makeiden();
	ans = ans * expo;
	for(int i = 0;i < SZ; i++)
	{
		res2[i] = 0;
		for(int j = 0;j < SZ; j++)
			res2[i]=add(res2[i], mult(expo.arr[i][j], res[j]));
	}
	for(int i=0;i<SZ;i++)
		res[i] = res2[i];
	cout << res[101];
	return 0;
}