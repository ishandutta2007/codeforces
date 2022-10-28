#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m;

int check(int h)
{
	int have=h/2 + h/3 - h/6;
	return (n+m)<=have && h>=3*m && h>=2*n;
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
	cin>>n>>m;
	int ans=binsearch(1, 1e18);
	cout<<ans;
	return 0;    
}