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
struct re{
	int a,b,c;
};
const int N=2e5;
ll f[N];
int main()
{
   ios::sync_with_stdio(false);
   int T;
   cin>>T;
   f[0]=1;
   rep(i,1,60) f[i]=f[i-1]*2;
   while(T--)
   {
   	ll n,k;
   	 cin>>n>>k;
   	 if (n<61&&f[n-1]<k)
   	 {
   	 	cout<<-1<<endl;
   	 } else
   	 {
   	 	rep(i,1,n)
   	 	{
   	 		if (i==n||n-1-i>60||f[n-1-i]>=k)
   	 		{
   	 			cout<<i<<" ";
   	 		} else
   	 		{
   	 			int now=i;
   	 			while (now<n&&k>f[n-1-now])
			    {
			    	k-=f[n-1-now];
			    	now++;
			    }
			    dep(j,now,i) cout<<j<<" ";
			    i=now;
			}
   	 	}
   	 	cout<<endl;
   	 }
   }
   return 0;
}