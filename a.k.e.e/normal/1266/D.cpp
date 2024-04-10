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
const int MAXN=300005;

int n,m;
ll d[MAXN];
int u[MAXN],v[MAXN];
ll c[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int E,uu,vv,cc;
	readint(n),readint(E);
	while(E--)
	{
		readint(uu),readint(vv),readint(cc);
		d[uu]-=cc;d[vv]+=cc;
	}
	int x=1,y=1;
	while(x<=n && y<=n)
	{
		while(x<=n && d[x]>=0)++x;
		while(y<=n && d[y]<=0)++y;
		if(x>n || y>n)break;
		++m;
		if(-d[x]>d[y])
		{
			u[m]=x,v[m]=y,c[m]=d[y];
			d[x]+=d[y];
			d[y]=0;
		}
		else
		{
			u[m]=x,v[m]=y,c[m]=-d[x];
			d[y]+=d[x];
			d[x]=0;
		}
	}
	printf("%d\n",m);
	for(int i=1;i<=m;++i)
		printf("%d %d %I64d\n",u[i],v[i],c[i]);
	return 0;
}