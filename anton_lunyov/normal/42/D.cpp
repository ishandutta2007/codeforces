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

#define N 22

int main()
{
    //freopen("d.in","r",stdin);
    int mark[11111]={0};
    int a[N]={1};
    int n;
    for(n=1;n<N;n++)
    {
        int x,i;
        for(x=a[n-1]+1;;x++)
        {
            for(i=0;i<n && !mark[x+a[i]];i++);
            if(i==n) break;
        }
        a[n]=x;
        for(i=0;i<n;i++)
            mark[x+a[i]]=1;
        //printf("%d\n",a[n]);
    }
    while(scanf("%d",&n)>0)
    {
        int i,j;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                int x = i==j?0:a[i]+a[j];
                printf("%d%c",x,j<n-1?' ':'\n');
            }
    }
    return 0;
}