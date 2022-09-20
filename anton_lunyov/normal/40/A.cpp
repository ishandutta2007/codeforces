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
    //freopen("a.in","r",stdin);
    int x,y;
    while(scanf("%d%d",&x,&y)>0)
    {
        int s=0;
        if(x<0) x=-x,s++;
        if(y<0) y=-y,s++;
        int n=sqrt(1.*x*x+y*y)+eps;
        int col=(s+n)%2;
        if(n*n==x*x+y*y) col=0;
        puts(col?"white":"black");
    }
    return 0;
}