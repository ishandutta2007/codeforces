#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int m;

int get(int k)
{
	int ct=0, cur=5;
	while(k>=cur)
	{
		ct+=k/cur;
		cur*=5;
	}
	return ct;
}

bool check(int k)
{
	return get(k)>=m;
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
	cin>>m;
	int ans=binsearch(1, 1e18);
	if(get(ans)==m)
	{
		cout<<5<<endl;
		for(int j=0;j<=4;j++)
			cout<<ans+j<<" ";
	}
	else
		cout<<"0";
	return 0;
}