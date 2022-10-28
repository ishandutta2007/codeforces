#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, m;
int a[N], f[N], cnt[N];

int32_t main()
{
	IOS;
	cin>>n>>m;	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<=m)
			f[a[i]]++;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;i*j<=m;j++)
			cnt[i*j]+=f[i];
	}
	int lcm=1, kmax=0;
	for(int i=1;i<=m;i++)
	{	
		if(cnt[i]>kmax)
		{
			kmax=cnt[i];
			lcm=i;
		}
	}
	cout<<lcm<<" "<<kmax<<endl;
	for(int i=1;i<=n;i++)
	{
		if(lcm%a[i]==0)
			cout<<i<<" ";
	}
	return 0;
}