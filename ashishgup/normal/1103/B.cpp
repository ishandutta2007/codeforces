#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define endl "\n"
#define int long long

const int N=1e5+5;

int query(int x, int y)
{
	cout<<"? "<<x<<" "<<y<<endl;
	char ch;
	cin>>ch;
	if(ch=='x')
		return 1;
	else if(ch=='e')
		assert(false);
	return 0;
}

pair<int, int> getrange()
{	
	int x=2, y=1;
	while(y<=1e9)
	{
		int cur=query(x, y);
		if(cur==0)
			return {y, x};
		x*=2;
		y*=2;
	}
}


int binsearch(int lo, int hi)
{
	int store=hi;
	while(lo<hi)
	{
		int mid=(lo+hi+1)/2;
		if(query(store, mid)==0)
			lo=mid;
		else
			hi=mid-1;
	}
	return lo+1;
}

int32_t main()
{
	//IOS;
	while(true)
	{
		string s;
		cin>>s;
		if(s=="end")
			break;
		else if(s=="mistake")
			assert(false);
		if(query(0, 1))
		{
			cout<<"! 1"<<endl;
			continue;
		}
		pair<int, int> p = getrange();
		int ans = binsearch(p.first, p.second);
		cout<<"! "<<ans<<endl;
	}
	return 0;
}