#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=1e6;
char c[N];
ll f[N],g[N],n;
int main()
{
	cin>>n;
	cin>>c;
	ll now=0,ans=0,ans2=0;
	int cnt=0;
	rep(i,1,n)
	  if (c[i-1]=='1')
	  {
	  	now++;
	  	ans+=now*(now+1)/2;
	  	int cnt2=cnt;
	  	while (now>=f[cnt]&&cnt>0) ans2-=f[cnt]*g[cnt],f[cnt]=now,cnt--;
	  	if (cnt<cnt2)
		{ 
		  cnt++;
		  rep(j,cnt+1,cnt2) g[cnt]+=g[j];
		  ans2+=f[cnt]*g[cnt]; 
	    }
	    ans+=ans2;
	  } else
	  {
	    if (now>0)
	    {
	    	dep(i,now,1) f[++cnt]=i,g[cnt]=1,ans2+=i;
	    	now=0;
	    }
	    ans+=ans2;
	    f[++cnt]=0,g[cnt]=1;
	  }
	cout<<ans<<endl;
	return 0; 
}