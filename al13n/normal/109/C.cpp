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
#define dinf 1e200
#define left asdleft
#define prev asdprev
#define eps 1e-12
#define y1 asdy1
#define y2 asdy2
#define EQ(a,b) abs((a)-(b))<eps
#define PI 3.1415926535897932384626433832795
#define DEG2RAD PI/180
#define ulng unsigned lng
#define next asdnext
#define prev asdprev
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

const int lim=110000;
vector<pair<int,bool> > gr[lim];
int sz[lim];
int down[lim];
int up[lim];
int n;

void getdown(int v,int par){
    sz[v]=1;
    forv(i,gr[v]){
        int p=gr[v][i].first;
        if(p==par)
            continue;
        getdown(p,v);
        if(gr[v][i].second)
            down[v]+=sz[p];
        else
            down[v]+=down[p];
        sz[v]+=sz[p];
    }
}

void getup(int v,int u,int par){
    up[v]=u;
    forv(i,gr[v]){
        int p=gr[v][i].first;
        if(p==par)
            continue;
        if(gr[v][i].second)
            getup(p,n-sz[p],v);
        else
            getup(p,u+down[v]-down[p],v);
    }
}

bool lucky(int a){
    while(a){
        int t=a%10;
        if(t!=4&&t!=7)
            return false;
        a/=10;
    }
    return true;
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);

    cin>>n;
    forn(i,n-1){
        int a,b,c;
        cin>>a>>b>>c;
        --a;--b;
        bool l=lucky(c);
        gr[a].pb(mp(b,l));
        gr[b].pb(mp(a,l));
    }
    getdown(0,-1);
    getup(0,0,-1);
    lng res=0;
    forn(i,n){
        lng v=down[i]+up[i];
        res+=v*(v-1);
    }
    cout<<res<<flush;

    return 0;
}