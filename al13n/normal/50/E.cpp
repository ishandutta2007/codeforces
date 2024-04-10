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

int isqup(lng v){
    lng r=(lng)sqrt((double)v);
    while(SQ(r-1)>=v)
        --r;
    while(r*r<v)
        ++r;
    return (int)r;
}

int delta[11000000];

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    int n,m;
    cin>>n>>m;
    lng res=0;
    for(int b=1;b<=n;++b){
        int t;
        if(m>=SQ((lng)b))
            t=0;
        else
            t=isqup(SQ((lng)b)-m);
        if(t>b)
            exit(123);
        res+=(min(SQ((lng)b),(lng)m)-(b-t))*2;
        if(t==0){
            ++delta[b];
            --delta[b+1];
            ++t;
        }
        if(t>=b)
            continue;
        ++delta[1];
        --delta[b-t+1];
        ++delta[b+t];
        --delta[b+b];
    }
    int d=0;
    forn(i,11000000){
        d+=delta[i];
        if(d)
            ++res;
    }
    cout<<res;

    return 0;
}