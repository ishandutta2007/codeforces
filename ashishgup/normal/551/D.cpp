#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;
const int SZ=3;

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
int n, k, l, m;
int res[SZ], res2[SZ];

int32_t main()
{
	IOS;
	cin>>n>>k>>l>>m;
	MOD=m;
	if(l<=60 && k>=(1LL<<l))
	{
		cout<<"0";
		return 0;
	}
	int ones=__builtin_popcountll(k);
	int zeroes=l-ones;
	matrix ans;
	ans.makeiden();
	res[0]=1, res[1]=0, res[2]=1;
	matrix mat;
	mat.arr[0][0]=1, mat.arr[0][1]=1, mat.arr[0][2]=2;
	mat.arr[1][0]=1, mat.arr[1][1]=0, mat.arr[1][2]=0;
	mat.arr[2][0]=0, mat.arr[2][1]=0, mat.arr[2][2]=2;
	matrix expo=power(mat, n-2);
	ans = ans * expo;
	for(int i=0;i<SZ;i++)
	{
		res2[i]=0;
		for(int j=0;j<SZ;j++)
			res2[i]=add(res2[i], mult(expo.arr[i][j], res[j]));
	}
	for(int i=0;i<SZ;i++)
		res[i]=res2[i];
	int ways1=res[0];
	int ways0=pow(2LL, n, MOD) - ways1 + MOD;
	ways0%=MOD;
	int answer=pow(ways1, ones, MOD) * pow(ways0, zeroes, MOD);
	answer%=MOD;
	cout<<answer;
	return 0;
}