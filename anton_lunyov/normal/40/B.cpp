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
    //freopen("b.in","r",stdin);
    int n,m,x;
    while(scanf("%d%d%d",&n,&m,&x)>0)
    {
        int i;
        for(i=1;i<x;)
        {
            n-=2,m-=2;
            i++;
            if(n<3 || m<3) break;
        }
        if(i<x) puts("0"); else
        {
            int ans;
            if(m>=2 && n>=2)
                ans=m+n-2;
            else
                ans=(n+m)/2;
            printf("%d\n",ans);
        }
    }
    return 0;
}