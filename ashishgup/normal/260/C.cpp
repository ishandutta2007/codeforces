#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, x, min1=1e9+1;
int a[N];

int32_t main()
{
	IOS;
	cin>>n>>x;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		min1=min(min1, a[i]);
	}
	int ans=min1*n;
	for(int i=0;i<n;i++)
	{
		a[i]-=min1;
	}
	while(true)
	{
		if(a[(x-1+n)%n]==0)
		{
			a[(x-1+n)%n]=ans;
			break;
		}
		x=(x-1+n)%n;
		a[x]--;
		ans++;
	}
	x=(x-1+n)%n;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
 	return 0;
}