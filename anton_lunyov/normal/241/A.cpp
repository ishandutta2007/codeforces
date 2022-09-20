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

int main()
{
#ifdef MY_SIDE
    freopen("a.in","r",stdin);
#endif
    int m,k;
    while(scanf("%d%d",&m,&k)>0)
    {
        int d[1111],s[1111];
        int i;
        for(i=0;i<m;i++) scanf("%d",d+i);
        for(i=0;i<m;i++) scanf("%d",s+i);
        int maxs=0;
        int f=0,t=0;
        for(i=0;i<m;i++)
        {
            f+=s[i];
            MAX(maxs,s[i]);
            if(f<d[i])
            {
                int h=(d[i]-f+maxs-1)/maxs;
                t+=k*h;
                f+=maxs*h;
            }
            f-=d[i];
            t+=d[i];
        }
        printf("%d\n",t);
    }
    return 0;
}