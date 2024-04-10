#include <stdio.h>
#include <time.h>
#include <assert.h>
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

typedef __int64 LL;
typedef unsigned __int64 ULL;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) {if(a>(b)) a=(b);}
#define MAX(a,b) {if(a<(b)) a=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

//clock_t start=clock();
//fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));

#define N 1111

int n;
int X[N],Y[N];
int y;

void makeLine(LL x1,LL y1,LL x2,LL y2,LL &a,LL &b,LL &c)
{
    a=y2-y1;
    b=x1-x2;
    c=-y1*x2+x1*y2;
}

int fnd(int x,int xx)
{
    int i;
    for(i=1;i<n;++i)
    {
        LL x1=X[i]-x, y1=Y[i]-y;
        LL x2=X[i+1]-x, y2=Y[i+1]-y;
        LL det=x1*y2-x2*y1;
        if(det>0) break;
    }
    if(i==n) return x;
    LL a,b,c;
    makeLine(X[i],Y[i],X[i+1],Y[i+1],a,b,c);
    if(a<0) a*=-1, b*=-1, c*=-1;
    int d=1;
    int l=x, r=xx;
    if(l>r) swap(l,r), d=-1;
    if(!(l*a<=c-b*y && c-b*y<=r*a)) return xx+d;
    LL px=(c-b*y)/a;
    if(a*px!=c-b*y && xx>px) ++px;
    return fnd(px,xx);
}

int main()
{
    //freopen("e.in","r",stdin);
    int i,j,k;
    for(;scanf("%d", &n)>0;)
    {
        for(i=0;i<n;++i) scanf("%d%d",X+i,Y+i);
        y=Y[0];
        X[n]=X[0];
        Y[n]=Y[0];
        int l=fnd(X[0],X[1]);
        int r=fnd(X[1],X[0]);
        if(X[0]>X[1]) swap(l,r);
        int res = max(0,r-l+1);
        printf("%d\n",res);
    }
    return 0;
}