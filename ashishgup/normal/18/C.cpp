#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, sum=0;
int a[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	int ans=0, cursum=0;
	for(int i=1;i<=n-1;i++)
	{
		cursum+=a[i];
		if(cursum == sum-cursum)
			ans++;
	}
	cout<<ans;
	return 0;
}