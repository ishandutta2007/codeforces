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
int n,mo;
ll f[500][500],inv[500],jc[500],h[500];
ll fsp(int x,int y)
{
	if (y==1) return x;
	ll ans=fsp(x,y/2);
	ans=ans*ans%mo;
	if (y%2==1) ans=ans*x%mo;
	return ans;
}
ll C(int x,int y)
{
	return jc[x]*inv[y]%mo*inv[x-y]%mo;
}
int main()
{
   ios::sync_with_stdio(false);
   cin>>n>>mo;
   inv[0]=1; jc[0]=1;
   rep(i,1,n) inv[i]=fsp(i,mo-2); 
   rep(i,1,n) inv[i]=inv[i]*inv[i-1]%mo;
   rep(i,1,n) jc[i]=jc[i-1]*i%mo;
   f[0][0]=1;
   f[1][1]=1;
   h[1]=1;
   rep(i,2,n) h[i]=h[i-1]*2%mo;
   rep(i,2,n)
     rep(j,1,i)
     {
       rep(k,1,j)
       {
       	if (i-k-1==0) continue;
       	 int gg;
       	 if (k==1) gg=1; else gg=2;
	     f[i][j]=(f[i][j]+f[max(0,i-k-1)][j-k]*C(j,k)%mo*h[k])%mo;
	   }
     }
   ll now=1;
   ll ans=0;
   rep(i,1,n)
   {
   	ans=(ans+f[n][i])%mo;
   }
   cout<<ans<<endl;
   return 0;
}