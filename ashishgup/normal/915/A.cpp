#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int a[N];

int32_t main() 
{
	IOS;
	int n, k;
	cin>>n>>k;
	int ans=1e9;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(k%a[i]==0)
		{
			ans=min(ans, k/a[i]);
		}
	}
	cout<<ans;
}