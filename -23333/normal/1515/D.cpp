//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

//#include <immintrin.h>
//#include <emmintrin.h>
#include <bits/stdc++.h>
#define N 1000009
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
template<class T>void maxa(T &x,T y)
{
	if (y>x) x=y;
}
template<class T>void mina(T &x,T y)
{
	if (y<x) x=y;
}
template<class T>void read(T &x)
{
	int f=1,c; while (c=gc(),c<48||c>57) if (c=='-') f=-1; x=(c^48);
	while(c=gc(),c>47&&c<58) x=x*10+(c^48); x*=f;
}
const int maxn=1000000;
struct cp {
	ll x,y;
	cp operator +(cp B)
	{
		return (cp){x+B.x,y+B.y};
	}
	cp operator -(cp B)
	{
		return (cp){x-B.x,y-B.y};
	}
	ll operator *(cp B)
	{
		return x*B.y-y*B.x;
    }
    int half() { return y < 0 || (y == 0 && x < 0); }
};
struct re{
	int a,b,c;
};
int a[N],f[N];
int main()
{
   ios::sync_with_stdio(false);
   int T;
   cin>>T;
   while (T--)
   {
   	int n,m,k;
   	 cin>>n>>m>>k;
   	 rep(i,1,n) cin>>a[i];
   	 rep(i,1,m) f[a[i]]++;
   	 rep(i,m+1,n) f[a[i]]--;
   	 ll ans=0,gg=0,ans1=0,ans2=0;
   	 rep(i,1,n) if (f[i]<0) ans1-=f[i]; else ans2+=f[i];
   	 ans=min(ans1,ans2);
   	 int ans3=0;
   	 if (ans1>ans2)
     {
     	rep(i,1,n) if (f[i]<0)
		{
		   f[i]=-f[i]; 
		   ans3+=(f[i]/2)*2;
	    }
     } else
     {
     	rep(i,1,n) if (f[i]>0)
		{ 
		  ans3+=(f[i]/2)*2;
        }
     }
     if (ans3+min(ans1,ans2)>max(ans1,ans2))
     {
     	ans+=(max(ans1,ans2)-min(ans1,ans2))/2;
     } else
     {
     	int gg=max(ans1,ans2)-min(ans1,ans2);
     	ans+=gg-ans3/2;
     }
	 cout<<ans<<endl; 
	 rep(i,1,n) f[i]=0;
   }
   return 0;
}