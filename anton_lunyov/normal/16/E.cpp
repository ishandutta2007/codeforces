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
#define pi 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

typedef vector<int> VI;
typedef pair<int,int> PII;
//typedef long long LL;

#define N 18
double a[N][N];
double p[1<<N];

int main()
{
    int n;
    while(scanf("%d",&n)>0)
    {
        int i,j;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++) scanf("%lf",&a[i][j]);
        fill(p,0);
        p[bit(n)-1]=1;
        for(int mask=bit(n)-1;mask>0;mask--)
        {
            int cnt=0;
            for(i=0;i<n;i++) if(mask & bit(i)) cnt++;
            double c2n=cnt*(cnt-1)/2.;
            for(i=0;i<n;i++) if(mask & bit(i))
                for(j=0;j<n;j++) if(mask & bit(j))
                    if(i!=j)
                        p[mask-bit(i)]+=p[mask]*a[j][i]/c2n;
        };
        for(i=0;i<n;i++)
            printf("%.7lf%c",p[1<<i],i<n-1?' ':'\n');
    }
    return 0;
}