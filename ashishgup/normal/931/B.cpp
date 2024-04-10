#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, a, b;
vector<int> v;

int check()
{
	for(int i=0;i<v.size();i+=2)
	{
		if(v[i]==a&&v[i+1]==b)
		{
		   return 1;
		}
	}
	return 0;
}

int remove()
{
	vector<int> temp;
	for(int i=0;i<v.size();i+=2)
	{
		int x=v[i];
		int y=v[i+1];
		if(x==a)
			temp.push_back(x);
		else if(x==b)
			temp.push_back(x);
		else
			temp.push_back(y);
	}
	v=temp;
}

int32_t main()
{
	IOS;
	cin>>n>>a>>b;
	if(a>b)
		swap(a, b);
	for(int i=1;i<=n;i++)
	{
		v.push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(check())
		{
			if(v.size()==2)
				cout<<"Final!";
			else
				cout<<i;
			return 0;
		}
		remove();
	}
	return 0;
}