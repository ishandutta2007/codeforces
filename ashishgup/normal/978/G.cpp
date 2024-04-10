#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

struct data
{
	int s, d, c, ind;
};

int n, m;
int ans[N];
data a[N];

bool comp(data &d1, data &d2)
{
	return d1.d<d2.d;
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].s>>a[i].d>>a[i].c;
		ans[a[i].d]=m+1;
		a[i].ind=i;
	}	
	sort(a+1, a+m+1, comp);
	for(int i=1;i<=m;i++)
	{
		int start=a[i].s;
		int reqd=a[i].c;
		for(int j=start;j<a[i].d;j++)
		{
			if(ans[j]>0)
				continue;
			if(reqd==0)
				continue;
			reqd--;
			ans[j]=a[i].ind;
		}
		if(reqd>0)
		{
			cout<<"-1";
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}