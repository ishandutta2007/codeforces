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
#include <complex>
#ifdef __ASD__
#include <windows.h>
#endif
using namespace std;
#define all(a) a.begin(),a.end()
#define forn(i,n) for(int i=0;i<(n);++i)
#define fornn(i,n) for(i=0;i<(n);++i)
#define lng long long
#define SQ(a) ((a)*(a))
#define forv(i,v) for(int i=0;i<(int)v.size();++i)
#define mp make_pair
#define pb push_back
#define ABS(a) ((a)<0?-(a):(a))
#define iinf 1000000000
#define linf 1000000000000000000LL
#define left asdleft
#define prev asdprev
#define eps 1e-8
#define y1 asdy1
#define y2 asdy2
#define EQ(a,b) abs((a)-(b))<eps
#define PI 3.1415926535897932384626433832795
#define DEG2RAD PI/180
#define ulng unsigned lng
const double dinf = 1e200;
void mytimer(string task){
#ifdef __ASD__
    static LARGE_INTEGER prev;  LARGE_INTEGER cur,freq; QueryPerformanceCounter(&cur);  QueryPerformanceFrequency(&freq);   if(task!="")        cout<<task<<" took "<<(cur.QuadPart-prev.QuadPart)*1.0/freq.QuadPart<<endl; prev=cur;
#endif
}
void ext(int c){
#ifdef __ASD__
    exit(c);
#endif
}

int B[10],L[10];
int n;
int A;
double res;

void solve(){
    double r=0;
    forn(m,1<<n){
        double p=1,s=0;
        int c=0;
        forn(i,n){
            if(m&(1<<i)){
                ++c;
                p*=L[i]/10.;
            }else{
                p*=(10-L[i])/10.;
                s+=B[i];
            }
        }
        if(c*2<=n)
            p*=A/(A+s);
        r+=p;
    }
    res=max(res,r);
}

void doit(int a,int k){
    if(a==n){
        solve();
        return;
    }
    for(int i=0;i<=k&&L[a]+i<=10;++i){
        L[a]+=i;
        doit(a+1,k-i);
        L[a]-=i;
    }
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    int k;
    cin>>n>>k>>A;
    forn(i,n){
        cin>>B[i]>>L[i];
        L[i]/=10;
    }

    doit(0,k);

    printf("%.12lf",res);

    return 0;
}