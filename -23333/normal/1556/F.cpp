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
int n;
const int N=20;
const int M=1e5;
ll a[N],f[N][N],g[N][M],dp[M];
int main()
{
   ios::sync_with_stdio(false);
   int n;
   cin>>n;
   rep(i,1,n) cin>>a[i];
   rep(i,1,n)
     rep(j,1,n) f[i][j]=1ll*fsp(a[i]+a[j],mo-2)*(a[i])%mo;
   rep(i,1,n) g[i][0]=1;
   rep(i,1,(1<<n)-1)
   {
   	 int gg=0;
     rep(j,1,n) if ((i>>(j-1))&1) gg=j-1;
     rep(j,1,n)
       g[j][i]=g[j][i^(1<<gg)]*f[j][gg+1]%mo;
   }
   rep(j,1,(1<<n)-1)
   {
   	 dp[j]=1;
     for (int k=(j-1)&j;k;k=(k-1)&j)
     {
     	int t=k^j;
     	ll now=1;
     	rep(i,1,n) if ((k>>(i-1))&1) now=now*g[i][t]%mo;
     	dp[j]=(dp[j]-now*dp[k])%mo;
     }
   }
   ll ans=0;
   rep(j,1,(1<<n)-1)
   {
   	int t=j^((1<<n)-1);
   	ll now=1,cnt=0;
   	rep(i,1,n) if ((j>>(i-1))&1) now=now*g[i][t]%mo;
   	rep(i,1,n) if ((j>>(i-1))&1) cnt++;
   	ans=(ans+cnt*now%mo*dp[j]%mo)%mo;
   }
   ans=(ans+mo)%mo;
   cout<<ans<<endl;
   return 0;
}