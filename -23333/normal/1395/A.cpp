#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int t=t;i>=h;i--)
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T; 
	rep(i,1,T)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int cnt=0;
		if (a%2==1) cnt++;
		if (b%2==1) cnt++;
		if (c%2==1) cnt++;
	    if (d%2==1&&cnt!=1&&a>0&&b>0&&c>0) cnt=0;
	    if (d%2==0&&cnt==3&&a>0&&b>0&&c>0) cnt=0;
	   	if (d%2==1) cnt++;
	    if (cnt<=1) cout<<"Yes"<<endl;
	    else cout<<"No"<<endl;
	}
	return 0;
}