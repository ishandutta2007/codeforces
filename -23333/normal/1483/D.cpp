
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

#include <immintrin.h>
#include <emmintrin.h>
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
template<class T>void read(T &x)
{
	int f=1,c; while (c=gc(),c<48||c>57) if (c=='-') f=-1; x=(c^48);
	while(c=gc(),c>47&&c<58) x=x*10+(c^48); x*=f;
}
const int mo=1e9+7;
struct re{
	short a,b;
	ll c;
};
int n,m;
const int N=603;
ll dis[N][N],dis2[N][N],dis3[N][N];
bool g[N][N],g2[N][N],p[N][N];
struct cmp{
	bool operator() (re x,re y)
	{
		return x.c<y.c;
	}
};
priority_queue<re,vector<re>,cmp> q;
int main()
{
   ios::sync_with_stdio(false);
   cin>>n>>m;
   rep(i,1,n)
     rep(j,1,n) dis[i][j]=1e18;
   rep(i,1,m)
   {
   	int x,y,z;
   	cin>>x>>y>>z;
   	dis[x][y]=dis[y][x]=dis3[x][y]=dis3[y][x]=z;
   	p[x][y]=1;
   }
   rep(i,1,n)
     rep(j,1,n)
       rep(k,1,n)
         dis[j][k]=min(dis[j][i]+dis[i][k],dis[j][k]);
   int qq;
   cin>>qq;
   rep(i,1,qq)
   {
   	 int x,y,z;
   	 cin>>x>>y>>z;
   	 dis2[x][y]=dis2[y][x]=z;
   	 q.push((re){x,y,z});
   }  
   int cnt=0;
   while(!q.empty())
   {
   	  if(q.size()>3e7)
   	  {
   	  	rep(i,1,n)
   	  	  rep(j,1,n) g2[i][j]=0;
   	  	while(!q.empty())
   	  	{
   	  		re k=q.top(); q.pop();
   	  		g2[k.a][k.b]=g2[k.b][k.a]=1;
   	  	}
   	  	rep(i,1,n)
   	  	  rep(j,i+1,n) if (g2[i][j]) q.push((re){i,j,dis2[i][j]}); 
   	  }
   	  re k=q.top(); q.pop();
   	  int x=k.a,y=k.b;
   	  if (dis2[x][y]<0) break;
   	  if (g[x][y]) continue;
   	  g[x][y]=g[y][x]=1;
   	  rep(i,1,n)
   	    if (dis2[x][y]-dis[x][i]>dis2[i][y])
   	    {
   	    	dis2[i][y]=dis2[y][i]=dis2[x][y]-dis[x][i];
   	        q.push((re){i,y,dis2[i][y]});
   	    }
   	  rep(i,1,n)
   	    if (dis2[x][y]-dis[y][i]>dis2[x][i])
   	    {
   	      dis2[x][i]=dis2[i][x]=dis2[x][y]-dis[y][i];
   	      q.push((re){i,x,dis2[i][x]});
   	    }
   }
  // cerr<<cnt<<endl;
   int ans=0;
   rep(i,1,n)
     rep(j,1,n)
       if (p[i][j]&&dis3[i][j]<=dis2[i][j])
	   {
	     ans++;
	   }
   cout<<ans<<endl;
   return 0;
}