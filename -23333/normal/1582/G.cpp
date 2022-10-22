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
	if (y==0) return 1;
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
const int N=1e6+10;
int vis[N];
int a[N];
char s[N];
vector<re> ve[N],ve2[N],ve3[N];
re st[N];
int h[N],now[N];
int main()
{
   ios::sync_with_stdio(false);
   int n;
   cin>>n;
   rep(i,1,n) cin>>a[i];
   cin>>(s+1);
   rep(i,1,n)
     if (s[i]=='/'&&a[i]==1) s[i]='*';
   int m=1e6;
   rep(i,2,m)
     for (int j=i;j<=m;j+=i)
	   if (!vis[j]) {vis[j]=i;}
   rep(i,2,m)
   {
     if (vis[i])
     {
	   ve[i]=ve[i/vis[i]];
	   if (ve[i].size()>0&&ve[i].back().a==vis[i]) ve[i].back().b++;
	   else ve[i].push_back((re){vis[i],1});
     }
   }
   dep(i,n,1)
     for (auto v:ve[a[i]])
     {
     	if (s[i]=='*') ve2[v.a].push_back((re){i,v.b});
     	else  ve2[v.a].push_back((re){i,-v.b}); 
     }
   rep(i,1,m)
   {
   	 int sum=0,t=0;
   	 st[0].b=n+1;
   	 int cnt=-1;
   	 if (ve2[i].size()>0) st[++t]=(re){sum,ve2[i][0].a};
   	 for (auto v:ve2[i])
   	 {
   	 	sum+=v.b;
   	 	while (t>0&&sum>=st[t].a) t--;
   	 	ve3[v.a].push_back((re){i,st[t].b});
   	 //	cerr<<v.a<<" "<<i<<" "<<st[t].b<<endl;
   	 	cnt++;
   	 	if (cnt!=ve2[i].size()-1)
		  st[++t]=(re){sum,ve2[i][cnt+1].a};
   	 }
   }
   ll ans=0;
   h[n+1]=n;
   rep(i,1,m) now[i]=1e9;
   dep(i,n,1)
   {
     for (auto v:ve3[i])
       now[v.a]=v.b;
     if (s[i]=='*')
     {
     	h[i]=h[i+1];
     	while (1)
     	{
     		if (h[i]==n) break;
     		int vv=a[h[i]+1];
     		bool tt=1;
     		for (auto v:ve[vv])
              if (now[v.a]<=h[i]+1) tt=0;
            if (!tt) break;
            h[i]=h[h[i]+2];
     	}
     } else h[i]=i-1;
     ans+=(h[i]-i+1);
   }
   cout<<ans<<endl;
   return 0;
}