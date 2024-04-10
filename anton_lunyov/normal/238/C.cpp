#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cassert>
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
#pragma comment(linker, "/STACK:266777216")
using namespace std;

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

#define N 3030
VPII a[N];
int mark[N];
int f[N];
int g[N];
int h[N];

void dfs(int u)
{
    mark[u]=1;
    int diff=0;
    int difh=0;
    g[u]=0;
    for(int i=a[u].sz;i--;)
    {
        int v=a[u][i].X;
        if(mark[v]) continue;
        int fix=a[u][i].Y>0 ? 0 : 1;
        dfs(v);
        g[u]+=g[v]+fix;
        MIN(diff,f[v]+!fix-(g[v]+fix));
        MIN(difh,h[v]-g[v]);
    }
    f[u]=g[u]+diff;
    h[u]=g[u]+difh;
    MIN(h[u],f[u]);
}

int main()
{
#ifdef MY_SIDE
    freopen("c.in","rt",stdin);
#endif
    int n;
    while(scanf("%d",&n)>0)
    {
        int i;
        for(i=1;i<=n;i++) a[i].cl;
        for(i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            a[u].pb(mp(v,1));
            a[v].pb(mp(u,-1));
        }
        int ans=inf;
        for(i=1;i<=n;i++)
        {
            fill(mark,0);
            fill(f,0);
            fill(g,0);
            dfs(i);
            MIN(ans,h[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}