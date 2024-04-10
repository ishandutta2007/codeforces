#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n;
int a[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	a[n+1]=90;
	for(int i=1;i<=n+1;i++)
	{
		if(a[i]-a[i-1]>15)
		{
			cout<<a[i-1]+15;
			return 0;
		}
	}
	cout<<90;
	return 0;
}