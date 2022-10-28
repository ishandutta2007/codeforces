#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;
const int INF=1e15;

int m, k;
int nCr[105][105];

void preprocess()
{
	nCr[0][0]=1;
	for(int i=1;i<=100;i++)
	{
		nCr[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			nCr[i][j]=nCr[i-1][j]+nCr[i-1][j-1];
		}
	}
}
	
int f(int n)
{	
	int ans=0;
	int current=0;
	for(int i=62;i>=0;i--)
	{
		if(n&(1LL<<i))
		{
			int rem_bits=i;
			int needed_ones=k-current;
			if(needed_ones>=0)
			{
				ans+=nCr[rem_bits][needed_ones];
			}
			current++;
		}
	}
	if(current==k)
		ans++;
	return ans;
}

int check(int n)
{
	int calc=f(2*n)-f(n); //f(l, r) = f(r) - f(l-1);
	if(calc>=m)
		return 1;
	return 0;
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)>>1;
		if(check(mid))
		{
			hi=mid;
		}
		else
		{
			lo=mid+1;
		}
	}
	return lo;
}

int32_t main()
{
	IOS;
	preprocess();
	cin>>m>>k;
	int ans=binsearch(1, 1e18);
	cout<<ans;
	return 0;
}