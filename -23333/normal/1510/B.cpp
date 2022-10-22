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
struct re{
	int a,b,c;
};
char s[20];
const int N=2100;
#define lowbit(x) (x&(-x))
int a[N],f[N],fa[N],n,m;
bool g[N],gao[N];
char p[N*100];
int cnt=0;
bool cmp(int x,int y)
{
	return f[x]<f[y];
}
const int inf=1e9;
int ans=0,dis[N*2],fl[N*2],head[N*2],pre[N*2],tot=1;
bool vis[N*2];
queue<int> q;
struct edge{int n,to,l,f;}e[N*100];
inline void add(int u,int v,int l,int f){
	e[++tot].n=head[u];e[tot].to=v;head[u]=tot;e[tot].l=l;e[tot].f=f;
	e[++tot].n=head[v];e[tot].to=u;head[v]=tot;e[tot].l=0;e[tot].f=-f;
}
bool spfa(int s,int t){
	memset(dis,0x3f,sizeof(dis));
	q.push(s);dis[s]=0;fl[s]=inf;
	while(!q.empty()){
		int u=q.front();q.pop();vis[u]=0;
		for(int i=head[u];i;i=e[i].n){
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].f&&e[i].l){
				dis[v]=dis[u]+e[i].f;fl[v]=min(fl[u],e[i].l);pre[v]=i;
				if(!vis[v]){vis[v]=1;q.push(v);}
			}
		}
	}
//	cout<<dis[t]<<" ";
	return dis[t]<=1e9;
}
inline void calc(int s,int t){
	int x=t;
	while(x!=s){
		int i=pre[x];
		e[i].l-=fl[t];e[i^1].l+=fl[t];
		x=e[i^1].to;
	}
	ans+=dis[t]*fl[t];
}
void pr(int x,int y)
{
	gao[x]=1;
	if (fa[x]) pr(fa[x],0);
	int tt=a[x]^a[fa[x]];
	rep(i,1,n) if ((tt>>(i-1))&1) p[++cnt]='0'+n-i; 
	if(y==1) p[++cnt]='R';
}
int main()
{
   ios::sync_with_stdio(false);
   cin>>n>>m;
   rep(i,1,m)
   {
   	 cin>>(s+1);
   	 rep(j,1,n) a[i]=a[i]*2+s[j]-'0';
   }
   rep(i,1,2000) f[i]=f[i-lowbit(i)]+1;
   sort(a+1,a+m+1,cmp);
   rep(i,1,m)
   {
   	 dep(j,i-1,1) if ((a[i]&a[j])==a[j])
   	 {
   	 	add(j,i+m,1,f[a[i]^a[j]]);
   	 }
   	 add(0,i+m,1,f[a[i]]);
   	 add(i+m,2*m+1,1,0);
   	 add(0,i,1,0); 
   }
   while (spfa(0,2*m+1))
   {
     calc(0,2*m+1);
   }
   rep(i,0,m)
     for (int u=head[i];u;u=e[u].n)
     {
     	int v=e[u].to;
     	if (e[u].l==0&&v>=m)
     	  fa[v-m]=i;
     }
   dep(i,m,1)
     if (!gao[i]) pr(i,1);
   cout<<cnt-1<<endl;
   rep(i,1,cnt-2) cout<<p[i]<<" ";
   cout<<p[cnt-1]<<endl;
   return 0;
}