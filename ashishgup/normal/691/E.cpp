#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;
const int SZ=105;

int MOD=1e9+7;

int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
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

int n, k, answer=0;
int a[N];
int res[SZ], res2[SZ];

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i], res[i]=1;
	matrix ans;
	ans.makeiden();
	matrix mat;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(__builtin_popcountll(a[i]^a[j])%3==0)
				mat.arr[i][j]=1;
	matrix expo=power(mat, k-1);
	ans = ans * expo;
	for(int i=0;i<SZ;i++)
	{
		res2[i]=0;
		for(int j=0;j<SZ;j++)
			res2[i]=add(res2[i], mult(expo.arr[i][j], res[j]));
	}
	for(int i=0;i<SZ;i++)
	{
		res[i]=res2[i];
		answer+=res[i];
	}
	answer%=MOD;
	cout<<answer;
	return 0;
}