#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int a[5];

int32_t main()
{
	IOS;
	cin>>a[1]>>a[2]>>a[3];
	sort(a+1, a+4);
	int ans=0;
	int cur=a[1];
	for(int i=0;i<=a[2]-1;i++)
	{
		ans+=cur*2;
		if(i==a[2]-1)
			ans-=cur;
		cur++;
	}
	cur-=1;
	ans+=cur*(a[3]-a[2]);
	cout<<ans;
	return 0;
}