#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5e5+5;

int n, cnt=0;
int a[N], ans[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int l=i, r=i+1;
		while(r<=n && a[l]^a[r])
		{
			l++;
			r++;
		}	
		l=i+1;
		r-=2;
		int cur=0;
		while(l<=r)
		{
			a[l]=a[l-1];
			a[r]=a[r+1];
			l++;
			r--;
			cur++;
		}
		cnt=max(cnt, cur);
	}
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
}