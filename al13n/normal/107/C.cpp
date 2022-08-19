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

lng lim=linf+iinf;

vector<int> gr[20];
int placeof[20];
int vertof[20];
lng dp[1<<17];
int n;

inline bool can(int v,int m){
    forv(i,gr[v])
        if(m&(1<<gr[v][i]))
            return false;
    return true;
}

lng doit(int m,int a){
    lng &res=dp[m];
    if(res!=-1)
        return res;
    if(!m)
        return 1;
    if(vertof[a]!=-1)
        if(can(vertof[a],m))
            return res=doit(m^(1<<vertof[a]),a+1);
        else
            return res=0;
    lng r=0;
    forn(i,n){
        if(!(m&(1<<i))||placeof[i]!=-1)
            continue;
        if(can(i,m)){
            r=min(lim,r+doit(m^(1<<i),a+1));
            if(r==lim)
                break;
        }
    }
    return res=r;
}

void solve(lng y){
    y-=2001;
    memset(dp,-1,sizeof(dp));
    memset(placeof,-1,sizeof(placeof));
    memset(vertof,-1,sizeof(vertof));
    if(y>=doit((1<<n)-1,0)){
        cout<<"The times have changed";
        exit(0);
    }
    forn(p,n){
        bool found=false;
        for(int v=0;v<n;++v){
            if(vertof[v]!=-1)
                continue;
            vertof[v]=p;
            placeof[p]=v;
            memset(dp,-1,sizeof(dp));
            lng c=doit((1<<n)-1,0);
            if(y-c<0){
                found=true;
                break;
            }
            y-=c;
            vertof[v]=-1;
            placeof[p]=-1;
        }
        if(!found)
            exit(123);
    }
    forn(i,n)
        cout<<placeof[i]+1<<' ';
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    int m;
    lng y;
    cin>>n>>y>>m;
    forn(i,m){
        int a,b;
        cin>>a>>b;
        --a;--b;
        gr[b].pb(a);
    }
    //for(int y=2001;y<2100;++y){
        solve(y);
    //  cout<<endl;
    //}

    return 0;
}