#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, temp, ans=0;
int a[N];

int check(int cur)
{
	if(cur%2)
		return (cur*(cur-1)/2 + 1)<=n;
	else
		return (cur*(cur-1)/2 + cur/2)<=n;
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>temp>>a[i];
	sort(a+1, a+m+1);
	reverse(a+1, a+m+1);
	for(int i=1;i<=m;i++)
	{
		if(check(i))
			ans+=a[i];
		else
			break;
	}
	cout<<ans;
	return 0;
}