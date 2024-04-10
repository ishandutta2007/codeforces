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
const int MAXN=200005;

int n,mx,my;
char res[MAXN];
vector<pii> a[MAXN],b[MAXN];
vector<int> G[MAXN];
int col[MAXN];
void dfs(int u)
{
	for(auto v:G[u])
		if(!col[v])
		{
			col[v]=3-col[u];
			dfs(v);
		}
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
	#endif
	int x,y;
	readint(n);
	for(int i=1;i<=n;++i)
	{
		readint(x),readint(y);
		a[x].pb(mp(y,i));
		b[y].pb(mp(x,i));
		chkmax(mx,x),chkmax(my,y);
	}
	for(int i=1;i<=mx;++i)
		for(int j=1;j<(int)a[i].size();j+=2)
			G[a[i][j].y].pb(a[i][j-1].y),G[a[i][j-1].y].pb(a[i][j].y);
 	for(int i=1;i<=my;++i)
		for(int j=1;j<(int)b[i].size();j+=2)
			G[b[i][j].y].pb(b[i][j-1].y),G[b[i][j-1].y].pb(b[i][j].y);
	for(int i=1;i<=n;++i)
		if(!col[i])col[i]=1,dfs(i);
	for(int i=1;i<=n;++i)
		putchar(col[i]==1?'r':'b');
   return 0;
}