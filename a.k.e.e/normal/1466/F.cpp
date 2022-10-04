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
const int MOD=1000000007;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=500005;

int n,m,fa[MAXN],col[MAXN];
bool res[MAXN];
int getfa(int u){return u==fa[u]?u:fa[u]=getfa(fa[u]);}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int ty,u,v;
	readint(m);readint(n);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		readint(ty),readint(u);
		if(ty==1)
		{
			u=getfa(u);
			if(!col[u])col[u]=i,res[i]=1;
		}
		else
		{
			readint(v);
			u=getfa(u),v=getfa(v);
			if(u!=v && (!col[u] || !col[v]))
			{
				fa[u]=v;
				res[i]=1;
				col[v]+=col[u];
			}
		}
	}
	int s=1,c=0;
	for(int i=1;i<=m;++i)if(res[i])s=dmy(s<<1),++c;
	printf("%d %d\n",s,c);
	for(int i=1;i<=m;++i)if(res[i])printf("%d ",i);
	return 0;
}