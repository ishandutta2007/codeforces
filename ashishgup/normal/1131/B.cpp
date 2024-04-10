#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, ans=0, cur=0;
int a[N], b[N];
int curl=0;

int get(int l1, int r1, int l2, int r2)
{
	int l=max(l1, l2);
	l=max(l, curl);
	int r=min(r1, r2);
	if(r<l)
		return 0;
	curl=r+1;
	return r-l+1;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		int l1=a[i-1], r1=a[i];
		int l2=b[i-1], r2=b[i];
		ans+=get(l1, r1, l2, r2);
	}
	cout<<ans;
	return 0;
}