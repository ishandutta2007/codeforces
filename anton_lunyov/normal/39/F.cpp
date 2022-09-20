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
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    {
        int d[111],a[111];
        int i,j;
        for(i=0;i<m;i++)
            scanf("%d",d+i);
        for(i=0;i<k;i++)
            scanf("%d",a+i);
        int num[111]={0};
        int maxnum=inf;
        for(i=0;i<m;i++)
        {
            for(j=0;j<k;j++)
                if(a[j]%d[i]==0) num[i]++;
            MIN(maxnum,num[i]);
        }
        VI ans;
        for(i=0;i<m;i++)
            if(num[i]==maxnum) ans.pb(i+1);
        printf("%d\n",ans.sz);
        for(i=0;i<ans.sz;i++)
            printf("%d%c",ans[i],i<ans.sz-1?' ':'\n');
    }
    return 0;
}