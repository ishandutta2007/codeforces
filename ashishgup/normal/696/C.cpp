#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;
const int SZ=3;
const int MOD=1e9+7;

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

int modinv(int k)
{
	return pow(k, MOD-2, MOD);
}

int n, flag=0, cur=1;
int a[N], res[SZ], res2[SZ];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!flag)
		{
			cur*=a[i];
			if(cur>=2)
				flag=1;
		}
	}	
	if(!flag)
	{
		cout<<"0/1";
		return 0;
	}
	matrix ans;
	ans.makeiden();
	matrix mat;
	for(int i=0;i<SZ;i++)
	{
		for(int j=0;j<SZ;j++)
		{
			if(i+j==2)
				mat.arr[i][j]=0;
			else
				mat.arr[i][j]=1;
		}
	}
	res[0]=0;
	res[1]=1;
	res[2]=0;
	int pwden=1;
	matrix temp;
	temp.makeiden();
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)
			continue;
		pwden*=(a[i]%(MOD-1));
		pwden%=(MOD-1);
	}
	matrix expo=power(mat, pwden);
	for(int i=0;i<SZ;i++)
	{
		res2[i]=0;
		for(int j=0;j<SZ;j++)
			res2[i]=add(res2[i], mult(expo.arr[i][j], res[j]));
	}
	for(int i=0;i<SZ;i++)
		res[i]=res2[i];
	int den=pow(2LL, (pwden-1+MOD-1)%(MOD-1), MOD);
	int num=res[1]*modinv(2);
	num%=MOD;
	cout<<num<<"/"<<den;
	return 0;
}