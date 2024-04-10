#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

#include <immintrin.h>
#include <emmintrin.h>
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
struct re{
	int a,b,c;
};
const int N=2e6;
int a[N],b[N],h[N];
int g[N],M[N],now,pos;
ll n,m,k;
ll check(ll x)
{
	ll ans=0;
	rep(i,1,n)
	{
		if (!M[a[i]]) continue;
		int t=h[i];
		if (!g[t]) continue;
		ll k;
		k=x/((now-1)*n);
		ans+=k+1;
		if ((k*(now-1)+(g[t]-1))*n+i>x) ans--;
	}
    x-=ans;
	return x-k;
}
int main()
{
   ios::sync_with_stdio(false);
   read(n); read(m); read(k);
   if (n>m)
   {
   	 swap(n,m);
     rep(i,1,m) read(b[i]);
     rep(i,1,n) read(a[i]);
   } else
   {
   	rep(i,1,n) read(a[i]);
   	rep(i,1,m) read(b[i]);
   }
   rep(i,1,m) M[b[i]]=i;
   rep(i,1,n) h[i]=(m-(i-M[a[i]])%m)%m;
   now=0;
   while (1)
   {
   	 now++;
     ll k=1ll*(now-1)*n%m;
   	 if (!g[k])
   	 {
   	 	g[k]=now;
   	 } else
   	 {
   	 	pos=g[k]; break;
   	 }
   }
   if (pos!=1&&now>m+10)
   {
   	return 0;
   }
   ll h=1,t=6e17;
   while (h<t)
   {
   	 ll mid=(h+t)/2;
   	 ll tt=check(mid);
   	 if (tt<0)
   	 {
   	 	h=mid+1;
   	 }
   	 if (tt>=0)
   	 {
   	 	t=mid;
     }
   }
   cout<<h<<endl;
   return 0;
}