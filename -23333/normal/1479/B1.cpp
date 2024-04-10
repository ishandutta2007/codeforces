#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define me(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
const int N=2e5;
int a[N];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int c=0,d=0,ans=0;
	rep(i,1,n) cin>>a[i];
	rep(i,1,n)
	{
		if (a[i]==c)
		{
			if (a[i]!=d) ans++;
			d=a[i];
		} else
		if (a[i]==d)
		{
			if(a[i]!=c) ans++;
			c=a[i];
		} else
		{
			if (c==a[i+1]) c=a[i]; else d=a[i];
			ans++;
		}
	}
	cout<<ans<<endl;
    return 0;
}