//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

//#include <immintrin.h>
//#include <emmintrin.h>
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
const int mo=1e9+7;
ll fsp(int x,int y)
{
	if (y==1) return x;
	ll ans=fsp(x,y/2);
	ans=ans*ans%mo;
	if (y%2==1) ans=ans*x%mo;
	return ans;
}
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
const int N=1e6;
const int M=2e7;
int a[N],ans2[N];
int ls[M],rs[M],mx[M],mn[M],ans[M],cnt,rt;
void insert(int &z,int x,int y)
{
	if (!z) { z=++cnt; mn[z]=1e9; ans[z]=1e9;}
	int k=x-((x>>(y+1))<<(y+1));
	mx[z]=max(mx[z],k);
	mn[z]=min(mn[z],k);
	if (y==-1) return;
	if ((x>>y)&1)
	{ 
	  insert(rs[z],x,y-1);
    } else
    {
      insert(ls[z],x,y-1);
    }
    if (ls[z])
    {
    	ans[z]=min(ans[z],ans[ls[z]]);
    }
    if (rs[z])
    {
    	ans[z]=min(ans[z],ans[rs[z]]);
    }
    if (ls[z]&&rs[z])
    {
    	ans[z]=min(ans[z],mn[rs[z]]+(1<<y)-mx[ls[z]]);
    }
}
void g(int z,int y,int k)
{
	if (y==k)
	{
		swap(ls[z],rs[z]);
	} else
	{
	  if (ls[z])
	  {
		g(ls[z],y-1,k);
	  }
	  if (rs[z])
	  { 
		g(rs[z],y-1,k);
	  }
    }
	mx[z]=0; mn[z]=1e9; ans[z]=1e9;
	if (rs[z])
	{
		mx[z]=max(mx[z],mx[rs[z]]+(1<<y));
		mn[z]=min(mn[z],mn[rs[z]]+(1<<y));
    	ans[z]=min(ans[z],ans[rs[z]]);
	}
	if(ls[z])
	{
		mx[z]=max(mx[z],mx[ls[z]]);
		mn[z]=min(mn[z],mn[ls[z]]);
		ans[z]=min(ans[z],ans[ls[z]]); 
	}
	if (ls[z]&&rs[z])
	{
		ans[z]=min(ans[z],mn[rs[z]]+(1<<y)-mx[ls[z]]);
	}
}
int main()
{
   ios::sync_with_stdio(false);
   int n,m;
   cin>>n>>m;
   rep(i,1,n)
   { 
     cin>>a[i];
     insert(rt,a[i],m-1);
   }
   int gg=1;
   rep(i,1,m) gg*=2;
   int now=0;
   rep(i,0,gg-1)
   {
   	 int p=0;
   	 rep(j,0,m-1)
   	   if ((i>>j)&1) p=p+(1<<(m-1-j));
   	 rep(j,0,m-1)
   	   if (((now>>j)&1)!=((p>>j)&1))
   	     g(rt,m-1,j);
   	 ans2[p]=ans[rt];  
   	 now=p;
   }
   rep(i,0,gg-1) cout<<ans2[i]<<" ";
   return 0;
}