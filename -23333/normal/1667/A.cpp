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

//unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//mt19937 myrand(seed);
//uniform_int_distribution<ll>dist(1,10000000);
//dist(myrand);
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
    if (y==0) return 1;
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
const int N=1e6+10; 
int n,m;
int a[N];
ll js(ll x,ll y)
{
	if (x%y==0) return x/y;
	return x/y+1;
}
int main()
{
     ios::sync_with_stdio(false);
     int T;
//     cin>>T;
     T=1;
     while (T--)
     {
   	     cin>>n;
   	     rep(i,1,n) cin>>a[i];
   	     ll ans2=1e18;
   	     rep(i,1,n)
   	     {
   	       ll now=0;
   	       ll ans=0;
   	       dep(j,i-1,1)
		   {
		   	 ll t=js(now+1,a[j]);
		   	 now=t*a[j];
		   	 ans+=t;
		   }
		   now=0;	
		   rep(j,i+1,n)
		   {
		   	 ll t=js(now+1,a[j]);
		   	 now=t*a[j];
		   	 ans+=t;
		   }
		   ans2=min(ans2,ans);
   	     }
   	     cout<<ans2<<endl;
     }
     return 0;
}