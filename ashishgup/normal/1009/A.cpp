#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;

int n, m, ans=0;
int a[N], b[N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
	int i=1, j=1;
	while(i<=n && j<=m)
	{
		if(b[j]>=a[i])
		{
			i++, j++;
			ans++;
		}
		else
			i++;
	}
	cout<<ans;
	return 0;
}