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
const int N=5e6;
int mo,n;
ll sum[N],f[N];
int main()
{
   ios::sync_with_stdio(false);
   cin>>n>>mo;
   sum[n]=1; f[n]=1;
   dep(i,n-1,1)
   {
   	 f[i]=sum[i+1];
   	 sum[i]=sum[i+1];
   	 for (int j=2;j*i<=n;j++)
   	   f[i]=(f[i]+(sum[j*i]-sum[min(n+1,j*i+j)]))%mo;
   	 sum[i]=(sum[i]+f[i])%mo; 
   }
   f[1]=(f[1]+mo)%mo;
 /*  rep(i,2,n)
   {
   	 f[i]=sum[i-1];
   	 for (int j=2;j<=i;j=i/((i/j))+1)
   	 {
   	 	int k=i/((i/j));
   	 	f[i]=(f[i]+(k-j+1)*f[i/j])%mo;
   	 }
   	 sum[i]=(sum[i-1]+f[i])%mo;
   }*/
   cout<<f[1]<<endl;
   return 0;
}