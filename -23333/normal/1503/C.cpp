//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
#define me(x) memset(x,0,sizeof(x))
#define IL inline
#define rint register int
inline ll rd(){
	ll x=0;char c=getchar();bool f=0;
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f?-x:x;
}
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
const int N=2e5;
struct re{
	int a,b,c;
}a[N];
bool cmp(re x,re y)
{
	return x.a<y.a;
}
int main()
{
   ios::sync_with_stdio(false);
   int n;
   cin>>n;
   ll ans=0;
   rep(i,1,n)
   {
     cin>>a[i].a>>a[i].b;
     ans+=a[i].b;
   }
   sort(a+1,a+n+1,cmp);
   ll nowa=a[1].b+a[1].a;
   rep(i,1,n)
   {
   	ans+=max(a[i].a-nowa,0ll);
   	nowa=max(nowa,1ll*a[i].b+a[i].a);
   }
   cout<<ans<<endl;
   return 0;
}