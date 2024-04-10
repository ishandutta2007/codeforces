#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n=4;
vector<int> v(4);

int32_t main()
{
	IOS;
	for(int i=0;i<n;i++)	
		cin>>v[i];
	sort(v.begin(), v.end());
	for(int i=2;i<n;i++)
	{
		if(v[i]<v[i-1]+v[i-2])
		{
			cout<<"TRIANGLE";
			return 0;
		}
	}
	for(int i=2;i<n;i++)
	{
		if(v[i]==v[i-1]+v[i-2])
		{
			cout<<"SEGMENT";
			return 0;
		}
	}
	cout<<"IMPOSSIBLE";
	return 0;
}