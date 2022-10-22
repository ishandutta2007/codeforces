#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=2e5;
int a[N];
int main()
{
	ios::sync_with_stdio(false);
    int T;
	cin>>T;
	while (T--)
	{   
	    int n,x,y;
		cin>>n>>x>>y;
		int cnt=1;
		a[1]=x;
		int now=n;
		dep(i,n,1)
		{
			now=i;
			if (cnt==n/2) break;
			if (i!=y&&i!=x)
			{
				a[++cnt]=i;
			}
		}
		a[++cnt]=y;
		dep(i,now,1)
		  if (i!=y&&i!=x)
		    a[++cnt]=i;
		int mn=1e9,mx=0; 
		rep(i,1,n/2) mn=min(mn,a[i]);
		rep(i,n/2+1,n) mx=max(mx,a[i]);
		if (mn==x&&mx==y)
		{
			rep(i,1,n) cout<<a[i]<<" ";
			cout<<"\n";
		} else cout<<-1<<endl;
    }
	return 0; 
}