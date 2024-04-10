#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, h;

int rsum(int a, int b)
{
	int s1=a*(a-1)/2;
	int s2=b*(b+1)/2;
	return s2-s1;
}

int getsum(int k)
{
	if(k<=h)
	{
		return k*(k+1)/2;
	}
	int sum=k*(k+1)/2;
	sum+=rsum(h, k-1);
	return sum;
}

int check(int k)
{
	int cur=getsum(k);
	return cur<=n;
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi+1)>>1;
		if(check(mid))
			lo=mid;
		else
			hi=mid-1;
	}
	return lo;
}

int32_t main()
{
	IOS;
	cin>>n>>h;
	int k=binsearch(1, 2e9);
	int rem=n - getsum(k);
	int ans=k + max(0LL, k-h) + ((rem+k-1)/k);
	cout<<ans;
	return 0;
}