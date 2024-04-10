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
#define left asdleft
#define prev asdprev
#define eps 1e-10
void mytimer(string task){
#ifdef __ASD__
    static LARGE_INTEGER prev;  LARGE_INTEGER cur,freq; QueryPerformanceCounter(&cur);  QueryPerformanceFrequency(&freq);   if(task!="")        cout<<task<<" took "<<(cur.QuadPart-prev.QuadPart)*1.0/freq.QuadPart<<endl; prev=cur;
#endif
}

int ar[110000];
int lim=100000;

int doit(int n,int p){
    int k=(n+n)/p-p+1;
    if(p<2||(k&1)||k<=0)
        return lim;
    k>>=1;
    int x=0;
    forn(i,p)
        x^=ar[k+i];
    return x;
}

int was[200000];

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    ar[0]=0;
    int cur=10;
    for(int n=1;n<=lim;++n){
        ++cur;
        for(int p=1;p*p<=n+n;++p){
            if((n+n)%p)
                continue;
            was[doit(n,p)]=was[doit(n,(n+n)/p)]=cur;
        }
        while(was[ar[n]]==cur)
            ++ar[n];
    }

    int a;
    cin>>a;
    int r=-1;
    for(int p=2;p<a;++p){
        if(2*a%p)
            continue;
        if(!doit(a,p)){
            r=p;
            break;
        }
    }
    cout<<r;

    return 0;
}