#pragma comment(linker,"/STACK:228000000")
#include <vector>
#include <cstring>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <string>
using namespace std;
#define all(a) a.begin(),a.end()
#define forn(i,n) for(int i=0;i<(n);++i)
#define fornr(i,n) for(int i=(n)-1;i>=0;--i)
#define lng long long
#define PI 3.1415926535897932384626433832795
#define SQ(a) ((a)*(a))
#define sqr(a) ((a)*(a))
#define VI vector<int>
#define VD vector<double>
#define VS vector<string>
#define forv(i,v) for(int i=0;i<(int)v.size();++i)
#define forvr(i,v) for(int i=(int)v.size()-1;i>=0;--i)
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define ABS(a) ((a)<0?-(a):(a))
#define EQ(a,b) (ABS((a)-(b))<eps)
#define iinf 1000000000
#define dinf 100000000000000000000.0
#define linf 1000000000000000000LL
#define y0 asdy0
#define y1 asdy1
#define y2 asdy2
#define DEG2RAD 0.01745329251994329576923690768489
#define eps 1e-12
#define prev asdprev
#define left asdleft
#define fixed asdfixed
#define time asdtime
#define free asdfree
#define ends asdends
inline lng abs(lng a){return a<0?-a:a;}
#ifdef __ASD__
//#include "my.h" // project euler thingy
#endif

double src[110];
int n,k;
int x0,y0;
double dp[110];
double prob[110];

double doit(double rad){
    rad*=rad;
    forn(i,n){
        if(src[i]<=rad+eps)
            prob[i]=1;
        else
            if(rad>eps)
                prob[i]=exp(1-src[i]/rad);
            else
                prob[i]=0;
    }
    forn(i,n+1)
        dp[i]=0;
    dp[0]=1;
    forn(i,n){
        for(int j=n;j>0;--j)
            dp[j]=dp[j-1]*prob[i]+dp[j]*(1-prob[i]);
        dp[0]*=1-prob[i];
    }
    double sum=0;
    /*forn(i,n+1)
        sum+=dp[i];
    if(fabs(sum-1)>0.01)
        exit(123);*/
    sum=0;
    for(int i=k;i<=n;++i)
        sum+=dp[i];
    return sum;
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    cin>>n;
    double pr;
    cin>>k>>pr;
    pr/=1000;
    cin>>x0>>y0;
    forn(i,n){
        double x,y;
        cin>>x>>y;
        src[i]=SQ(x-x0)+SQ(y-y0);
    }
    double a=0,b=10000;
    forn(q,100){
        double v=(a+b)*0.5;
        if(1-doit(v)<pr)
            b=v;
        else
            a=v;
    }
    printf("%.12lf",(a+b)*0.5);

    return 0;
}