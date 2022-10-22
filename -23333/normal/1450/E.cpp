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
const int N=2e5;
bool vis[N],g[N];
bool tt=1;
int dis[300][300];
vector<int> ve[N]; 
void dfs(int x)
{
	vis[x]=1;
	for (auto v:ve[x])
	{
		if (vis[v])
		{
			if ((g[v]^g[x])!=1) tt=0;
		} else
		{
			g[v]=g[x]^1;
			dfs(v);
		}
    }
}
int main()
{
//   freopen("1.in","r",stdin);
//   freopen("1.out","w",stdout);
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n,m;
   cin>>n>>m;
   rep(i,1,n)
     rep(j,1,n) if(i!=j) dis[i][j]=1e9;
   rep(i,1,m)
   {
   	 int x,y,z;
     cin>>x>>y>>z;
	 ve[x].push_back(y); ve[y].push_back(x);
     dis[x][y]=1;
     if (z==0) dis[y][x]=1; else dis[y][x]=-1;
   }
   dfs(1);
   rep(k,1,n)
     rep(i,1,n)
       rep(j,1,n)
         if (dis[i][k]+dis[k][j]<dis[i][j])
         {
         	dis[i][j]=dis[i][k]+dis[k][j];
         }
    rep(i,1,n)
      if (dis[i][i]<0) tt=0;
    int now=0,jl=0;
    if (!tt)
    {
    	cout<<"NO"<<endl;
    	return 0;
    }
    rep(i,1,n)
      rep(j,1,n)
        if (dis[i][j]>now)
        {
        	now=dis[i][j]; jl=i;
        }
    cout<<"YES"<<endl;
    cout<<now<<endl;
    rep(i,1,n)
      cout<<dis[jl][i]<<" ";
    cout<<endl;
   return 0;
}