
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double
 
const int N = 1e5 + 5;
const int SZ = 128;
 
double add(double a, double b)
{
	return a + b;
}
 
double mult(double a, double b)
{
	return a * b;
}
 
struct matrix
{
	double arr[SZ][SZ];
 
	void reset()
	{
		memset(arr, 0, sizeof(arr));
	}
 
	void makeiden()
	{
		reset();
		for(int i = 0; i < SZ; i++)
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
 
int n, x, sz = 128;
double p[128];
double res[SZ], res2[SZ];
 
int32_t main()
{
	IOS;
	cin >> n >> x;
	for(int i = 0; i <= x; i++)
		cin >> p[i];
	matrix mat;
	mat.reset();
	for(int i = 0; i < sz; i++)
		for(int j = 0; j < sz; j++)
			mat.arr[i][j] = p[i ^ j];
	res[0] = 1;
	matrix expo = power(mat, n);
	matrix ans;
	ans.makeiden();
	ans = ans * expo;
	for(int i = 0; i < SZ; i++)
	{
		res2[i] = 0;
		for(int j = 0; j < SZ; j++)
			res2[i] = add(res2[i], mult(expo.arr[i][j], res[j]));
	}
	for(int i = 0; i < SZ; i++)
		res[i] = res2[i];
	cout << fixed << setprecision(12) << (1 - res[0]);
	return 0;
}