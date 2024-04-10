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
#define mid ((h+t)>>1)
const int N=5e5;
struct sgt{
	int lazy[N*4];
	void change(int x,int h,int t,int h1,int t1,int k)
	{
		if(h1<=h&&t<=t1)
		{ 
		  lazy[x]=k; return;
	    }
		if (h1<=mid) change(x*2,h,mid,h1,t1,k);
		if (mid<t1) change(x*2+1,mid+1,t,h1,t1,k);
	}
	int query(int x,int h,int t,int pos)
	{
	//	cerr<<x<<" "<<h<<" "<<t<<" "<<pos<<endl;
		if (lazy[x]) return lazy[x];
		if(h==t) return 0;
		if (pos<=mid) return query(x*2,h,mid,pos);
		else return query(x*2+1,mid+1,t,pos); 
	}
}S;
struct sgt2{
	int lazy[N*4];
	void change(int x,int h,int t,int pos,int k)
	{
		lazy[x]+=k;
		if(h==t) return ;
		if (pos<=mid) change(x*2,h,mid,pos,k);
		else change(x*2+1,mid+1,t,pos,k);
	}
	int query(int x,int h,int t,int h1,int t1)
	{
	  if (h1<=h&&t<=t1) return lazy[x];
	  int ans=0;
	  if (h1<=mid) ans+=query(x*2,h,mid,h1,t1);
	  if (mid<t1) ans+=query(x*2+1,mid+1,t,h1,t1);
	  return ans;
	}
}S2;
vector<int> ve1[N],ve2[N];
int num[N],size[N],cnt,n;
void dfs(int x,int y)
{
	num[x]=++cnt; size[x]=1;
	for(auto v:ve1[x])
	if (v!=y)
	{
		dfs(v,x);
		size[x]+=size[v];
	}
}
ll ans=0,ans2=0;
void dfs2(int x,int y)
{
	int t=S.query(1,1,n,num[x]),t2=S2.query(1,1,n,num[x],num[x]+size[x]-1);
	if(t2==0)
	{
	  if (t)
	  {
	  	ans2--;
		S.change(1,1,n,num[t],num[t]+size[t]-1,0);
	  }
	  ans2++;
	  S.change(1,1,n,num[x],num[x]+size[x]-1,x);
	  S2.change(1,1,n,num[x],1);
    }
    ans=max(ans,ans2);
	for(auto v:ve2[x])
	if (v!=y)
	{
		dfs2(v,x);
	}
	if (t2==0)
	{
		S2.change(1,1,n,num[x],-1);
		S.change(1,1,n,num[x],num[x]+size[x]-1,0);
		if(t)
		{
			ans2++;
			S.change(1,1,n,num[t],num[t]+size[t]-1,t);
		}
		ans2--;
	}
}
int main()
{
   ios::sync_with_stdio(false);
   int T;
   cin>>T; 
   while(T--)
   {
   	 cnt=0;
   	 cin>>n; ans=0;
   	 int x;
   	 rep(i,2,n)
   	 {
   	 	 cin>>x;
   	 	 ve2[x].push_back(i);
   	 }
   	 rep(i,2,n)
   	 {
   	 	 cin>>x;
   	 	 ve1[x].push_back(i);
   	 }
   	 dfs(1,0);
   	 dfs2(1,0);
   	 cout<<ans<<endl;
   	 rep(i,1,n*4) S.lazy[i]=0,S2.lazy[i]=0;
   	 rep(i,1,n) ve1[i].clear(),ve2[i].clear();
   }
   return 0;
}