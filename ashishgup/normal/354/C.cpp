#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e6+5;

int n, k;
int a[N], f[N];

int check(int m)
{
	int no=a[n]/m + 1;
	int cnt=0;
	for(int j=1;j<=no;j++)
	{
		int left=j*m;
		if(left>1e6)
			break;
		int right=min(j*m + k, 1000000);
		cnt+=f[right]-f[left-1];
	}
	if(cnt==n)
		return 1;
	return 0;
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[a[i]]++;
	}
	int ans=1;
	sort(a+1, a+n+1);
	k=min(k, a[1]-1);
	for(int i=1;i<=1e6;i++)
	{
		f[i]+=f[i-1];
	}
	for(int i=1;i<=a[1];i++)
	{
		if(check(i))
			ans=i;
	}
	cout<<ans;
}