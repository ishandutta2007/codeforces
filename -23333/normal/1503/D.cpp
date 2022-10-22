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
const int N=1e6;
struct re{
	int a,b,c,d;
}a[N];
bool cmp(re x,re y)
{
	return x.a<y.a;
}
int n;
int main()
{
   ios::sync_with_stdio(false);
   cin>>n;
   rep(i,1,n)
   {
   	 cin>>a[i].a>>a[i].b;
   	 if (a[i].a<a[i].b) a[i].d=0; else a[i].d=1;
   	 if (a[i].a>a[i].b) swap(a[i].a,a[i].b);
   }
   sort(a+1,a+n+1,cmp);
   rep(i,1,n)
   {
   	 if (a[i].b-n-1<0)
   	 {
   	 	cout<<-1<<endl;
   	 	return 0;
   	 }
   }
   int now1=n,now2=n,ans2=0,ans=0,cnt=0;
   rep(i,1,n)
   {
   	 int gg=a[i].b-n-1;
   	 if (gg>now1)
   	 {
   	 	cout<<-1<<endl;
   	 	return 0;
   	 }
   	 if (gg>now2)
   	 {
   	 	if (a[i].d==0) ans2++;
   	 	now1=gg;
   	 } else
   	 {
   	 	if (a[i].d==1) ans2++;
   	 	now2=gg;
   	 }
   	 cnt++;
   	 if (now2+i==n)
   	 {
   	 	ans+=min(ans2,cnt-ans2);
   	 	cnt=0;
   	 	ans2=0;
   	 }
   }
   cout<<ans<<endl;
   return 0;
}