#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		long long ans=0;
		int b;
		for(b=1;x/(b+1)>=b-1&&b<=y;b++)ans+=min(x/(b+1),b-1);
		b--;
		for(int c=1;c<=b-1;c++)
		{
			int xx=min(y,x/c-1);
			int sx=max(b+1,x/(c+1));
			ans+=1ll*c*max(0,xx-sx+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}