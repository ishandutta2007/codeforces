#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define IL inline
#define rint register int
#define ll long long 
char ss[1<<24],*A=ss,*B=ss;
IL char gc()
{
    return A==B&&(B=(A=ss)+fread(ss,1,1<<24,stdin),A==B)?EOF:*A++;
}
template<class T> void read(T &x)
{
    rint f=1,c; while (c=gc(),c<48||c>57) if (c=='-') f=-1; x=(c^48);
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
const int N=3000;
const int N2=1e7+10;
const int N3=1e6+10;
struct re{
	int a,b;
}a[N],b[N],c[N],t[N2];
int f[N3];
bool cmp(re x,re y)
{
	return x.a<y.a||((x.a==y.a)&&(x.b<y.b));
}
bool cmp2(re x,re y)
{
    return x.a>y.a||((x.a==y.a)&&(x.b>y.b));
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
    cin>>n>>m;
    rep(i,1,n) cin>>a[i].a>>a[i].b;
    rep(i,1,m) cin>>b[i].a>>b[i].b;
    sort(b+1,b+m+1,cmp);
    int cnt=m+1,cnt2=0;
    dep(i,m,1)
      if (b[i].b>=c[cnt].b) c[--cnt]=b[i],cnt2++;
    m=cnt2;
    rep(i,1,m)
      b[i]=c[cnt+i-1];
    rep(i,1,m)
    {
    	rep(j,b[i-1].a,b[i].a-1) f[j]=b[i].b;
    }
    int num=0;
    b[m+1]=(re){-1,-1};
    rep(i,1,n)
    {
    	t[++num]=(re){0,max(0,f[a[i].a]-a[i].b+1)};
    	rep(j,1,m)
    	{
    	  if (b[j].a>=a[i].a) t[++num]=(re){b[j].a-a[i].a+1,max(0,b[j+1].b-a[i].b+1)};
    	  if (b[j].a>a[i].a) t[++num]=(re){b[j].a-a[i].a,max(0,b[j].b-a[i].b+1)};
        }
    }
    sort(t+1,t+num+1,cmp2);
    int now2=0;
    int ans=1e9;
    rep(i,1,num)
    {
    	now2=max(now2,t[i].b);
    	ans=min(ans,t[i].a+now2);
    }
    cout<<ans<<endl;
	return 0;
}