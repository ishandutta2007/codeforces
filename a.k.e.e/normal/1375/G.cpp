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
const int MAXN=200005;

int n;
vector<int> G[MAXN];
int dep[MAXN],cnt[2];
void dfs(int u,int pa)
{
	++cnt[dep[u]];
	for(auto v:G[u])
		if(v!=pa)
		{
			dep[v]=dep[u]^1;
			dfs(v,u);
		}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int u,v;
	readint(n);
	for(int i=1;i<n;++i)
	{
		readint(u),readint(v);
		G[u].pb(v),G[v].pb(u);
	}
	dfs(1,-1);
	printf("%d\n",min(cnt[0],cnt[1])-1);
	return 0;
}