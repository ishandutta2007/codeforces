#pragma comment(linker,"/STACK:228000000")
#include <vector>
#include <string.h>
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
inline lng abs(lng a){return a<0?-a:a;}
#ifdef __ASD__
//#include "my.h"
#endif

lng px[10000],py[10000];
lng cx[10000],cy[10000],cr[10000];
int id[10000];

vector<pair<int,int> > inside[2000];
int dep[2000];
int jmp[2000][20];
const int jc=10;

void dfs(int v){
    forv(i,inside[v]){
        int p=inside[v][i].second;
        if(dep[p]==-1){
            dep[p]=dep[v]+1;
            jmp[p][0]=v;
            dfs(p);
        }
    }
}

void genjmp(int n){
    for(int i=1;i<jc;++i){
        forn(j,n){
            jmp[j][i]=-1;
            if(jmp[j][i-1]==-1)
                continue;
            jmp[j][i]=jmp[jmp[j][i-1]][i-1];
        }
    }
}
int jump(int v,int d){
    for(int i=jc-1;dep[v]>d;--i)
        if(dep[v]-(1<<i)>=d)
            v=jmp[v][i];
    return v;
}
int lca(int a,int b){
    a=jump(a,min(dep[a],dep[b]));
    b=jump(b,min(dep[a],dep[b]));
    if(a==b)
        return a;
    for(int i=jc-1;i>=0;--i)
        if(jmp[a][i]!=jmp[b][i]){
            a=jmp[a][i];
            b=jmp[b][i];
        }
    return jmp[a][0];
}
int dist(int a,int b){
    int v=lca(a,b);
    return dep[a]-dep[v]+dep[b]-dep[v];
}

#define filename "" 
int main()
{
#ifdef __ASD__
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    /*
    forn(i,1000)
        cout<<i+1<<' '<<-1000000000<<' '<<1000000000<<endl;
    return 0;//*/

    int n,m,k;
    cin>>n>>m>>k;
    forn(i,n)
        cin>>px[i]>>py[i];
    forn(i,m)
        cin>>cr[i]>>cx[i]>>cy[i];
    forn(i,m){
        forn(j,m){
            if(j==i)
                continue;
            if(cr[i]>cr[j]&&SQ(cx[i]-cx[j])+SQ(cy[i]-cy[j])<=SQ(cr[i]))
                inside[i+1].pb(mp(-(int)cr[j],j+1));
        }
    }
    forn(i,m)
        inside[0].pb(mp(-(int)cr[i],i+1));
    forn(i,m+1)
        dep[i]=-1;
    forn(i,m+1)
        sort(all(inside[i]));
    dep[0]=0;
    jmp[0][0]=-1;
    dfs(0);
    genjmp(m+1);
    
    forn(i,n){
        id[i]=0;
        forn(j,m)
            if(SQ(px[i]-cx[j])+SQ(py[i]-cy[j])<=SQ(cr[j])&&dep[j+1]>dep[id[i]])
                id[i]=j+1;
    }
    forn(i,k){
        int a,b;
        scanf("%d%d",&a,&b);
        --a;--b;
        printf("%d\n",dist(id[a],id[b]));
    }

    return 0;
}