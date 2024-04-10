#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(a[1]!=0)
	{
		cout<<"1";
		return 0;
	}
	int curmax=0;
	for(int i=1;i<=n;i++)
	{	
		if(a[i]>curmax+1)
		{
			cout<<i;
			return 0;
		}
		curmax=max(curmax, a[i]);
	}
	cout<<"-1";
	return 0;
}