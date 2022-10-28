#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=3e4+5;

int n, t;
int a[N];

int32_t main()
{
	IOS;
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int cur=1;
	while(true)
	{
		if(cur==t)
			return cout<<"YES", 0;
		if(cur==n||cur+a[cur]>n)
			break;
		cur+=a[cur];
	}
	cout<<"NO";
}