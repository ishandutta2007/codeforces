#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=205,dir[4][2]={1,1,1,-1,-1,-1,-1,1};

int n,m,MOD;
pii fa[MAXN][MAXN];
pii getfa(pii u){return fa[u.x][u.y]==u?u:fa[u.x][u.y]=getfa(fa[u.x][u.y]);}
inline void onion(pii u,pii v)
{
	u=getfa(u),v=getfa(v);
	if(u==v)exit(0*printf("0\n"));
	fa[u.x][u.y]=v;
}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
char s[MAXN][MAXN];
int id[MAXN][MAXN],cnt,G[MAXN][MAXN];
int gauss(int n)
{
	if(!n)return 1;
	int pos=0;
	for(int i=1;i<=n;++i)if(G[i][n]){pos=i;break;}
	if(!pos)return 0;
	for(int i=1;i<=n;++i)swap(G[pos][i],G[n][i]);
	int inv=qmi(G[n][n],MOD-2);
	for(int i=1;i<n;++i)
		for(int j=1;j<n;++j)
			G[i][j]=(G[i][j]-1ll*G[i][n]*inv%MOD*G[n][j]%MOD+MOD)%MOD;
	if(n!=pos)return 1ll*(MOD-1)*G[n][n]%MOD*gauss(n-1)%MOD;
	return 1ll*G[n][n]*gauss(n-1)%MOD;
}
int solve(int give)
{
	cnt=0;
	memset(id,0,sizeof(id));
	memset(G,0,sizeof(G));
	for(int i=0;i<=n;++i)
		for(int j=0;j<=m;++j)
			if(((i^j)&1)==give && getfa(mp(i,j))==mp(i,j))id[i][j]=++cnt;
	for(int i=0;i<=n;++i)
		for(int j=0;j<=m;++j)
		{
			if(((i^j)&1)!=give)continue;
			pii pr=getfa(mp(i,j));
			int hij=id[pr.x][pr.y];
			for(int k=0;k<2;++k)
			{
				int x=i+dir[k][0],y=j+dir[k][1];
				if(x<0 || x>n || y<0 || y>m)continue;
				if(s[max(i,x)][max(j,y)]!='*')continue;
				pr=getfa(mp(x,y));
				int hxy=id[pr.x][pr.y];
				--G[hij][hxy];--G[hxy][hij];
				++G[hij][hij];++G[hxy][hxy];
			}
		}
	for(int i=1;i<=cnt;++i)
		for(int j=1;j<=cnt;++j)
			G[i][j]=(G[i][j]%MOD+MOD)%MOD;
	return gauss(cnt-1);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(m),readint(MOD);
	for(int i=0;i<=n;++i)
		for(int j=0;j<=m;++j)
			fa[i][j]=mp(i,j);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;++j)
			if(s[i][j]=='\\')onion(mp(i,j),mp(i-1,j-1));
			else if(s[i][j]=='/')onion(mp(i,j-1),mp(i-1,j));
	}
	printf("%d\n",(solve(0)+solve(1))%MOD);
	return 0;
}