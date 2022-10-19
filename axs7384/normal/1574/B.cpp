#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,d,mx,mn,da,xiao;
int main()
{
	cin>>t;
	while (t--)
	{
		cin>>a>>b>>c>>d;
		mx=max(0,a-1)+max(0,b-1)+max(0,c-1);
		da=max({a,b,c});
		xiao=a+b+c-da;
		mn=0;
		if (da>xiao)
			mn=da-xiao-1;
		puts(d>=mn&&d<=mx?"YES":"NO");
	}
	return 0;
}