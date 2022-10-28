#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, cur=1;
int a[N], ans[N];

int32_t main()
{
	IOS;
	cin>>n;
	while(cur*2<n)
		cur*=2;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n-1;i++)
	{
		while(i+cur>n)
			cur/=2;
		a[i+cur]+=a[i];
		ans[i]=ans[i-1]+a[i];
		a[i]=0;
		cout<<ans[i]<<endl;
	}
	return 0;
}