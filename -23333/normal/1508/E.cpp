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
vector<int> ve[N];
int cnt=0,now,cnt2=0;
int dep[N],a[N],b[N],gg[N];
ll ans=0;
bool tt=1;
void dfs(int x)
{
	for (auto v:ve[x])
	{
		dep[v]=dep[x]+1;
	     dfs(v);
	}
	cnt++;
	if (cnt<=now)
	{
		if (a[x]!=cnt) tt=0;
		ans+=dep[x];
		gg[x]=1;
	}
}
void p(int x)
{
	if (!gg[x]) 
	{ 
	  cnt++; 
	  if (cnt!=a[x]) tt=0;
    }
    b[x]=++cnt2;
	for (auto v:ve[x])
	{
		p(v);
	}
}
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
void gao(int x)
{
	for (auto v:ve[x])
	{
		if (a[v]>a[x])
		{
			ans--;
			swap(a[v],a[x]);
			gao(v);
			break;
		}
    }
}
int main()
{
   ios::sync_with_stdio(false);
   int n;
   cin>>n;
   rep(i,1,n) cin>>a[i];
   rep(i,1,n-1)
   {
   	int x,y;
   	 cin>>x>>y;
   	 ve[x].push_back(y);
   }
   rep(i,1,n)
     sort(ve[i].begin(),ve[i].end(),cmp);
   now=a[1]-1;
   if (now)
   {
   	 int pos;
   	 rep(i,1,n) if(a[i]==now) pos=i;
   	 gao(pos);
   }
   dfs(1);
   cnt=now; p(1);
   if (tt)
   {
   	  cout<<"YES"<<endl;
      cout<<ans<<endl;
      rep(i,1,n) cout<<b[i]<<" "; 
   }
   else cout<<"NO"<<endl;
   return 0;
}