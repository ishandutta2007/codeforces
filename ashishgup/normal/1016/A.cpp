#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, m;
int a[N], ans[N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cur+=a[i];
		ans[i]=cur/m;
		cur%=m;
		cout<<ans[i]<<" ";
	}
	return 0;
}