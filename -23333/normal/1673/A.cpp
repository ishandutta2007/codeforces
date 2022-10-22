#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
int T,n,m;
const int N=3e5;
int a[N];
char s[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		//cin>>n>>m;
		cin>>s;
		int n=strlen(s);
		int ans=0;
		rep(i,0,n-1) ans+=s[i]-'a'+1;
		if (n%2==1)
		{
			ans-=2*min(s[0]-'a'+1,s[n-1]-'a'+1);
		}	
		if (ans>0) cout<<"Alice "<<ans<<endl;
		else cout<<"Bob "<<-ans<<endl;
	}
	return 0;
}