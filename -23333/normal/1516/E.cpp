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
//char ss[1<<24],*A=ss,*B=ss;
//IL char gc()
//{
//	return A==B&&(B=(A=ss)+fread(ss,1,1<<24,stdin),A==B)?EOF:*A++;
//}
template<class T>void maxa(T &x,T y)
{
	if (y>x) x=y;
}
template<class T>void mina(T &x,T y)
{
	if (y<x) x=y;
}
//template<class T>void read(T &x)
//{
//	int f=1,c; while (c=gc(),c<48||c>57) if (c=='-') f=-1; x=(c^48);
//	while(c=gc(),c>47&&c<58) x=x*10+(c^48); x*=f;
//}
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
ll f[300][300],ans[300];
ll A[500][500],h2[300],h[300];
int main()
{
//   freopen("1.in","r",stdin);
//   freopen("1.out","w",stdout);
   ios::sync_with_stdio(false);
   int n,m;
   cin>>n>>m;
   h2[0]=1;
   rep(i,0,2*m)
   {
     A[i][0]=1;
     rep(j,1,2*m)
       A[i][j]=A[i][j-1]*(n-i-j+1)%mo;
   }
   rep(i,1,m) h2[i]=h2[i-1]*i%mo;
   rep(i,1,m) h2[i]=fsp(h2[i],mo-2);
   rep(i,1,m+1) h[i]=fsp(i,mo-2); 
   f[0][0]=1;
   rep(i,1,m)
     rep(j,1,m)
     {
       rep(k,1,j)
       {
       	  int kk=(i-1)+(j-k);
       	  if (kk>=0)
       	  {
       	    f[i][j]=(f[i][j]+f[i-1][j-k]*A[kk][k+1]%mo*h[k+1])%mo;
       	  }
       }
       ans[j]=(ans[j]+f[i][j]*h2[i])%mo;
     }
   ans[0]=1;
   rep(i,2,m) ans[i]=(ans[i]+ans[i-2])%mo;
   rep(i,1,m) cout<<ans[i]<<" ";
   return 0;
}