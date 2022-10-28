#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, r, avg, total=0, reqd, ans=0;
pair<int, int> a[N]; //b, a

int32_t main()
{
	IOS;
	cin>>n>>r>>avg;
	reqd=avg*n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].second>>a[i].first;
		total+=a[i].second;
	}
	reqd-=total;
	if(reqd<0)
	{
		cout<<0;
		return 0;
	}
	sort(a+1, a+n+1);
	for(int i=1;i<=n;i++)
	{
		int cur=min(reqd, r-a[i].second);
		ans+=cur*a[i].first;
		reqd-=cur;
	}
	cout<<ans;
	return 0;
}