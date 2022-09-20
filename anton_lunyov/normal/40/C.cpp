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
typedef unsigned long long ULL;

#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define X first
#define Y second
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))

int main()
{
    //freopen("c.in","r",stdin);
    int n,x,m,y,i,j;
    while(scanf("%d%d%d%d",&n,&x,&m,&y)>0)
    {
        int d=abs(x-y);
        if(n>m) swap(n,m);
        LL ans=m+1;
        for(i=1;i<=n;i++)
        {
            int num=0;
            j=i-d;if(1<=j && j<=m) num++;
            num+=2*max(i-abs(d-i),0);
            num+=2*max(min(m,d+i-1)-max(i,d-i),0);
            ans+=max(num,1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}