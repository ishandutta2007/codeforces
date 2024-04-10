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
#define forn(i,n) for(int i=0;i<n;++i)
#define fornr(i,n) for(int i=n-1;i>=0;--i)
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
#define y1 asdy1
#define y2 asdy2
#define DEG2RAD 0.01745329251994329576923690768489
#define eps 1e-12
#define prev asdprev
#define left asdleft
#define fixed asdfixed
#define time asdtime
#define free asdfree
inline lng abs(lng a){return a<0?-a:a;}
#ifdef __ASD__
//#include "my.h"
#endif

int dsu[110000];
pair<int,pair<int,int> > edges[210000];
vector<pair<int,int> > gr[110000];
int jmp[110000][20];
int maxjmp[110000][20];
int depth[110000];

int get(int v){
    if(dsu[v]==v)
        return v;
    else
        return dsu[v]=get(dsu[v]);
}
bool merge(int a,int b){
    a=get(a);
    b=get(b);
    if(a==b)
        return false;
    if(b<a)
        swap(a,b);
    dsu[b]=a;
    return true;
}

void dfs(int v){
    int todel=-1;
    forv(i,gr[v]){
        int p=gr[v][i].first;
        if(depth[p]!=-1){
            todel=i;
            continue;
        }
        jmp[p][0]=v;
        maxjmp[p][0]=gr[v][i].second;
        depth[p]=depth[v]+1;
        dfs(p);
    }
    if(todel!=-1)
        gr[v].erase(gr[v].begin()+todel);
    else if(v)
        exit(123);
}

void genjmp(int n){
    for(int i=1;i<20;++i){
        forn(v,n){
            int t=jmp[v][i-1];
            if(t==-1)
                continue;
            int p=jmp[t][i-1];
            if(p==-1)
                continue;
            jmp[v][i]=p;
            maxjmp[v][i]=max(maxjmp[v][i-1],maxjmp[t][i-1]);
        }
    }
}

int jmpdep(int v,int d,int &mx){
    mx=0;
    for(int i=19;i>=0;--i)
        if(depth[v]-(1<<i)>=d){
            mx=max(mx,maxjmp[v][i]);
            v=jmp[v][i];
        }
    return v;
}
int maxpath(int a,int b){
    int mx=0;
    if(depth[b]<depth[a])
        swap(a,b);
    for(int i=19;i>=0;--i)
        if(depth[b]-(1<<i)>=depth[a]){
            mx=max(mx,maxjmp[b][i]);
            b=jmp[b][i];
        }
    if(a==b)
        return mx;
    for(int i=19;i>=0;--i)
        if(jmp[a][i]!=jmp[b][i]){
            mx=max(mx,maxjmp[a][i]);
            mx=max(mx,maxjmp[b][i]);
            a=jmp[a][i];
            b=jmp[b][i];
        }
    mx=max(mx,maxjmp[a][0]);
    mx=max(mx,maxjmp[b][0]);
    return mx;
}

#define filename "exam"
int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
    //freopen(filename".in","r",stdin);freopen(filename".out","w",stdout);
#endif

    int n;
    cin>>n;
    int m;
    cin>>m;
    forn(i,m){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        --a;--b;
        edges[i]=mp(w,mp(a,b));
    }
    sort(edges,edges+m);
    forn(i,n)
        dsu[i]=i;
    lng wei=0;
    int cntadded=0;
    forn(i,m){
        int a=edges[i].second.first;
        int b=edges[i].second.second;
        int w=edges[i].first;
        if(merge(a,b)){
            gr[a].pb(mp(b,w));
            gr[b].pb(mp(a,w));
            wei+=w;
            ++cntadded;
        }
    }
    bool impossible=cntadded<n-2;
    bool disj=cntadded==n-2;
    if(!disj){
        memset(jmp,-1,sizeof(jmp));
        memset(depth,-1,sizeof(depth));
        depth[0]=0;
        dfs(0);
        genjmp(n);
    }
    int tc;
    cin>>tc;
    forn(q,tc){
        int a,b;
        scanf("%d%d",&a,&b);
        --a;--b;
        if(impossible||disj&&get(a)==get(b)){
            printf("-1\n");
            continue;
        }
        lng r=wei;
        if(!disj)
            r-=maxpath(a,b);
        printf("%lld\n",r);
    }

    return 0;
}