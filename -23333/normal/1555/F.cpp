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
const int N=2e6;
struct re{
	int a,b,c;
}a[N];
int fa[N],dfn[N],siz[N],sum[N],dep[N];
int cnt=0;
vector<re> ve[N];
int bz[500000][20];
void dfs(int x,int y)
{
	dfn[x]=++cnt; siz[x]=1; dep[x]=dep[y]+1;
	bz[x][0]=y;
	rep(i,1,19) bz[x][i]=bz[bz[x][i-1]][i-1];
	for (auto v:ve[x])
	if(v.a!=y)
	{
		sum[v.a]=sum[x]^v.b;
		dfs(v.a,x);
	    siz[x]+=siz[v.a];
    }
}
int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y); 
	dep(i,19,0)
	  if (dep[bz[x][i]]>=dep[y]) x=bz[x][i];
	if (x==y) return x;
	dep(i,19,0)
	  if (bz[x][i]!=bz[y][i]) x=bz[x][i],y=bz[y][i];
	return bz[x][0];
}
int n,m;
int p[N];
struct sgt{
  ll c1[N],c2[N]; 
  inline void update(ll x,ll k)
  {
    ll i=x;
    while(x<=n)
    {
        c1[x]+=k;
        c2[x]+=i*k;
        x+=x&-x;
    }
    return;
  }
  inline ll sum(ll x)
  {
    ll ans=0;
    ll i=x;
    while(x>0)
    {
        ans+=c1[x]*(i+1);
        ans-=c2[x];
        x-=x&-x;
    }
    return ans;
  }
   inline void change(int x,int y,ll z)
   {
  //     cerr<<x<<" "<<y<<endl;
      update(x,z);
      update(y+1,-z);
   }
   ll query(int x)
   {
      return sum(x)-sum(x-1);
   }
}S;
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
   ios::sync_with_stdio(false);
   read(n); read(m);
   rep(i,1,n) fa[i]=i;
   rep(i,1,m)
   {
   	 int x,y,z;
   	 read(x); read(y); read(z);
   	 a[i]=(re){x,y,z};
   	 int f1=find(x),f2=find(y);
   	 if (f1!=f2)
	 {
	 	p[i]=1;
	 	fa[f1]=f2;
	 	ve[x].push_back((re){y,z});
		ve[y].push_back((re){x,z}); 
	 }
   }
   rep(i,1,n)
     if (!dfn[i]) dfs(i,0);
   rep(i,1,m)
   {
   	 int x=a[i].a,y=a[i].b,z=a[i].c;
   	 int k=lca(x,y);
   	 if (p[i])
   	 {
   	 	cout<<"YES"<<endl;
   	 	continue;
   	 }
   	 if ((sum[x]^sum[y]^z)==1&&S.query(dfn[x])==S.query(dfn[k])&&S.query(dfn[y])==S.query(dfn[k]))
   	 {
   	 	while (x!=k)
   	 	{
   	 		S.change(dfn[x],dfn[x]+siz[x]-1,1);
   	 		x=bz[x][0];
   	 	}
   	 	while (y!=k)
   	 	{
   	 		S.change(dfn[y],dfn[y]+siz[y]-1,1);
   	 		y=bz[y][0];
   	 	}
   	 	cout<<"YES"<<endl;
   	 } else
   	 cout<<"NO"<<endl;
   }
   return 0;
}