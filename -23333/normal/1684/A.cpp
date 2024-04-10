#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
int T,n,m;
char s[100];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>s;
		int n=strlen(s);
		if (n==2)
		{
			cout<<s[1]<<endl;
		} else
		{
		  int ans=9;
		  rep(i,0,n-1)
		    ans=min(ans,s[i]-'0');
		  cout<<ans<<endl;
	    }
	}
	return 0;
}