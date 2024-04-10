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
#define mep(x,y) memcpy(x,y,sizeof(y))
#define IL inline
#define rint register int
#define mp make_pair
#define fi first
#define se second
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
const int N=3100;
re e[N*2],e2[N*2];
int l;
int head[N];
void arr(int x,int y)
{
	e[++l].a=head[x];
	e[l].b=y;
	e[l].c=0;
	head[x]=l;
}
int num[N],g[N];
int cnt,n,m;
int vis[N];
vector<int> ans;
void tu(int l,int z)
{
	e[l].c=e[l^1].c=z;
}
void gg(int x,int k)
{
	vis[x]=k;
	for(int u=head[x];u;u=e[u].a)
    if (e[u].c==0)
	{
		int v=e[u].b;
		tu(u,1);
		gg(v,k);
	}
	ans.push_back(x);
}
bool pd(int x)
{
	int now=ans.size();
	ans.push_back(-1); 
	for (int u=head[x];u;u=e[u].a)
	if (e[u].c==2)
	{
		int v=e[u].b;
		now++;
		ans.push_back(v),ans.push_back(x);
    }
    if (now-1!=m)
    {
    	ans.clear();
    	return 0;
    }
    cout<<ans.size()<<endl;
    for (auto v:ans)
    {
    	cout<<v<<" ";
    }
	return 1;
}
int gao(int x)
{
	me(vis); me(g);
	rep(i,1,l) e[i].c=0;
	int cnt2=0;
	for (int u=head[x];u;u=e[u].a)
	{
		int v=e[u].b;
		if (num[v]%2==1) cnt2++;
	}
	if (num[x]%2==1) cnt2++;
	if (cnt>=cnt2+2) return 0;
	if (cnt!=cnt2)
	{
	   for (int u=head[x];u;u=e[u].a)
	   {
	   	 int v=e[u].b;
	     if (num[v]%2==1) tu(u,2);
	   }
	   gg(x,1);
	   return pd(x);
    } else
    {
      for (int u=head[x];u;u=e[u].a)
	   {
	   	 int v=e[u].b;
	     if (num[v]%2==1) { tu(u,2); if (num[v]==1) vis[v]=3;}
	   }
	  mep(e2,e);
	  int cnt=0;
	  rep(i,1,n) if (!vis[i]) gg(i,++cnt);
	  mep(e,e2);
	  ans.clear();
	  if (cnt>2)
	  {
	    return 0;
	  }
	  if (cnt==1)
	  {
	  	me(vis);
	  	gg(x,1);
	  	return pd(x);
	  } else
	  {
	  	for (int u=head[x];u;u=e[u].a)
	    {
	   	 int v=e[u].b;
	     if (num[v]%2==1&&vis[x]!=vis[v]&&vis[v]!=3)
	     {
	    	me(vis);
	    	tu(u,0);
	    	gg(x,1);
	    	return pd(x);
	     }
	    }
	    
	    return 0;
      }
  }
  return 0;
}
int main()
{
   ios::sync_with_stdio(false);
   cin>>n>>m;
   l=1;
   rep(i,1,m)
   {
   	 int x,y;
   	 cin>>x>>y;
   	 arr(x,y); arr(y,x);
	 num[x]++; num[y]++; 
   }
   int t=1;
   rep(i,1,n) if (num[i]%2==1) cnt++,t=i;
   if (cnt<=2)
   {
   	 gg(t,1); pd(1);
   	 return 0;
   }
   rep(i,1,n) 
     if (gao(i)) return 0;
   cout<<0<<endl;
   return 0;
}