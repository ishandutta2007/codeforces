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

#define N 111
char a[N][N];

int main()
{
#ifdef MY_SIDE
    freopen("f.in","r",stdin);
#endif
    int n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)>0)
    {
        int i,j;
        int posx[128],posy[128];
        for(i=0;i<n;i++)
        {
            scanf("%s",a[i]);
            for(j=0;j<m;j++)
                if(a[i][j]>60) 
                {
                    posx[a[i][j]]=i;
                    posy[a[i][j]]=j;
                }
        }
        int x,y;
        scanf("%d%d",&x,&y);
        x--;y--;
        char s[1111];
        scanf("%s",s);
        int sn=strlen(s);
        int xe,ye;
        scanf("%d%d",&xe,&ye);
        int ansx=-1,ansy=-1;
        xe--;ye--;
        int t=0;
        for(i=0;i<=sn && ansx<0;i++)
        {
            int xx,yy;
            if(i<sn) xx=posx[s[i]],yy=posy[s[i]]; else xx=xe,yy=ye;
            int dx=0,dy=0;
            if(x==xx) {
                dx=0;
                dy=y<yy?+1:-1;
            } else {
                dx=x<xx?+1:-1;
                dy=0;
            }
            for(;x!=xx || y!=yy;)
            {
                if(a[x][y]<60) t+=a[x][y]-'0'; else t++;
                if(t>k)
                {
                    ansx=x,ansy=y;
                    break;
                }
                x+=dx;
                y+=dy;
                if(t>=k) 
                {
                    ansx=x,ansy=y;
                    break;
                }
            }
        }
        if(ansx<0) ansx=xe,ansy=ye;
        printf("%d %d\n",ansx+1,ansy+1);
    }
    return 0;
}