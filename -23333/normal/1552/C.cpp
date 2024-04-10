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
	int d[10];
};
int T,n;
const int N=300;
bool vis[N],vis2[N];
int ve[N],k; 
int a[N],b[N];
#define mep memcpy(x,y,sizoef(y))
int main()
{
   ios::sync_with_stdio(false);
   cin>>T;
   while(T--)
   {
   	 cin>>n>>k;
   	 rep(i,1,2*n) vis[i]=0;
     rep(i,1,k)  
     {
     	cin>>a[i]>>b[i];
     	if(a[i]>b[i]) swap(a[i],b[i]); 
     	vis[a[i]]=1; vis[b[i]]=1;
     }     
     int cnt=0;
     rep(i,1,2*n)
       if (!vis[i]) ve[++cnt]=i;
     int t=n-k;
     rep(i,1,t)
       a[++k]=ve[i],b[k]=ve[i+t];
     int ans=0;
     rep(i,1,n)
       rep(j,i+1,n)
         if ((a[j]>a[i]&&a[j]<b[i]&&b[j]>b[i])||(a[i]>a[j]&&a[i]<b[j]&&b[i]>b[j])) ans++;
     cout<<ans<<endl;    
   }
   return 0;
}