#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n=3, ans=0;
int a[5];

int32_t main()
{
	IOS;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=a[1];i++)
	{
		if(a[2]>=i+1 && a[3]>=i+2)
			ans=3*i+3;
		else
			break;
	}
	cout<<ans;
	return 0;
}