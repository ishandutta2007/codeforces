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
const int N=200;
int head[N],tot,cur[N],deep[N];
struct node{int n,to,l;} e[N*N*2];
inline void add(int u,int v,int l){
	e[++tot].n=head[u];e[tot].to=v;head[u]=tot;e[tot].l=l;
	e[++tot].n=head[v];e[tot].to=u;head[v]=tot;e[tot].l=0;
}
inline bool bfs(int s,int t){
	queue<int> q;
	memset(deep,0,sizeof(deep));
	memcpy(cur,head,sizeof(head));
	q.push(s);deep[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i;i=e[i].n){
			int v=e[i].to;
			if(e[i].l>0&&!deep[v]){
				deep[v]=deep[u]+1;q.push(v); 
			}
		}
	}
	return deep[t];
}
int dfs(int u,int t,int l){
	if(u==t||!l)return l;
	int f,flow=0;
	for(int &i=cur[u];i;i=e[i].n){
		int v=e[i].to;
		if(deep[v]==deep[u]+1&&(f=dfs(v,t,min(l,e[i].l)))){
			e[i].l-=f;e[i^1].l+=f;l-=f;flow+=f;
			if(!l)break;
		}
	}
	return flow;
}
int S,T,n,m,k;
ll a[N],b[N];
ll dp[N][N]; 
int p[N][N];
int main()
{
   ios::sync_with_stdio(false);
   cin>>n>>m>>k;
   S=0,T=2*n+1; tot=1;
   rep(i,1,n) add(S,i,1),add(i+n,T,1);
   rep(i,1,m)
   {
   	 int x,y;
   	 cin>>x>>y;
   	 add(x,y+n,1);
   }
   int ans=0; 
   while (bfs(S,T)) ans+=dfs(S,T,1e9);
   int now=n-ans;
   if (now>k)
   {
   	cout<<k<<endl;
   	 rep(i,1,k) cout<<0<<" ";
   	 return 0;
   } 
   int gg=k-now+1;
   vector<int> ve;
   rep(i,1,n)
   {
     if (!deep[i]) ve.push_back(i);
     if (deep[i+n]) ve.push_back(-i);
   }
   random_shuffle(ve.begin(),ve.end()); 
   rep(i,1,k) cin>>a[i]>>b[i];
   rep(i,1,k) dp[0][i]=-1e18;
   rep(i,1,k)
   {
     rep(j,0,gg) dp[i][j]=-1e18;
     rep(j,max(0,i-now+1),gg)
       rep(t,0,j)
       {
       	 ll now=dp[i-1][j-t]+max(0ll,a[i]-t*b[i]);
     	 if (now>dp[i][j])
     	 {
     		dp[i][j]=now;
     		p[i][j]=j-t;
     	 }
       }
   }
   now=gg;
   vector<int> ve2;
   dep(i,k,1)
   {
   	 int g=now-p[i][now];
   	 ve2.push_back(0);
   	 while(g--) ve2.push_back(ve.back()),ve.pop_back();
	 now=p[i][now]; 
   }
   cout<<ve2.size()<<endl;
   reverse(ve2.begin(),ve2.end());
   for (auto v:ve2) cout<<v<<" ";
   return 0; 
}