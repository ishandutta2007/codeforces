#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int a, b, k;
int sieve[N];

int check(int l)
{
	for(int x=a;x<=b-l+1;x++)
	{
		int ct=sieve[x+l-1]-sieve[x-1];
		if(ct<k)
			return 0;
	}
	return 1;
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)>>1;
		if(check(mid))
			hi=mid;
		else
			lo=mid+1;
	}
	return lo;
}

int32_t main()
{
	IOS;
	cin>>a>>b>>k;
	fill(sieve+2, sieve+N, 1);
	for(int i=2;i<N;i++)
	{
		if(sieve[i])
		{
			for(int j=2;i*j<N;j++)
				sieve[i*j]=0;
		}
	}
	for(int i=2;i<N;i++)
		sieve[i]+=sieve[i-1];
	int ans=binsearch(1, b-a+1);
	if(!check(ans))
		cout<<"-1";
	else
		cout<<ans;
	return 0;
}