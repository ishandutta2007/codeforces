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
const int MAXN=500005;

int n,m,s1,s2,k,u[MAXN],v[MAXN],fa[MAXN],size[MAXN];
int getfa(int u){return u==fa[u]?u:fa[u]=getfa(fa[u]);}
void onion(int u,int v)
{
	u=getfa(u),v=getfa(v);
	if(u==v)return;
	fa[u]=v;size[v]+=size[u];
}
void solve()
{
	readint(n),readint(m),readint(s1),readint(s2);
	for(int i=1;i<=m;++i)readint(u[i]),readint(v[i]);
	int sum1=0,sum2=0;
	for(int i=1;i<=n;++i)fa[i]=i,size[i]=1;
	for(int i=1;i<=m;++i)if(u[i]!=s1 && v[i]!=s1)onion(u[i],v[i]);
	for(int i=1;i<=n;++i)if(getfa(i)==i && getfa(s2)!=i && s1!=i)sum1+=size[i];
	
	for(int i=1;i<=n;++i)fa[i]=i,size[i]=1;
	for(int i=1;i<=m;++i)if(u[i]!=s2 && v[i]!=s2)onion(u[i],v[i]);
	for(int i=1;i<=n;++i)if(getfa(i)==i && getfa(s1)!=i && s2!=i)sum2+=size[i];

	cout<<1ll*sum1*sum2<<endl;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}