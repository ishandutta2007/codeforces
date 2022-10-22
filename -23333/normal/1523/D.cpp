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
const int N=2e5;
char s[N][70];
ll f[N];
int a[N];
int dp[N];
int main()
{
   ios::sync_with_stdio(false);
   int n,m,p;
   cin>>n>>m>>p;
   rep(i,1,n)
   {
   	cin>>s[i];
   	rep(j,0,m-1) f[i]=f[i]*2+s[i][j]-'0';
   }
   int bz=(n+1)/2;
   rep(i,1,n) a[i]=i;
   random_shuffle(a+1,a+n+1);
   int ans=0;ll ans2;
   rep(tt,1,min(n,15))
   {
   	  int i=a[tt];
   	  int h[40],cnt=0;
   	  rep(j,0,m-1) 
	    if ((f[i]>>j)&1)
   	      h[++cnt]=j;
   	  rep(j,1,n)
   	  {
   	  	ll now=0;
   	    rep(k,1,cnt)
   	      if ((f[j]>>h[k])&1) now+=1ll<<(k-1);
   	    dp[now]++;
//   	    if(now>1e5) cout<<now<<endl;
//   	    assert(now<1e5);
   	  }
   	  rep(j,1,cnt)
   	    rep(k,0,(1<<cnt)-1)
   	       if (k&(1<<(j-1)))
		   dp[k^(1<<(j-1))]+=dp[k]; 
	  rep(j,0,(1<<cnt)-1)
	  {
	  	int cnt2=0;
	  	rep(k,1,cnt) if ((j>>(k-1))&1) cnt2++;
	  	ll now=0;
	  	rep(k,1,cnt) if ((j>>(k-1))&1) now=now^(1ll<<h[k]);
      	if (dp[j]>=bz&&cnt2>ans)
      	{
      		ans=cnt2;
      		ans2=now;
      	}
      }
      me(dp);
   }
   char c[100];
   int cnt=0;
   rep(i,0,m-1) if ((ans2>>i)&1) c[++cnt]='1'; else c[++cnt]='0';
   dep(i,cnt,1) cout<<c[i];
   cout<<endl;
   return 0;
}