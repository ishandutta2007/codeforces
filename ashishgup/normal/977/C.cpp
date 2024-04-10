#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, k;
int a[N];

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1, a+n+1);
	if(a[k]==a[k+1])
	{
		cout<<"-1";
		return 0;
	}
	if(k==0)
	{
		if(a[1]==1)
		{
			cout<<"-1";
			return 0;
		}
		cout<<"1";
		return 0;
	}
	cout<<a[k];
	return 0;
}