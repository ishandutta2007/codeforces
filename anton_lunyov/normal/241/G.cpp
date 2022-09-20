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

int main()
{
#ifdef MY_SIDE
    freopen("g.in","r",stdin);
    freopen("g.out","w",stdout);
#endif
    int i;
    int p[333]={0},x[333]={0};
    double q[333];
    int n=305;
    for(i=1;i<n;i++) 
    {
        p[i]=i==1?1000000:n-i;
        q[i]=sqrt(p[i]+0.);
    }
    x[1]=0;
    x[n]=0;
    for(i=2;i<n;i++) 
    {
        x[i]=x[i-1]+2*q[i]*q[i-1]+1;
        MAX(x[n],x[i]*q[1]/(q[1]-q[i]));
    }
    x[n]=p[n]=1000000;
    /*x[n]+=10000;
    p[n]=LL(x[n])*x[n]/4/p[1]+100;
    double rrn=double(x[n])*x[n]/4/p[1];
    double rn=p[n];
    for(i=n-1;i>=1;i--)
    {
        double rk=double(x[n]-x[i])*(x[n]-x[i])/4/p[i];
        MIN(rn,rk);
    }*/
    printf("%d\n",n);
    for(i=1;i<=n;i++)
        printf("%d %d\n",x[i],p[i]);
    return 0;
}