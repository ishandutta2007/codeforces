#include<bits/stdc++.h>
using namespace std;
#define db double
#define mp make_pair 
const int N=100005;
const db inf=1e10;
int n,m,q,Eu[N],Ev[N],all[N],vis[N];vector<int>V;
map<pair<int,int>,int>F,S;
struct P{db x,y;}p[N];
inline P operator+(const P&a,const P&b){return (P){a.x+b.x,a.y+b.y};}
inline P operator-(const P&a,const P&b){return (P){a.x-b.x,a.y-b.y};}
inline db operator*(const P&a,const P&b){return a.x*b.y-b.x*a.y;}
inline db operator/(const P&b,const P&a){return atan2(b.y-a.y,b.x-a.x);}
inline bool operator<(const P&a,const P&b){return a.x!=b.x?a.x<b.x:a.y<b.y;}
inline db crs(P p,P a,P b){return (a-p)*(b-p);}
struct E{int v;db a;};
inline bool operator<(const E&a,const E&b){return a.a<b.a;}
vector<E>G[N];
inline void add(int u,int v){G[u].push_back((E){v,p[v]/p[u]});F[make_pair(u,v)]=0;}
int dfs(int x,int p)
{
	vis[x]=1;int s=1;
	for(int i=0;i<G[x].size();i++){int y=G[x][i].v;if(!vis[y])s+=dfs(y,x);}
	if(p){F[mp(p,x)]+=s;F[mp(x,p)]-=s;}
	return s;
}
inline int calc(int a,int b,int c){return ((p[b]/p[a])<(p[c]/p[a])?0:all[a])+S[mp(a,c)]-S[mp(a,b)]-F[mp(a,c)];}
int main()
{
	scanf("%d%d",&n,&m);int T=n+1;p[T]=(P){-inf,0};
	for(int i=1;i<=m;i++)scanf("%d%d",&Eu[i],&Ev[i]);
	for(int i=1;i<=n;i++)scanf("%lf%lf",&p[i].x,&p[i].y);
	for(int i=1;i<=m;i++)add(Eu[i],Ev[i]),add(Ev[i],Eu[i]);
	int x=1;for(int i=2;i<=n;i++)if(p[i]<p[x])x=i;
	add(T,x);add(x,T);dfs(T,0);
	for(int i=1;i<=n+1;i++)sort(G[i].begin(),G[i].end());
	for(int i=1;i<=n+1;i++)
	{
		int x=i;S[mp(i,i)]=0;
		for(int j=0;j<G[i].size();j++){int y=G[i][j].v;all[i]+=F[mp(i,y)];S[mp(i,y)]=S[mp(i,x)]+F[mp(i,y)];x=y;}
	}
	scanf("%d",&q);
	while(q--)
	{
		int k;scanf("%d",&k);V.clear();
		for(int i=1,x;i<=k;i++)scanf("%d",&x),V.push_back(x);
		int ans=0,cc=V.size();db s=0;p[0]=(P){0,0};
		for(int i=0;i<cc;i++)s+=crs(p[0],p[V[i?i-1:cc-1]],p[V[i]]);
		if(s>0)reverse(V.begin(),V.end());
		for(int i=0;i<cc;i++)ans+=calc(V[i],V[i?i-1:cc-1],V[(i+1)%cc]);
		printf("%d\n",ans+cc);
	}
	return 0;
}