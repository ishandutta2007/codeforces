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
int n,mo;
const int N=510;
const int P=510*510/2+10;
ll C[N][N],dp[2][P*2+100],sum[2][P*2+100],jc[N];
inline void jj(ll& x,ll y)
{
	x=(x+y)%mo;
}
int main()
{
   ios::sync_with_stdio(false);
   cin>>n>>mo;
   rep(i,0,n)
   {
   	 C[i][0]=1;
   	 rep(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
   }
   jc[0]=1;
   rep(i,1,n) jc[i]=jc[i-1]*i%mo;
   dp[0][0+P]=1;
   ll ans=0;
   rep(i,1,n)
   {
   	 int now=i%2,lst=(i+1)%2;
   	 int tt=i*(i-1)/2;
   	 int now2=-tt;
   	 me(dp[now]);
   	 dep(j,i,1)
   	 {
   	   jj(dp[now][-tt+P],dp[lst][now2+P]*j);
   	   now2++;
	 }
     rep(j,-tt+1,tt)
     {
       dp[now][j+P]=dp[now][j-1+P]; 
       jj(dp[now][j+P],-(sum[lst][j-1+P]-sum[lst][j-i-1+P]));
       jj(dp[now][j+P],sum[lst][j+P+i-1]-sum[lst][j+P-1]);
     }
     tt=(i+1)*i/2+i+10;
     me(sum[now]);
   	 rep(j,-tt,tt) jj(sum[now][j+P],sum[now][j+P-1]+dp[now][j+P]);
	 ll ans2=0; 
     rep(j,1,i)
       jj(ans2,(sum[now][tt+P]-sum[now][j+P])*(i+1-j)%mo);
     jj(ans,ans2*C[n][i+1]%mo*jc[n-i-1]%mo);
 //    cerr<<ans<<endl; 
   }
   ans=(ans+mo)%mo;
   cout<<ans<<endl;
   return 0;
}