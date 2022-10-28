#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=2e5+5;

int n, k;
int a[N], idx=1;
double lim=2e18;

int check(int x)
{
	//ways to get from (i, j) to (x, y) is C(x-i+y-j, x-i)
	//ways to get from (1, i) to (x, n) is C(x-1+n-i, x-1)	
	int contrib=1, cur=0;
	for(int i=n;i>=idx;i--)
	{
		if(contrib>=lim)
			return 1;
		double temp=1.0l * contrib * a[i];
		if(temp>=lim)
			return 1;
		cur+=contrib*a[i];
		if(cur>=k)
			return 1;
		double nxt=1.0l * contrib * (x-1+n-(i-1)) / (n-i+1);
		if(nxt>=k)
			contrib=k+1;
		else
		{
			int g=__gcd(contrib, n-i+1);
			contrib/=g;
			int den=n-i+1;
			den/=g;
			int num2=(x-1+n-(i-1));
			g=__gcd(den, num2);
			den/=g;
			num2/=g;
			contrib=contrib*num2;
		}
	}
	return 0;
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)/2;
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
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>=k)
		{
			cout<<0;
			return 0;
		}
	}
	while(a[idx]==0)
		idx++;
	int ans=binsearch(1, 1e18);
	cout<<ans;
	return 0;
}