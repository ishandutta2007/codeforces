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

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long LL;

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

int main()
{
    //freopen("a.in","r",stdin);
    int n,v,i;
    while(scanf("%d%d",&n,&v)>0)
    {
        int a[22];
        int sa=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",a+i);
            sa+=a[i];
        }
        double x=1.*v/sa;
        for(i=0;i<n;i++)
        {
            int b;
            scanf("%d",&b);
            MIN(x,1.*b/a[i]);
        }
        printf("%.7lf\n",x*sa);
    }
    return 0;
}