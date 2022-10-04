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
template <typename T> void chkmin(T &x,T y){x>y?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
const int MAXN=300005;

int n;
vector<int> G[MAXN];
int q[MAXN],vis[MAXN];
void solve()
{
	int E;
	readint(n),readint(E);
	for(int i=1;i<=n;++i)G[i].clear(),vis[i]=0;
	while(E--)
	{
		int u,v;
		readint(u),readint(v);
		G[u].pb(v),G[v].pb(u);
	}
	int front=1,rear=0,cnt=0;
	q[++rear]=1;vis[1]=1;
	while(front<=rear)
	{
		int u=q[front++];
		for(auto v:G[u])
		{
			if(!vis[v])q[++rear]=v,vis[v]=1;
			if(vis[u]==1)vis[v]=2;
		}
		if(vis[u]==1)++cnt;
	}
	if(rear==n)
	{
		printf("YES\n%d\n",cnt);
		for(int i=1;i<=n;++i)if(vis[i]==1)printf("%d ",i);
		putchar('\n');
	}
	else printf("NO\n");
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}