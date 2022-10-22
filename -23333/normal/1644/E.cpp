#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=1e6;
char s[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		int n;
		cin>>n;
		cin>>s;
		int m=strlen(s);
		int cnt1=0,cnt2=0,cnt3=1,cnt4=1;
		rep(i,0,m-1)
		  if (s[i]=='R') cnt1++; else cnt2++;
		if (cnt1==m||cnt2==m)
		{
			cout<<n<<endl;
			continue;
	    }
	    ll ans=1ll*n*n;
	    cnt1=n-cnt1-1; cnt2=n-cnt2-1;
	    bool tt=1;
	    rep(i,0,m-1)
	    {
	      if (s[i]!=s[0]) tt=0;
	      if (s[i]=='R')
	      {
	      	 cnt3++;
	      	 if (!tt) ans-=max(0,(n-cnt4)-cnt2);
	      	 else ans-=n-1;
	      } else
	      {
	      	 cnt4++;
	      	 if (!tt) ans-=max(0,(n-cnt3)-cnt1);
	      	 else ans-=n-1;
	      }
	    }
	    cout<<ans<<endl;
	}
	return 0; 
}