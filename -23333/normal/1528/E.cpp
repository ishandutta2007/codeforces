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
const int mo=998244353;
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
const int N=2e6;
ll f[N],inv2,inv6,h[N];
ll g(ll x)
{
	x=x%mo;
	return x*(x+1)%mo*(x+2)%mo*inv6%mo; 
}
int main()
{
 //  freopen("1.in","r",stdin);
 //  freopen("1.out","w",stdout);
   ios::sync_with_stdio(false);
   int n;
   cin>>n;
   f[0]=1; ll ans=1;
   inv2=fsp(2,mo-2),inv6=fsp(6,mo-2);
   rep(i,1,n)
   {
     f[i]=(ans*(ans+1)%mo*inv2-(ans-f[i-1])*(ans-f[i-1]+1)%mo*inv2)%mo;
     ans=(ans+f[i])%mo;
   }
   rep(i,1,n) h[i]=(f[i]-f[i-1])%mo;
   ll ans2=(g(ans)-g(ans-f[n]))%mo;
   ans2=(ans2*2-1)%mo;
  // cerr<<ans2<<endl;
   rep(i,0,n-1)
   {  
   	  ans2=(ans2+1ll*h[n-i]*(f[i+1]-1))%mo;
   }
   cout<<(ans2+mo)%mo<<endl;
   return 0;
}