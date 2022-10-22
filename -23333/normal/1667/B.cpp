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
int n,m,nn;
ll a[N],b[N],c[N],dp[N];
ll sum[N],sum2[N];
#define mid ((h+t)/2)
struct sgt{
	ll v[N*4];
	void build(int x,int h,int t)
	{
		v[x]=-1e18;
		if (h==t) return;
		build(x*2,h,mid); build(x*2+1,mid+1,t);
	}
	void g(int x,int h,int t,int pos,ll k)
	{
		v[x]=max(v[x],k);
		if (h==t) return;
		if (pos<=mid) g(x*2,h,mid,pos,k);
		else g(x*2+1,mid+1,t,pos,k);
	}
	ll q(int x,int h,int t,int h1,int t1)
	{
		if (h1<=h&&t<=t1) return v[x];
		ll ans=-1e18;
		if (h1<=mid) ans=q(x*2,h,mid,h1,t1);
		if (mid<t1) ans=max(ans,q(x*2+1,mid+1,t,h1,t1));
		return ans;
	}
}S;
int pos(ll x)
{
	return upper_bound(sum2+1,sum2+nn+1,x)-sum2-1; 
}
int main()
{
     ios::sync_with_stdio(false);
     int T;
     cin>>T;
     while (T--)
     {
   	     cin>>n;
   	     rep(i,1,n) cin>>a[i];
		 rep(i,1,n) sum[i]=sum[i-1]+a[i];
		 ll mn=0;
		 int cnt=1; b[1]=0; c[1]=0;
		 rep(i,1,n) dp[i]=-1e18;
		 rep(i,1,n) sum2[i]=sum[i]; sum2[n+1]=0;
		 sort(sum2+1,sum2+n+2);
		 nn=unique(sum2+1,sum2+n+2)-sum2-1;
		 S.build(1,1,nn);
		 S.g(1,1,nn,pos(0),0);
		 rep(i,1,n)
		 {
	       if (a[i]==0) dp[i]=max(dp[i],dp[i-1]);
		   else if (a[i]<0) dp[i]=max(dp[i],dp[i-1]-1);
		   else dp[i]=max(dp[i],dp[i-1]+1);
		   int t=pos(sum[i]-1);
		   if (1<=t) dp[i]=max(dp[i],S.q(1,1,nn,1,t)+i);
		   S.g(1,1,nn,pos(sum[i]),dp[i]-i);
	     }
	     cout<<dp[n]<<endl;
     }
     return 0;
}