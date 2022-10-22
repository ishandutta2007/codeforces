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
const int N=1e5;
int a[N];
int main()
{
//   freopen("1.in","r",stdin);
//   freopen("1.out","w",stdout);
   ios::sync_with_stdio(false);
   int T;
   cin>>T;
   while (T--)
   {
   	   int n,m;
   	  cin>>n>>m;
	  rep(i,1,n) cin>>a[i];
	  int gg=100;
	  bool tt1=0;
	  while (gg--)
	  {
	  	random_shuffle(a+1,a+n+1);
	  	int now=0;
		  bool tt=0; 
		rep(i,1,n)
		{ 
		  now=now+a[i];
		  if (now==m) tt=1;
	    }
	    if (!tt)
	    {
	    	tt1=1;
	    	cout<<"YES"<<endl;
	    	rep(i,1,n) cout<<a[i]<<" ";
	    	break;
	    }
	  }
	  if (!tt1)
	  {
	  	cout<<"NO"<<endl;
	  }
   }
   return 0;
}