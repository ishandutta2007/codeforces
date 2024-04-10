#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
int a[N], b[N];
set<int> s;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		cin>>b[i];
		b[i] += b[i-1];
		s.insert(b[i]);
	}
	if(s.size() != n-1)
		cout<<"-1";
	else
	{
		int pos = 0, neg = 0;
		for(auto &it:s)
		{
			pos += (it > 0);
			neg += (it < 0);
			if(it == 0)
			{
				cout<<"-1";
				return 0;
			}
		}
		int element = 1 + neg;
		set<int> reqd;
		for(int i=1;i<=n;i++)
			reqd.insert(i);
		a[1] = element;
		for(int i=2;i<=n;i++)
			a[i] = element + b[i - 1];
		for(int i=1;i<=n;i++)
		{
			if(reqd.find(a[i]) == reqd.end())
			{
				cout<<"-1";
				return 0;
			}
			reqd.erase(a[i]);
		}
		for(int i=1;i<=n;i++)
			cout<<a[i]<<" ";
	}
	return 0;	
}