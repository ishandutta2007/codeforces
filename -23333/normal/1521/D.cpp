#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

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
int T;
int f[N];
vector<int> ve[N],vee[N][3];
vector<re> ve1,ve2;
re dfs(int x,int y,int z)
{
	int tt=z;
	int now=x,now2=x;
	int g[3];
	g[0]=g[1]=g[2]=0;
	for (auto v:vee[x][z])
	{
		now=dfs(v,x,1).a;
		g[tt]=v;
		if (tt==2)
		{ 
			now2=now;
			now=x;
		}
		tt--;
	}
	for (auto v:ve[x])
	{
		if (v!=y&&v!=g[2]&&v!=g[1])
		{
				ve1.push_back((re){x,v});
				re now2=dfs(v,x,2);
				ve2.push_back((re){now,now2.a});
				now=now2.b;
		}
	}
	return (re){now,now2};
}
int ans[N][3];
void dfs2(int x,int y,int z)
{
	ans[x][z]=0; int now=z; vee[x][z].clear();
	for (auto v:ve[x])
	{
		if (v!=y)
		{
			if (z==2)
			{
			  dfs2(v,x,2);
			  dfs2(v,x,1);
		    }
			if (ans[v][2]<ans[v][1])
			{
				ans[x][z]+=ans[v][2]+1;
			} else
			{
				if (now>0)
				{
					ans[x][z]+=ans[v][1];
					now--;
					vee[x][z].push_back(v);
				} else ans[x][z]+=ans[v][1]+1;
			}
		}
	}
}
int main()
{
   ios::sync_with_stdio(false); cin.tie(0);
   cin>>T;
   int cnt=0;
   while (T--)
   {
   	cnt++;
   	int n;
   	 cin>>n;
   	 rep(i,1,n-1)
   	 {
   	 	int x,y;
   	 	cin>>x>>y;
   	 	ve[x].push_back(y); ve[y].push_back(x);
   	 	f[x]++; f[y]++;
   	 }
   	 dfs2(1,0,2);
   	 dfs(1,0,2);
   	 printf("%d\n",ve1.size());
   	 for (int i=0;i<ve1.size();i++)
   	 {
   	 	auto u=ve1[i],v=ve2[i];
   	 	printf("%d %d %d %d\n",u.a,u.b,v.a,v.b);
   	 }
   	 ve1.clear(); ve2.clear();
   	 rep(i,1,n) f[i]=0,ve[i].clear();
   }
   return 0;
}