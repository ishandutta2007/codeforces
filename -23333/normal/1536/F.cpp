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
const int N=3e6;
ll jc[N],jc2[N];
ll C(int x,int y)
{ 
	if (x<0||x<y) return 0;
	return jc[x]*jc2[x-y]%mo*jc2[y]%mo;
}
int main()
{
  // freopen("1.in","r",stdin);
  // freopen("1.out","w",stdout);
   ios::sync_with_stdio(false);
   int n;
   cin>>n;
   jc[0]=1; jc2[0]=1;
   rep(i,1,n) jc[i]=jc[i-1]*i%mo; 
   jc2[n]=fsp(jc[n],mo-2);
   dep(i,n-1,1)
     jc2[i]=1ll*jc2[i+1]*(i+1)%mo;
   ll ans=0;
   rep(i,(n+1)/2,n)
   if (i%2==0)
   {
   	 ans=(ans+2*((C(i,n-i)+C(i-1,n-i-1))%mo)*jc[i])%mo;
   }
   cout<<ans<<endl;
   return 0;
}