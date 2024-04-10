#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, l;
int a[N];

int work() //Min cut is max flow
{
	int ans=0;
	for(int i=1;i<=l;i++)
		ans+=a[i];
	int cur=ans;
	for(int i=l+1;i<=n;i++)
	{
		cur+=a[i];
		cur-=a[i-l];
		ans=min(cur, ans);
	}
	return ans;
}	

int32_t main()
{
	IOS;
	cin>>n>>l;
	n--;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<work();
	return 0;
}