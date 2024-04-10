#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, sum=0, reqd=0, ans=0;
int a[N];
queue<int> g, l;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	reqd=sum/n;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==reqd)
			continue;
		if(a[i]<reqd)
		{
			while(a[i]<reqd && !g.empty())
			{	
				int idx=g.front();
				int extra=a[idx]-reqd;
				int needed=reqd-a[i];
				int take=min(extra, needed);
				a[idx]-=take;
				a[i]+=take;
				ans+=take*(i-idx);
				if(a[idx]==reqd)
					g.pop();
			}
			if(a[i]<reqd)
				l.push(i);
		}
		else
		{
			while(a[i]>reqd && !l.empty())
			{	
				int idx=l.front();
				int needed=reqd-a[idx];
				int extra=a[i]-reqd;
				int take=min(extra, needed);
				a[idx]+=take;
				a[i]-=take;
				ans+=take*(i-idx);
				if(a[idx]==reqd)
					l.pop();
			}
			if(a[i]>reqd)
				g.push(i);
		}
	}
	cout<<ans;
	return 0;
}