//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

//#include <immintrin.h>
//#include <emmintrin.h>
#include <bits/stdc++.h>
#define N 100009
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
int tag[N][11];
int top,n,st[N],d;
int a[N];
double b[N],dp[N][11];
struct re{
	int a,b,c;
};
void dfs(int n,int d){
	if(!n)return;
	if(tag[n][d]>=0){
		st[++top]=a[n];
		dfs(n-1,tag[n][d]);
	}
	else{
		dfs(n-1,d);
	}
}
int main()
{
   n=rd();d=rd();
   for(int i=1;i<=n;++i){
   	  a[i]=rd();
   	  b[i]=log(1.0*a[i]);
  // 	  printf("%.2lf ",b[i]);
   }
  // puts("");
   for(int i=0;i<=9;++i)dp[0][i]=-1;
   dp[0][1]=0;
   for(int i=1;i<=n;++i){
   	  for(int j=0;j<10;++j){
		 tag[i][j]=-1;
		 dp[i][j]=dp[i-1][j];
	  }
   	  for(int j=0;j<10;++j)if(dp[i-1][j]!=-1){
   	  	if(dp[i][(j*a[i])%10]<dp[i-1][j]+b[i]){
   	  		dp[i][(j*a[i])%10]=dp[i-1][j]+b[i];
   	  		tag[i][(j*a[i])%10]=j;
   	  	}
   	  }
   //	  for(int j=0;j<10;++j)printf("%.2lf ",dp[i][j]);puts("");
   }
   if(dp[n][d]<0)puts("-1");
   else{
   	 dfs(n,d);
   	 if(!top)puts("-1");
   	 else{
   	 printf("%d\n",top);
   	 for(int i=top;i>=1;--i)printf("%d ",st[i]);
     }
   }
   return 0;
}