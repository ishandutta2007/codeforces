#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (ll i=h;i<=t;i++)
#define dep(i,t,h) for (ll i=t;i>=h;i--)
#define IL inline
#define rll register ll
#define ll long long 
char ss[1<<24],*A=ss,*B=ss;
IL char gc()
{
    return A==B&&(B=(A=ss)+fread(ss,1,1<<24,stdin),A==B)?EOF:*A++;
}
template<class T> void read(T &x)
{
    rll f=1,c; while (c=gc(),c<48||c>57) if (c=='-') f=-1; x=(c^48);
    while (c=gc(),c>47&&c<58) x=(x<<3)+(x<<1)+(c^48); x*=f; 
}
char sr[1<<24],z[20]; ll Z,C1=-1;
template<class T>void wer(T x)
{
    if (x<0) sr[++C1]='-',x=-x;
    while (z[++Z]=x%10+48,x/=10);
    while (sr[++C1]=z[Z],--Z);
}
IL void wer1()
{
    sr[++C1]=' ';
}
IL void wer2()
{
	sr[++C1]='\n';
}
ll a,b,c,d;
ll js(ll x)
{
	ll f=1ll*x*a;
	ll k2=x-1.00*c/d;
	k2=max(k2,0ll);
	f-=k2*b*c;
    k2++;
	f-=((x-k2+1)*x*d-(x-k2+1)*(x+k2)*d/2)*b;
	return f;
}
int main()
{
	ll T;
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c>>d;
		if (a>b*c)
		{
			cout<<-1<<endl;
		} else
		{
			ll t=a/b;
			ll t2=t/d;
			ll ans=0;
			rep(i,max(t2-10,1ll),t2+10)
			 ans=max(ans,js(i));  
			cout<<ans<<endl;
		//	cout<<js(t2+1)<<endl;
		}
	}
//	fwrite(sr,1,C1+1,stdout);
	return 0;
}