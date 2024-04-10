#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <complex>
#include <queue>
#pragma comment(linker, "/STACK:266777216")
using namespace std;

#define assert(f) { if(!(f)) { fprintf(stderr,"Assertion failed: "); fprintf(stderr,#f); fprintf(stderr,"\n"); exit(1); } }

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<double> VD;
typedef pair<double,double> PDD;

const int inf=1000000000;
const LL INF=LL(inf)*inf;
const double eps=1e-9;
const double PI=2*acos(0.0);
#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset((ar),(val),sizeof (ar))
#define MIN(a,b) {if((a)>(b)) (a)=(b);}
#define MAX(a,b) {if((a)<(b)) (a)=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

//clock_t start=clock();
//fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));

#define N 111111
#define L 333333

char buf[L];
VI a[N];
int p[N];
string s[N];
int cnt;
int d[L];
int par[L][20];
LL HASH[L][20];


void dfs(int u,int du)
{
	int idu=cnt;
	d[cnt]=du;
	for(int i=0;i<a[u].sz;i++)
	{
		int v=a[u][i];
		int prev = idu;
		for(int j=0;j<s[v].sz;j++)
		{
			cnt++;
			d[cnt]=du+j+1;
			par[cnt][0]=prev;
			HASH[cnt][0]=s[v][j];
			prev=cnt;
		}
		dfs(v,du+s[v].sz);
	}
}

#define MOD 1415926579
#define P 157LL
int pw[L]={1};

int main()
{
#ifdef MY_SIDE
	freopen("e.in","r",stdin);
#endif
	int n;
	for(n=1;n<L;n++)
		pw[n] = P * pw[n-1] % MOD;
	while(scanf("%d",&n)>0)
	{
		fill(p,0);
		for(int i=1;i<=n;i++) a[i].cl;
		for(int i=2;i<=n;i++)
		{
			scanf("%d %s",p+i,buf);
			a[p[i]].pb(i);
			s[i]=buf;
		}
		scanf("%s",buf);
		int tn = strlen(buf);
		VI bin;
		for(int i=0;i<20;i++)
			if(tn & bit(i)) bin.pb(i);
		int hasht=0;
		for(int i=0;i<tn;i++)
			hasht = (P * hasht + buf[i]) % MOD;
		cnt=1;
		dfs(1,0);
		for(int h=0;bit(h)<=cnt;h++)
			for(int u=1;u<=cnt;u++)
			{
				int pu=par[u][h];
				par[u][h+1]=par[pu][h];
				HASH[u][h+1] = (HASH[u][h] + LL(pw[bit(h)]) * HASH[pu][h]) % MOD;
			}
		int ans=0;
		for(int u=1;u<=cnt;u++)
			if(d[u]>=tn) {
				int v=u;
				int path=0;
				int cur_hash=0;
				for(int i=0;i<bin.sz;i++)
				{
					int h = bin[i];
					cur_hash = (cur_hash + LL(pw[path]) * HASH[v][h]) % MOD;
					v = par[v][h];
					path += bit(h);
				}
				if(cur_hash==hasht) ans++;
			}
		printf("%d\n",ans);
	}
	return 0;
}