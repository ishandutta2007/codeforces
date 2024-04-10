#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int n, bestt, ans=1e9;
int a[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int t=1;t<=100;t++)
	{
		int cur=0;
		for(int i=1;i<=n;i++)
		{
			if(t>a[i]+1)
				cur+=(t-(a[i]+1));
			else if(t<a[i]-1)
				cur+=((a[i]-1)-t);
		}
		if(cur<ans)
		{
			bestt=t;
			ans=cur;
		}
	}
	cout<<bestt<<" "<<ans;
	return 0;
}