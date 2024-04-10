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
const int MAXN=155,MAXK=8,INF=2147483647;

int n,m,q[MAXN],dis[MAXN];
struct Edge
{
	int u,v,d;
	inline bool operator <(const Edge &b)const{return d<b.d;}
}e[MAXN];
struct Matrix
{
	bitset<MAXN> a[MAXN];
	Matrix(){memset(a,0,sizeof(a));}
};
Matrix G,ans;
Matrix operator *(Matrix a,Matrix b)
{
	Matrix c;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(a.a[i][j])c.a[i]|=b.a[j];
	return c;
}
Matrix power(Matrix a,int k)
{
	Matrix ans;
	for(int i=1;i<=n;++i)ans.a[i][i]=1;
	for(;k;k>>=1,a=a*a)
		if(k&1)ans=ans*a;
	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	readint(n),readint(m);
	for(int i=1;i<=m;++i)readint(e[i].u),readint(e[i].v),readint(e[i].d);
	sort(e+1,e+m+1);
	for(int i=1;i<=n;++i)ans.a[i][i]=1;
	int lasd=0,fin=INF;
	for(int i=1;i<=m;++i)
	{
		ans=ans*power(G,e[i].d-lasd);
		G.a[e[i].u][e[i].v]=1;
		lasd=e[i].d;
		for(int j=1;j<=n;++j)dis[j]=INF;
		int front=1,rear=0;
		for(int j=1;j<=n;++j)
			if(ans.a[1][j])q[++rear]=j,dis[j]=0;
		while(front<=rear)
		{
			int u=q[front++];
			for(int j=1;j<=n;++j)
				if(G.a[u][j] && dis[j]==INF)
				{
					dis[j]=dis[u]+1;
					q[++rear]=j;
				}
		}
		if(dis[n]<INF)chkmin(fin,dis[n]+e[i].d);
	}
	if(fin==INF)printf("Impossible\n");
	else printf("%d\n",fin);
	return 0;
}