#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--) 
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	rep(i,1,T)
	{
		int a1,b1,c1,a2,b2,c2;
		cin>>a1>>b1>>c1>>a2>>b2>>c2;
		int x=min(c1,b2),ans=0;
		if (b2+a2>=b1+x) ans=x*2;
		else ans=x*2-(b1+x-b2-a2)*2;
		cout<<ans<<endl;
	}
	return 0;
}