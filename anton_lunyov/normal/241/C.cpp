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

struct mir
{
    int v,a,b;
    bool used;
    mir(){}
    mir(int v_,int a_,int b_){v=v_;a=a_;b=b_;}
};

#define N 111

int main()
{
#ifdef MY_SIDE
    freopen("c.in","r",stdin);
#endif
    int hl,hr,n;
    while(scanf("%d%d%d",&hl,&hr,&n)>0)
    {
        int i,j;
        vector<mir> m[2];
        for(i=0;i<n;i++)
        {
            int v,a,b;
            char c;
            scanf("%d %c %d %d",&v,&c,&a,&b);
            m[c=='T'].pb(mir(v,a,b));
        }
        int x1=0,y1=hl;
        int ans=0;
        for(int y=-n-2;y<=n+2;y++) if(y)
        {
            if(y==-1)
                y=y;
            for(j=0;j<2;j++)
                for(i=0;i<m[j].sz;i++)
                    m[j][i].used=false;
            int x2=100000;
            int y2=100*y+(y%2?100-hr:hr);
            int score=0;
            bool fail=false;
            for(j=1;j<=abs(y) && !fail;j++)
            {
                int y0=100*(y>0?j:1-j);
                double x0=x1+double(x2-x1)*(y0-y1)/(y2-y1);
                int q=y>0?j%2:1-j%2;
                for(i=0;i<m[q].sz && !fail;i++)
                    if(m[q][i].a-eps<=x0 && x0<=m[q][i].b+eps)
                    {
                        if(m[q][i].used) fail=true; else
                        {
                            m[q][i].used=true;
                            score+=m[q][i].v;
                        }
                        break;
                    }
                if(i==m[q].sz) fail=true;
            }
            if(!fail) MAX(ans,score);
        }
        printf("%d\n",ans);
    }
    return 0;
}