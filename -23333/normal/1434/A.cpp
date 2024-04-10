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
const int N=2e6;
int a[N],b[N];
struct re{
	int a,b;
}c[N];
bool cmp(re x,re y)
{
	return x.b<y.b;
}
int jl[N];
int main()
{
	ll T;
	int n;
	rep(i,1,6) cin>>a[i];
	cin>>n;
	rep(i,1,n) cin>>b[i];
	int cnt=0;
	rep(i,1,n)
	{
		rep(j,1,6)
		{
		 	c[++cnt]=(re){i,b[i]-a[j]};
		}
	}
	sort(c+1,c+cnt+1,cmp);
	int h=1,t;
	int cnt2=0;
	rep(i,1,6*n)
	{ 
	  if (jl[c[i].a]==0) cnt2++;
	  jl[c[i].a]++;
	  if (cnt2==n)
	  {
	  	t=i; break;
	  }
    }	
    while (jl[c[h].a]>1)
	{
		jl[c[h].a]--; h++;
    }
    int ans=c[t].b-c[h].b; 
    t++;
    for(;t<=6*n;t++)
    {
    	jl[c[t].a]++;
    	while (jl[c[h].a]>1)
		{
			jl[c[h].a]--; h++;
    	}
    	ans=min(ans,c[t].b-c[h].b);
    }
    cout<<ans<<endl;
//	fwrite(sr,1,C1+1,stdout);
	return 0;
}