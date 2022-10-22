#include<bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
int n,m;
const int N=3e5;
ll a[N],f[N],g[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>n>>m;
	ll sum=0; int cnt=0;
	rep(i,1,n)
	{ 
	  cin>>a[i];
	  sum+=a[i];
	  g[i]=g[i-1]+a[i];
	  f[i]=f[i-1]+(a[i]==0);
    }
    ll t1=(sum+f[n]*m),t2=sum-f[n]*m;
    if ((t1>0&&t2>0)||(t1<0&&t2<0))
    {
    	cout<<-1<<endl;
    	return 0;
    }
    ll t=ceil(1.0*(-sum+f[n]*m)/(2*m));
    t=max(t,1ll);
    t1=t-1; t2=f[n]-t;
    ll t3=-(sum+t1*m-t2*m);
    assert(t3>=-m&&t3<=m); 
    ll ans=0;
    rep(i,0,n) 
      rep(j,i+1,n)  
        {
        	ll t=f[j]-f[i];
        	ll g1=0,g2=0;
        	if (t1>=t) g1=t*m; else g1=t1*m+t3-(t-t1-1)*m;
        	if (t2>=t) g2=-t*m; else g2=-t2*m+t3+(t-t2-1)*m;
        	ans=max(ans,g[j]-g[i]+g1);
        	ans=max(ans,g[i]-g[j]-g2);
        }
    cout<<ans+1<<endl;
	return 0;
}