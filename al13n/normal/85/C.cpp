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

vector<int> kids[110000];
int vals[110000];
int lval[110000];
int rval[110000];
int src[110000];
double res[110000];
int n,k;

void getvals(int v){
    if(!kids[v].size()){
        lval[v]=rval[v]=vals[v];
        return;
    }
    if(kids[v].size()!=2)
        exit(33);
    if(vals[kids[v][1]]<vals[kids[v][0]])
        swap(kids[v][0],kids[v][1]);
    forv(i,kids[v])
        getvals(kids[v][i]);
    lval[v]=lval[kids[v][0]];
    rval[v]=rval[kids[v][1]];
}

void solve(int v,int l,int r,int cnt,lng sum){
    if(l==r)
        return;
    if(!kids[v].size()){
        if(!cnt)
//#ifdef __ASD__
            exit(123);
//#else
//          sum=0,cnt=1;
//#endif
        for(int i=l;i<r;++i)
            res[i]=1.*sum/cnt;
        return;
    }
    int c=lower_bound(src+l,src+r,vals[v])-src;
    solve(kids[v][0],l,c,cnt+1,sum+lval[kids[v][1]]);
    solve(kids[v][1],c,r,cnt+1,sum+rval[kids[v][0]]);
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    cin>>n;
    int root=-1;
    forn(i,n){
        int a,b;
        scanf("%d%d",&a,&b);
        --a;
        if(a>=0)
            kids[a].pb(i);
        else
            root=i;
        vals[i]=b;
    }
    cin>>k;
    vector<pair<int,int> > v(k);
    forn(i,k){
        scanf("%d",src+i);
        v[i]=mp(src[i],i);
    }
    sort(all(v));
    forn(i,k)
        src[i]=v[i].first;
    vector<double> rs(k);

    getvals(root);
    solve(root,0,k,0,0);
    forn(i,k)
        rs[v[i].second]=res[i];
    forn(i,k)
        printf("%.15lf\n",rs[i]);

    return 0;
}