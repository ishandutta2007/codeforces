#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

#define bit(n) (1<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef __int64 LL;

int main()
{
   // freopen("in.txt","r",stdin);
    int n;
    while(scanf("%d",&n)>0)
    {
        int cnt=0;
        VI ans;
        int x,i;
        for(x=2001;x<=2000+n;x++)
        {
            int a;
            scanf("%d",&a);
            if(a==cnt+1) ans.pb(x),cnt++;
        }
        printf("%d\n",ans.sz);
        for(i=0;i<ans.sz;i++)
            printf("%d%c",ans[i],i<ans.sz-1?' ':'\n');
    }
    return 0;
}