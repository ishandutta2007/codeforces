#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
#define me(x) memset(x,0,sizeof(x))
#define IL inline
#define rint register int
char ss[1<<24],*A=ss,*B=ss;
IL char gc()
{
	return A==B&&(B=(A=ss)+fread(ss,1,1<<24,stdin),A==B)?EOF:*A++;
}
template<class T>void read(T &x)
{
	int f=1,c; while (c=gc(),c<48||c>57) if (c=='-') f=-1; x=(c^48);
	while(c=gc(),c>47&&c<58) x=x*10+(c^48); x*=f;
}
const int mo=1e9+7;
const int N=1000;
struct re{
	ll a,b;
}a1[5],b1[5]; 
ll a[5],b[5],c[5];
bool tf=0;
int n,x;
ll f1(ll x,int y)
{
	ll ans=a[2]-a[1]+a[4]-a[3];
	if (!y)
	{
    if (x>=c[1]&&x<=c[2]) return ans;
    if (x>=c[2]) return ans+2*(x-c[2]);
    if (x<=c[1]) return ans+2*(c[1]-x);
    } else
    {
    	if(x<=c[2]) return c[2]+c[1];
    	else return c[2]+c[1]+(x-c[2])*2;
    }
}
ll f2(ll x,int y)
{
	ll ans=b[2]-b[1]+b[4]-b[3];
	if (!y)
	{ 
    if (x>=c[3]&&x<=c[4]) return ans;
    if (x>=c[4]) return ans+2*(x-c[4]);
    if (x<=c[3]) return ans+2*(c[3]-x);
    } else
	{
		if(x<=c[4]) return c[3]+c[4];
		else return c[4]+c[3]+(x-c[4])*2;
    }
}
bool cmp(re x,re y)
{
	return x.a<y.a;
}
int main()
{
   ios::sync_with_stdio(false);
   int T;
   cin>>T;
   while(T--)
   {
   	 rep(i,1,4)
	 { 
		cin>>a1[i].a>>b1[i].a;
		a1[i].b=i; b1[i].b=i;
	 }
   	 sort(a1+1,a1+4+1,cmp); sort(b1+1,b1+4+1,cmp);
   	 tf=0;
   	 if (a1[1].b+a1[2].b+b1[1].b+b1[2].b==10||a1[1].b+a1[2].b==b1[1].b+b1[2].b)
   	 tf=1;
   	 rep(i,1,4) a[i]=a1[i].a,b[i]=b1[i].a;
   	 c[1]=a[3]-a[2],c[2]=a[4]-a[1],c[3]=b[3]-b[2],c[4]=b[4]-b[1];
   	 ll ans=1e10;
   	 rep(i,1,4)
   	 {
   	 	if (!tf) ans=min(ans,f1(c[i],0)+f2(c[i],0));
	    else
		{
			ans=min(ans,f1(c[i],1)+f2(c[i],0));
			ans=min(ans,f1(c[i],0)+f2(c[i],1));
	    }
   	 }
   	 cout<<ans<<endl;
   }
   return 0;
}