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

//unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//mt19937 myrand(seed);
//uniform_int_distribution<ll>dist(1,10000000);
//dist(myrand);
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
const int N=500;
int a[N*N],b[N*N];
int c[N*N];
int now[N][N];
int p[N*N];
vector<re> ve[N*N];
bool cmp(re x,re y)
{
	return x.a<y.a||(x.a==y.a&&x.b>y.b);
}
int main()
{
   ios::sync_with_stdio(false);
   int T;
   cin>>T;
   while(T--)
   {
   	int n,m;
   	cin>>n>>m;
   	rep(i,1,n*m) cin>>a[i],b[i]=a[i],c[i]=0;
   	sort(b+1,b+n*m+1);
   	int nn=unique(b+1,b+n*m+1)-b-1;
   	rep(i,1,n*m) a[i]=lower_bound(b+1,b+nn+1,a[i])-b,c[a[i]]++;
   	rep(i,1,n*m) c[i]+=c[i-1];
   	rep(i,1,n*m)
   	{
   	  ve[i].clear(); p[i]=-1;
   	  rep(j,c[i-1]+1,c[i])
   	  {
   	  	int x=(j-1)/m+1,y=j-(x-1)*m;
   	  	ve[i].push_back((re){x,y});
   	  }
   	  sort(ve[i].begin(),ve[i].end(),cmp);
    }
   	int ans=0;
   	rep(i,1,n*m)
   	{
   	  p[a[i]]++;
   	  int x=ve[a[i]][p[a[i]]].a,y=ve[a[i]][p[a[i]]].b;
   	  now[x][y]=1;
   	  rep(j,1,y-1) ans+=now[x][j];
    }
   	cout<<ans<<endl;
   	rep(i,1,n)
   	  rep(j,1,m) now[i][j]=0;
   }
   return 0;
}