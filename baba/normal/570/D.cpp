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
const int N = int(5e5)+10;
VI g[N];
int start[N],endd[N];
int E[N];
int level[N];
int C[N];
int H[N][26];
int len=0;
int sqt;
bool ans[N];
pair<II,II> Q[N];
void dfs(int u,int p)
{
	len++;
	start[u]=len;
	E[len]=u;
	for(int i=0;i<SZ(g[u]);i++)
		if(g[u][i]!=p)
			level[g[u][i]]=level[u]+1,dfs(g[u][i],u);
	endd[u]=len;
}
bool cmp(pair<II,II> a,pair<II,II> b)
{
	if(a.F.F/sqt != b.F.F/sqt)
		return a.F.F/sqt < b.F.F/sqt;
	return a.F.S<b.F.S;
}
int main()
{
	int n,m;
	si(n);si(m);
	for(int i=2;i<=n;i++)
	{
		int p;si(p);
		g[i].PB(p);
		g[p].PB(i);
	}
	string s;cin>>s;
	for(int i=0;i<SZ(s);i++)
		C[i+1]=s[i]-'a';
	level[1]=1;
	dfs(1,1);
	for(int i=0;i<m;i++)
	{
		int v,k;si(v);si(k);
		Q[i].F.F = start[v];
		Q[i].F.S = endd[v];
		Q[i].S.F = k;
		Q[i].S.S = i;
	}
	sqt = sqrt(2*n);
	sort(Q,Q+m,cmp);
	int L = 1,R = 1;
	H[level[E[1]]][C[E[1]]]++;
	for(int i=0;i<m;i++)
	{
		int l = Q[i].F.F;
		int r = Q[i].F.S;
		int k = Q[i].S.F;
		int pos = Q[i].S.S;
		while(L<l)
		{
			int u = E[L];
			H[level[u]][C[u]]--;
			L++;
		}
		while(L>l)
		{
			L--;
			int u = E[L];
			H[level[u]][C[u]]++;
		}
		while(R<r)
		{
			R++;
			int u = E[R];
			H[level[u]][C[u]]++;
		}
		while(R>r)
		{
			int u = E[R];
			H[level[u]][C[u]]--;
			R--;
		}
		bool odd=false,ok=true;
		for(int i=0;i<26;i++)
		{
			if(H[k][i]&1)
			{
				if(odd)ok=false;
				else	odd=true;
			}
		}
		ans[pos]=ok;
	}
	for(int i=0;i<m;i++)
		puts(ans[i]?"Yes":"No");
	return 0;
}