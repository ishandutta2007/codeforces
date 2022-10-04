#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<pii,pii> ppp;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
const int MOD=998244353;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=200005,MAXK=21;

int n;
vector<int> G[2][MAXN];
int dis[MAXK][MAXN];
priority_queue<pii,vector<pii>,greater<pii> > pq;
priority_queue<ppp,vector<ppp>,greater<ppp> > q;
pii f[2][MAXN];

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int E,u,v;
	readint(n),readint(E);
	while(E--)readint(u),readint(v),G[0][u].pb(v),G[1][v].pb(u);
	int ans=0x3f3f3f3f;
	memset(dis,0x3f,sizeof(dis));
	dis[0][1]=0;
	for(int i=0;i<MAXK;++i)
	{
		if(i)for(int j=1;j<=n;++j)dis[i][j]=dis[i-1][j]+(1<<(i-1));
		while(!pq.empty())pq.pop();
		for(int j=1;j<=n;++j)pq.push(mp(dis[i][j],j));
		while(!pq.empty())
		{
			int d=pq.top().x,u=pq.top().y;pq.pop();
			if(dis[i][u]!=d)continue;
			for(auto v:G[i&1][u])
				if(dis[i][v]>d+1)
					dis[i][v]=d+1,
					pq.push(mp(dis[i][v],v));
		}
		chkmin(ans,dis[i][n]);
	}
	if(ans!=0x3f3f3f3f)return 0*printf("%d\n",ans);
	memset(f,0x3f,sizeof(f));
	f[0][1]=mp(0,0);
	q.push(mp(f[0][1],mp(0,1)));
	while(!q.empty())
	{
		pii u=q.top().y,d=q.top().x;q.pop();
		if(f[u.x][u.y]!=d)continue;
		for(auto v:G[u.x][u.y])
			if(f[u.x][v]>mp(f[u.x][u.y].x,f[u.x][u.y].y+1))
				f[u.x][v]=mp(f[u.x][u.y].x,f[u.x][u.y].y+1),
				q.push(mp(f[u.x][v],mp(u.x,v)));
		if(f[u.x^1][u.y]>mp(f[u.x][u.y].x+1,f[u.x][u.y].y))
			f[u.x^1][u.y]=mp(f[u.x][u.y].x+1,f[u.x][u.y].y),
			q.push(mp(f[u.x^1][u.y],mp(u.x^1,u.y)));
	}
	pii r=min(f[0][n],f[1][n]);
	printf("%d\n",dmy(qmi(2,r.x)+r.y-1));
	return 0;
}