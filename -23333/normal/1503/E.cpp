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
struct re{
	int a,b,c;
};
const int N=5100;
ll C[N][N];
int main()
{
  // freopen("1.in","r",stdin);
  // freopen("1.out","w",stdout);
   ios::sync_with_stdio(false);
   int n,m;
   cin>>n>>m;
   rep(i,0,5090)
   {
   	 C[i][0]=1;
     rep(j,1,i)
	   C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
   }
   ll ans2=0; 
   rep(i,1,n-1)
   {
   	 ll ans=0;
   	 rep(j,1,m)
   	 {
   	 	ans2=(ans2+C[i-1+j-1][j-1]*C[i+m-j][m-j]%mo*ans)%mo;
   	 	ans=(ans+C[n-i+j-1][j-1]*C[n-i-1+m-j][m-j])%mo;
   	 }
//   	 cerr<<ans2<<endl;
   }
//   cerr<<ans2<<endl;
   swap(n,m);
   rep(i,1,n-1)
   {
   	 ll ans=0,ans3=0;
   	 rep(j,1,m)
   	 {
   	 	ans2=(ans2+C[i-1+j-1][j-1]*C[i+m-j][m-j]%mo*ans3)%mo;
   	 	ans3=ans; 
   	 	ans=(ans+C[n-i+j-1][j-1]*C[n-i-1+m-j][m-j])%mo;
   	 }
   }
   ans2=ans2*2%mo;
   cout<<(ans2%mo+mo)%mo<<endl;
   return 0;
}