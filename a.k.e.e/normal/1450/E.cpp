#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
const int MOD=1019260817;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=205,INF=0x3f3f3f3f;

int n;
vector<pii> G[MAXN];
int num[MAXN],dis[MAXN],q[MAXN*MAXN*MAXN],w[MAXN];
bool inq[MAXN];

bool spfa(int src)
{
    for(int i=1;i<=n;i++)dis[i]=INF;
    memset(inq,false,sizeof(inq));
    memset(num,0,sizeof(num));
    dis[src]=0;
    inq[src]=true;
    num[src]=1;
    int front=1,rear=0;
    q[++rear]=src;
    while(front<=rear)
    {
        int u=q[front++];
        if((abs(dis[u])&1)!=w[u]^w[src])--dis[u];
        inq[u]=false;
        for(auto p:G[u])
        {
            int v=p.x;
            if(dis[v]>dis[u]+p.y)
            {
                dis[v]=dis[u]+p.y;
                if(!inq[v])
                {
                    inq[v]=true;
                    q[++rear]=v;
                    num[v]++;
                    if(num[v]>=n)return 0;
                }
            }
        }
    }
    return 1;
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int E;
	readint(n),readint(E);
	while(E--)
	{
		int u,v,ty;
		readint(u),readint(v),readint(ty);
		if(ty)G[u].pb(mp(v,1)),G[v].pb(mp(u,-1));
		else G[u].pb(mp(v,1)),G[v].pb(mp(u,1));
	}
	int front=1,rear=0;
	memset(w,-1,sizeof(w));
	q[++rear]=1;w[1]=0;
	while(front<=rear)
	{
		int u=q[front++];
		for(auto p:G[u])
		{
			if(w[p.x]>=0){if(w[p.x]==w[u])return 0*printf("NO\n");}
			else
			{
				w[p.x]=w[u]^1;
				q[++rear]=p.x;
			}
		}
	}
	int d=-INF,r;
	for(int i=1;i<=n;++i)
	{
		if(!spfa(i))return 0*printf("NO\n");
		int maxx=-INF;
		for(int u=1;u<=n;++u)
		{
			for(auto p:G[u])
				if(!(abs(dis[p.x]-dis[u])&1))return 0*printf("NO\n");
			chkmax(maxx,dis[u]);
		}
		if(maxx>d)d=maxx,r=i;
	}
	spfa(r);
	printf("YES\n");
	printf("%d\n",d);
	for(int i=1;i<=n;++i)printf("%d ",dis[i]);
	return 0;
}