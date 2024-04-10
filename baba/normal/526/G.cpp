//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;
typedef unsigned long long int ULL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
//Works for forward as well as backward iteration

#define gu getchar
#define pu putchar
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define DRT() int t; si(t); while(t--)

#define PlUSWRAP(index,n) index = (index+1)%n		//index++; if(index>=n) index=0
#define MINUSWRAP(index,n) index = (index + n -1)%n 	//index--; if(index<0) index=n-1
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)	//Round off d to nearest integer

#define FLUSHN while(gu()!='\n')
#define FLUSHS while(gu()!=' ')

#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
const int N = int(1e5)+10;
const int LOGN = 20;
VII g[N];
int level[N],DP[LOGN][N],far[N],longest[N],leafcover[N];//longest[i]=longest path coming from subtree of i.
VII cntbn;VI PS;//contribution,prefix sum over contribution.
int n;

int dfs0(int u,int p)
{
	far[u]=u;
	DP[0][u]=p;
	int ret=0;
	for(int i=0;i<SZ(g[u]);i++)
	{
		int w = g[u][i].F;
		int weight = g[u][i].S;
		if(w!=p)
		{
			level[w]=level[u]+weight;
			int d = weight + dfs0(w,u);
			if(d>=ret)
				ret = d,far[u]=far[w];
		}
	}
	return longest[u]=ret;
}
int step1()//finding the center and hanging the tree at its center (calculating the level,DP and longest values)
{
	//Find the weighted center of tree
	dfs0(0,0);
	int root=far[0];
	level[root]=0;
	dfs0(root,root);
	int center=far[root];
	int d1 = max(level[center],level[far[root]]-level[center]);
	int d2 = max(level[DP[0][center]],level[far[root]]-level[DP[0][center]]);
	while(d1 > d2)
	{
		center=DP[0][center];
		d1 = max(level[center],level[far[root]]-level[center]);
		d2 = max(level[DP[0][center]],level[far[root]]-level[DP[0][center]]);
	}
	//Hang the tree at its center.
	level[center]=0;
	dfs0(center,center);
	for(int i=1;i<LOGN;i++)
		for(int j=0;j<n;j++)
			DP[i][j]=DP[i-1][DP[i-1][j]];
	return center;
}
void dfs1(int u,int currlen)	//HLD type idea 
{
	int flag=0;
	for(int i=0;i<SZ(g[u]);i++)
	{
		int w = g[u][i].F;
		int weight = g[u][i].S;
		if(w==DP[0][u])continue;
		if(!flag && longest[w]+weight == longest[u]) // w is a special child
			dfs1(w,currlen+weight),flag=1;
		else					     //w is not a special child
			dfs1(w,weight);
	}
	if(!flag)	//it's a leaf
		cntbn.PB({currlen,u});
}
int main()
{
	int q;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n-1;i++)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		g[u-1].PB({v-1,w});
		g[v-1].PB({u-1,w});
	}
	int center = step1();
	dfs1(center,0); //step2
	sort(ALL(cntbn),greater<II>());	//step3

	SET(leafcover,-1);
	for(int i=0;i<SZ(cntbn);i++)    //step4
	{
		int x=cntbn[i].S;
		while(leafcover[x]==-1)
		{
			leafcover[x]=i;
			x = DP[0][x];
		}
	}
	PS.PB(cntbn[0].F);	//step5
	for(int i=1;i<SZ(cntbn);i++)
		PS.PB(PS[i-1]+cntbn[i].F);
	//step6 : Handle the queries
	int ans = 0;
	while(q--)
	{
		int xx,yy,x,y;
		scanf("%d %d",&xx,&yy);
		x = (xx + ans - 1)%n + 1;
		y = (yy + ans - 1)%n + 1;
		x--; //0 based indexing
		if(2*y >= SZ(cntbn)) 
			ans = PS[SZ(PS)-1];
		else if(2*y >= 1 + leafcover[x])
			ans = PS[2*y - 1];
		else
		{
			int z = x;
			for(int i=LOGN-1;i>=0;i--)
				if(1+leafcover[DP[i][z]] > 2*y)
					z = DP[i][z];
			z = DP[0][z];
			ans = PS[2*y-1]+ (level[x]-level[z]) + longest[x] - min(cntbn[2*y-1].F,longest[z]);
		}
		dout(ans);
	}
	return 0;
}