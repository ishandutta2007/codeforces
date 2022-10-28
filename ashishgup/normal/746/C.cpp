#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
	IOS;
	int s,x1,x2,t1,t2;
	cin>>s>>x1>>x2>>t1>>t2;
	int p,d1;
	cin>>p>>d1;
	int d2=(x2-x1)/abs(x2-x1);
	if(d2<0)
	{
		d1*=-1;
		x2=s-x2;
		x1=s-x1;
		p=s-p;
	}
	int ans=(x2-x1)*t2;
	if(p>x1 && d1>0)
	{
		int t=(s-p+s+x2)*t1;
		ans=min(t,ans);
	}
	if(p<=x1 && d1>0)
	{
		int t=(x2-p)*t1;
		ans=min(t,ans);
	}
	if(d1<0)
	{
		int t=(p+x2)*t1;
		ans=min(t,ans);
	}
	cout<<ans;
	return 0;
}