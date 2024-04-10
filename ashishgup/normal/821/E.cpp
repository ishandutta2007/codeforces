#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int SZ=16;
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

int n, k;
int block[SZ], res[SZ], res2[SZ];
map<int, vector<pair<int, int> > > events;

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int l, r, a;
		cin>>l>>r>>a;
		events[l-1].push_back({a, 1});
		events[min(r, k)].push_back({a, -1});
	}
	matrix ans;
	int prev=-1;
	ans.makeiden();
	res[0]=1;
	for(auto it:events)
	{
		int cur=it.first;
		matrix mat;
		for(int i=0;i<SZ;i++)
		{
			for(int j=0;j<SZ;j++)
			{
				if(block[i]==0 && abs(i-j)<=1)
					mat.arr[i][j]=1;
				else
					mat.arr[i][j]=0;
			}
		}
		matrix expo=power(mat, cur-prev);
		ans=ans * expo;
		for(int i=0;i<SZ;i++)
		{
			res2[i]=0;
			for(int j=0;j<SZ;j++)
				res2[i]=add(res2[i], mult(expo.arr[i][j], res[j]));
		}
		for(int i=0;i<SZ;i++)
			res[i]=res2[i];
		for(auto x:it.second)
		{
			int a=x.first;
			if(x.second<0)
			{
				for(int j=a+1;j<SZ;j++)
					block[j]--;
			}
			else
			{
				for(int j=a+1;j<SZ;j++)
					block[j]++;
			}
		}
		prev=cur;
		prev=max(prev, 0LL);
	}
	//Final multiplication matrix is ans
	//Res stores the answer after every event
	cout<<res[0];
}