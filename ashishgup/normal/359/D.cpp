#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3e5+5;
const int LG=19;

int n;
int a[N], floorlog[N];
int RMQ[LG][N];

void precompute()
{
	for(int i=0;(1<<i)<N;i++)
	{
		for(int j=(1<<i);j<N && j<(1<<(i+1)); j++)
			floorlog[j]=i;
	}

	for(int i=n;i>=1;i--)
	{
		RMQ[0][i]=a[i]; 
		int mxj=floorlog[n-i+1]; //2^j <= n-i+1
		int pw=1;
		for(int j=1;j<=mxj;j++)
		{
			RMQ[j][i]=__gcd(RMQ[j-1][i], RMQ[j-1][i+pw]);
			pw<<=1;
		}
	}	
}

int getgcd(int L, int R)
{
	int k=floorlog[R-L+1]; //2^k <= R-L+1
	return __gcd(RMQ[k][L], RMQ[k][R - (1<<k) +1]);
}

int check(int L, int R, int val)
{
	int curgcd=getgcd(L, R);
	return ((curgcd%val)==0);
}   

int binsearch1(int lo, int hi, int val)
{
	while(lo<hi)
	{
		int mid=(lo+hi)>>1;
		if(check(mid, hi, val))
			hi=mid;
		else
			lo=mid+1;
	}
	return lo;
}

int binsearch2(int lo, int hi, int val)
{
	while(lo<hi)
	{
		int mid=(lo+hi+1)>>1;
		if(check(lo, mid, val))
			lo=mid;
		else
			hi=mid-1;
	}
	return lo;
}

int getL(int i)
{
	return binsearch1(1, i, a[i]);
}

int getR(int i)
{
	return binsearch2(i, n, a[i]);
}

int32_t main()
{ 
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	precompute();
	int curmax=0;
	set<int> ans;
	for(int i=1;i<=n;i++)
	{
		int l=getL(i);
		int r=getR(i);
		if(r-l>curmax)
		{
			curmax=r-l;
			ans.clear();
			ans.insert(l);
		}
		if(r-l==curmax)
			ans.insert(l);
	}
	cout<<ans.size()<<" "<<curmax<<endl;
	for(auto it:ans)
		cout<<it<<" ";
	return 0;
}