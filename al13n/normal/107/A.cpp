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

int next[100000];
int prev[100000];
int wei[100000];

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    memset(prev,-1,sizeof(prev));
    memset(next,-1,sizeof(next));

    int n,m;
    cin>>n>>m;
    forn(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        --a;--b;
        next[a]=b;
        prev[b]=a;
        wei[a]=c;
    }
    vector<pair<pair<int,int>,int> > v;
    forn(i,n){
        if(prev[i]!=-1)
            continue;
        int p=i;
        int w=iinf;
        while(next[p]!=-1)
            w=min(w,wei[p]),
            w=min(w,wei[p]),
            p=next[p];
        if(w!=iinf)
            v.pb(mp(mp(i,p),w));
    }
    sort(all(v));
    cout<<v.size()<<endl;
    forv(i,v)
        cout<<v[i].first.first+1<<' '<<v[i].first.second+1<<' '<<v[i].second<<'\n';

    return 0;
}