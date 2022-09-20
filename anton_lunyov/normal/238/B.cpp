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

#define N 101010
PII a[N];
int col[N];

int main()
{
#ifdef MY_SIDE
    freopen("b.in","rt",stdin);
#endif
    int n,h;
    while(scanf("%d%d",&n,&h)>0)
    {
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i].X);
            a[i].Y=i;
            col[i]=1;
        }
        sort(a,a+n);
        int res=a[n-1].X+a[n-2].X-a[0].X-a[1].X;
        int mn=a[0].X+a[1].X+h;
        if(n>2) MIN(mn,a[1].X+a[2].X);
        int mx=a[0].X+a[n-1].X+h;
        if(n>2) MAX(mx,a[n-1].X+a[n-2].X);
        if(res>mx-mn)
        {
            res=mx-mn;
            col[a[0].Y]=2;
        }
        printf("%d\n",res);
        for(i=0;i<n;i++)
            printf("%d%c",col[i],i<n-1?' ':'\n');
    }
    return 0;
}