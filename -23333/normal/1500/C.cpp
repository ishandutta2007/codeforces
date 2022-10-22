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
#define pb push_back 
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
const int mo=19260817;
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

#define ull unsigned long long

const int N=2000;
struct re{
	ull a,b,c;
}p1[N],p2[N];
int a[N][N],b[N][N],pos[N],dy[N],cnt[N];
vector<int> ve[N]; 
queue<int> q;
ull g1[N],g2[N],g3[N]; 
bool cmp(re x,re y)
{
	if(x.a!=y.a) return x.a<y.a;
	return x.b<y.b;
}
int main()
{
   ios::sync_with_stdio(false);
   int n,m;
   cin>>n>>m;
   rep(i,1,n)
   {
   	 ull ans=0;
     rep(j,1,m)
	 { 
	   cin>>a[i][j];
       ans=ans*mo+a[i][j];
     }
     g1[i]=ans;
   }
   rep(i,1,n)
   {
   	 ull ans=0;
     rep(j,1,m) 
     {
	   cin>>b[i][j];
	   ans=ans*mo+b[i][j];
     }
	 g2[i]=ans;
   }
   memcpy(g3,g2,sizeof(g2));
   rep(i,1,n) p1[i].a=g1[i],p1[i].b=p2[i].b=i,p2[i].a=g2[i];
   sort(p1+1,p1+n+1,cmp);
   sort(p2+1,p2+n+1,cmp);
   bool tt=1;
   rep(i,1,n)
   { 
     if (p1[i].a!=p2[i].a) tt=0;
     dy[p2[i].b]=p1[i].b;
   }
   if (!tt)
   {
   	cout<<-1<<endl;
   	return 0;
   }
   rep(j,1,m)
   {
     rep(i,2,n)
     {
   	   if (b[i][j]<b[i-1][j]) ve[i].pb(j),cnt[j]++;
     }
     if (!cnt[j]) q.push(j);
   }
   vector<int> ans;
   while(!q.empty())
   {
   	 int x=q.front(); q.pop();
   	 ans.push_back(x);
   	 rep(i,2,n)
   	   if (b[i][x]>b[i-1][x]&&!pos[i])
   	   {
   	   	 pos[i]=1;
   	   	 for(auto v:ve[i])
	     { 
			cnt[v]--;
			if (!cnt[v]) q.push(v);
	 	 }
   	   }
   }
   rep(i,2,n)
     if (!(dy[i]>dy[i-1]||pos[i])) tt=0;
   if (!tt)
   {
   	cout<<-1<<endl;
   	return 0;
   }
   cout<<ans.size()<<endl;
   reverse(ans.begin(),ans.end());
   for(auto i:ans)
   {
   	cout<<i<<" ";
   }
   return 0;
}