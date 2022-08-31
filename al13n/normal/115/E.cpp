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
        static LARGE_INTEGER prev;      LARGE_INTEGER cur,freq; QueryPerformanceCounter(&cur);  QueryPerformanceFrequency(&freq);       if(task!="")            cout<<task<<" took "<<(cur.QuadPart-prev.QuadPart)*1.0/freq.QuadPart<<endl;     prev=cur;
#endif
}
void ext(int c){
#ifdef __ASD__
        exit(c);
#endif
}

const int lim=1000000;
lng tree[lim];
lng delta[lim];

void add(int l,int r,lng v,int a,int b,int k){
    if(l==a&&r==b){
        delta[k]+=v;
        tree[k]+=v;
        return;
    }
    int c=(a+b)/2;
    if(r<=c)
        add(l,r,v,a,c,k*2+1);
    else if(l>=c)
        add(l,r,v,c,b,k*2+2);
    else{
        add(l,c,v,a,c,k*2+1);
        add(c,r,v,c,b,k*2+2);
    }
    tree[k]=max(tree[k*2+1],tree[k*2+2])+delta[k];
}

vector<pair<int,int> > *starts = new vector<pair<int,int> >[210000];
int cost[210000];
int n;

#define taska "burai"
int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
    //freopen(taska".in","r",stdin);freopen(taska".out","w",stdout);
#endif

    ios_base::sync_with_stdio(false);

    int m;
    cin>>n>>m;
    forn(i,n)
        cin>>cost[i];
    forn(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        --a;--b;
        starts[b].pb(mp(a,c));
    }

    forn(k,n){
        add(k+1,k+2,tree[0],0,n+1,0);
        add(0,k+1,-cost[k],0,n+1,0);
        forv(i,starts[k])
            add(0,starts[k][i].first+1,starts[k][i].second,0,n+1,0);
    }

    cout<<tree[0];

    return 0;
}