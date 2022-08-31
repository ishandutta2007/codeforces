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
#define ulng unsigned long long
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

bool mat[110][110];
vector<int> gr[110];
int tin[110];
int fup[110];
int timer;
bool was[110];
int n;
set<pair<int,int> > bri;

void dfs(int v,int pr=-1){
    was[v]=true;
    tin[v]=fup[v]=timer++;
    forv(i,gr[v]){
        int p=gr[v][i];
        if(!mat[v][p])
            continue;
        if(pr==p)
            continue;
        if(was[p])
            fup[v]=min(fup[v],tin[p]);
        else{
            dfs(p,v);
            fup[v]=min(fup[v],fup[p]);
            if(fup[p]>tin[v]){
                bri.insert(mp(v,p));
                bri.insert(mp(p,v));
            }
        }
    }
}

void getmoves(int v,vector<int> &res){
    int q=-1;
    forn(i,n)
        if(mat[v][i]){
            if(q==-1)
                q=i;
            else{
                q=-2;
                break;
            }
        }
    if(q==-1)
        exit(123);
    if(q!=-2){
        res.pb(q);
        return;
    }

    forn(i,n)
        was[i]=false;
    bri.clear();
    dfs(v,-1);
    
    forn(i,n)
        if(mat[v][i]&&!bri.count(mp(v,i)))
            res.pb(i);
}

int path[3000];
int m;

int main(int argc,char **argv){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    cin>>n>>m;
    forn(i,m+1){
        cin>>path[i];
        --path[i];
    }

    int p=-1;
    for(int i=m-1;i>=0;--i){
        int a=path[i];
        int b=path[i+1];
        gr[a].pb(b);
        gr[b].pb(a);
        mat[a][b]=mat[b][a]=true;
        vector<int> t;
        getmoves(a,t);
        sort(all(t));
        if(b==t.back())
            continue;
        b=*upper_bound(all(t),b);
        mat[a][b]=mat[b][a]=false;
        path[i+1]=b;
        p=i+1;
        break;
    }
    if(p==-1){
        cout<<"No solution";
        exit(0);
    }
    while(p<m){
        int a=path[p];
        vector<int> t;
        getmoves(a,t);
        int b=t[0];
        mat[a][b]=mat[b][a]=false;
        path[p+1]=b;
        ++p;
    }
    forn(i,m+1)
        cout<<path[i]+1<<' ';

    return 0;
}