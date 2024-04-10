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



int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    int n,m,h;
    cin>>n>>m>>h;
    --h;
    int s=0;
    int p=-1;
    forn(i,m){
        int a;
        cin>>a;
        if(i==h)
            p=a;
        s+=a;
    }
    if(p==-1)
        exit(123);
    if(s<n){
        cout<<-1;
        exit(0);
    }
    if(p==1){
        cout<<0;
        exit(0);
    }
    vector<int> mul,div;
    for(int i=s-p+1;i<=s-1;++i)
        div.pb(i);
    for(int i=s-n-p+2;i<=s-n;++i)
        mul.pb(i);
    double res=1;
    while(!div.empty()||!mul.empty()){
        if(!div.empty()&&(mul.empty()||res>1))
            res/=div.back(),
            div.pop_back();
        else
            res*=mul.back(),
            mul.pop_back();
    }

    printf("%.12lf",1-res);

    return 0;
}