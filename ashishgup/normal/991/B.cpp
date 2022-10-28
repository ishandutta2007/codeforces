#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n";
#define int long long

const int N=105;

int n, sum=0;
int a[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]*=2;
		sum+=a[i];
	}
	sort(a+1, a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(sum>=9*n)
			break;
		sum+=(10-a[i]);
		ans=i;
	}
	cout<<ans;
}