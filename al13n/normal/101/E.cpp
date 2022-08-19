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
#define eps 1e-10
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

int dist[2][20010];
unsigned int prev[10010][(20010+31)/32];
int X[20010],Y[20010];
int P;
int n,m;
int half;
int cu,pr;

inline bool getprev(int a,int b){
    return (bool)(prev[a][b>>5]&(((unsigned int)1)<<(b&31)));
}
inline void setprev(int a,int b,int v){
    if(v)
        prev[a][b>>5]&=~(((unsigned int)1)<<(b&31));
    else
        prev[a][b>>5]|=((unsigned int)1)<<(b&31);
}
inline int getcost(int a,int b){
    return (X[a]+Y[b])%P;
}

void fill(bool secondhalf){
    cu=0;
    pr=1;
    int h1,h2;
    if(secondhalf)
        h1=half,h2=n;
    else
        h1=0,h2=half;
    dist[cu][0]=getcost(0,0);
    for(int b=1;b<m;++b){
        dist[cu][b]=dist[cu][b-1]+getcost(0,b);
        if(h1<=0&&0<h2)
            setprev(0,b,1);
    }
    for(int a=1;a<h2;++a){
        swap(cu,pr);
        dist[cu][0]=dist[pr][0]+getcost(a,0);
        if(h1<=a&&a<h2)
            setprev(a-h1,0,0);
        for(int b=1;b<m;++b){
            int d1,d2,dd;
            dd=getcost(a,b);
            d1=dist[pr][b]+dd;
            d2=dist[cu][b-1]+dd;
            if(d1>d2){
                dist[cu][b]=d1;
                if(h1<=a&&a<h2)
                    setprev(a-h1,b,0);
            }else{
                dist[cu][b]=d2;
                if(h1<=a&&a<h2)
                    setprev(a-h1,b,1);
            }
        }
    }
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);

    cin>>n>>m>>P;
    forn(i,n)
        cin>>X[i];
    forn(i,m)
        cin>>Y[i];

    half = (n+1)/2;

    string res;

    int a=n-1,b=m-1;
    fill(true);
    int resn=dist[cu][m-1];
    while(a>=half){
        int p=!getprev(a-half,b);
        if(p)
            --b,
            res+='S';
        else
            --a,
            res+='C';
    }

    fill(false);

    while(a+b){
        int p=!getprev(a,b);
        if(p)
            --b,
            res+='S';
        else
            --a,
            res+='C';
    }

    reverse(all(res));
    cout<<resn<<'\n'<<res;

    return 0;
}