
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int SZ = 5;
int MOD = 1e9 + 7;

long long pow(long long a, long long b, long long m)
{
	long long ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

int discreteLog(int a, int b, int m)
{
	a %= m, b %= m;
	if(b == 1)
		return 0;
	int cnt = 0;
	long long t = 1;
	for(int curg=__gcd(a, m);curg!=1;curg=__gcd(a, m))
	{
		if(b % curg)
			return -1;
		b /= curg, m /= curg, t = (t * a / curg) % m;
		cnt++;
		if(b == t)
			return cnt;
	}

	gp_hash_table<int, int> hash;
	int mid = ((int)sqrt(1.0 * m) + 1);
	long long base = b;
	for(int i=0;i<mid;i++)
	{
		hash[base] = i;
		base = base * a % m;
	}

	base = pow(a, mid, m);
	long long cur = t;
	for(int i=1;i<=mid+1;i++)
	{
		cur = cur * base % m;
		auto it = hash.find(cur);
		if(it != hash.end())
			return i * mid - it->second + cnt;
	}
}

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

int res[SZ], res2[SZ];


int32_t main()
{
	IOS;
	int n, f1, f2, f3, c;
	cin >> n >> f1 >> f2 >> f3 >> c;
	c = discreteLog(10, c, MOD);
	f1 = discreteLog(10, f1, MOD);
	f2 = discreteLog(10, f2, MOD);
	f3 = discreteLog(10, f3, MOD);
	MOD--;
	matrix ans;
	ans.makeiden();
	res[0] = f3;
	res[1] = f2;
	res[2] = f1;
	res[3] = (2 * c) % (MOD);
	res[4] = c;
	matrix mat;
	mat.reset();
	mat.arr[0][0] = 1;
	mat.arr[0][1] = 1;
	mat.arr[0][2] = 1;
	mat.arr[0][3] = 1;
	mat.arr[1][0] = 1;
	mat.arr[2][1] = 1;
	mat.arr[3][3] = 1;
	mat.arr[3][4] = 2;
	mat.arr[4][4] = 1;
	matrix expo = power(mat, n - 3);
	ans=ans * expo;
	for(int i = 0; i < SZ; i++)
	{
		res2[i] = 0;
		for(int j = 0; j < SZ; j++)
			res2[i] = add(res2[i], mult(expo.arr[i][j], res[j]));
	}
	for(int i = 0; i < SZ; i++)
		res[i] = res2[i];
	MOD++;
	int answer = res[0];
	answer = pow(10LL, answer, MOD);
	cout << answer;
	return 0;
}