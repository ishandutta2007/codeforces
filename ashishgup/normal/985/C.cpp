#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k, l;
int a[N], vis[N];

int32_t main()
{
	IOS;
	cin>>n>>k>>l;
	for(int i=1;i<=n*k;i++)
		cin>>a[i];
	sort(a+1, a+n*k+1);
	int left=upper_bound(a+1, a+n*k+1, l+a[1]) - a - 1;
	int right=n*k;
	int answer=0;
	int barrels=0;
	while(barrels!=n)
	{
		int curmin=1e9+1;
		int ct=0;
		while(ct!=1)
		{
			if(left==0)
			{
				cout<<"0";
				return 0;
			}
			if(vis[left])
			{
				left--;
				continue;
			}
			curmin=min(curmin, a[left]);
			vis[left--]=1;
			ct++;
		}
		ct=0;
		while(ct!=k-1)
		{
			if(right==0)
			{
				cout<<"0";
				return 0;
			}
			if(vis[right])
			{
				right--;
				continue;
			}
			curmin=min(curmin, a[right]);
			vis[right--]=1;
			ct++;
		}
		answer+=curmin;
		barrels++;
	}
	cout<<answer;
	return 0;
}