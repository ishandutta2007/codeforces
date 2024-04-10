#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3e6+5;

int n, m, total;
int a[N], cnt[N], f[N], ans[N];

int32_t main()
{
	IOS;
	cin>>n;
	total=n*(n-1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[a[i]]++;
	}
	for(int i=1;i<N;i++)
	{
		for(int j=1;i*j<N;j++)
		{
			if(i==j)
				cnt[i*j]+=(f[i]*(f[i]-1));
			else
				cnt[i*j]+=f[i]*f[j];
		}
	}
	for(int i=1;i<N;i++)
		ans[i]=ans[i-1] + cnt[i];
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		cout<<total-ans[x-1]<<endl;
	}
	return 0;
}