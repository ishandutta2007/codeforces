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
const int N=5e5;
int a[N];
vector<int> p[N],ve[N];
int bz[20][N],pp[N],n,m;
int main()
{
   ios::sync_with_stdio(false);
   cin>>n>>m;
   rep(i,2,1e5)
     for (int j=1;j*i<=1e5;j++)
     {
     	p[i*j].push_back(i);
     }
   rep(i,1,n)
   { 
     cin>>a[i];
	 for (auto j:p[a[i]])
	 {
	    ve[j].push_back(i); 
     }
   }
   rep(i,1,n)
   {
   	 pp[i]=n;
     for (auto j:p[a[i]])
	 {
	 	auto it=(upper_bound(ve[j].begin(),ve[j].end(),i));
	 	if (it!=ve[j].end()) pp[i]=min(pp[i],*it-1);
     }
   }
   dep(i,n-1,1) pp[i]=min(pp[i],pp[i+1]);
   rep(i,1,n) bz[0][i]=pp[i];
   rep(i,1,19)
     rep(j,1,n)
	   if (bz[i-1][j]!=n) 
	     bz[i][j]=bz[i-1][bz[i-1][j]+1];
	   else bz[i][j]=n;
   rep(i,1,m)
   {
     int x,y;
	 cin>>x>>y;
	 if (bz[0][x]>=y)
	 {
	 	cout<<1<<endl;
	 } else
	 {
	   int ans=0;
	   dep(i,19,0)
	   {
	   	  if (bz[i][x]<y) x=bz[i][x]+1,ans+=(1<<i);
       }
       if (bz[0][x]>=y) cout<<ans+1<<endl;
       else cout<<ans+2<<endl;
     }
   } 
   return 0;
}