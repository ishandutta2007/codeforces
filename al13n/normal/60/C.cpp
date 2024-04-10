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

lng gcd(lng a,lng b){
    return a?gcd(b%a,a):b;
}

int v1[110],v2[110];
int n;
int D[110][110],M[110][110];
vector<int> gr[110];
int res[110];
bool done[110];
bool was[110];

void fail(){
    cout<<"NO";
    exit(0);
}

void dfs(int v,lng p){
    if(was[v])
        return;
    if(p<=0)
        p=1;
    if(p>2000000)
        p=1;
    res[v]=p;
    was[v]=true;
    done[v]=true;
    forv(t,gr[v]){
        int i=gr[v][t];
        dfs(i,1LL*M[v][i]/p*D[v][i]);
    }
}

bool subsolve(int v,int p){
    memset(was,0,sizeof(was));
    dfs(v,p);
    forn(i,n){
        if(!was[i])
            continue;
        forv(t,gr[i]){
            int j=gr[i][t];
            if(gcd(res[i],res[j])!=D[i][j]||1LL*res[i]/gcd(res[i],res[j])*res[j]!=M[i][j])
                return false;
        }
    }
    return true;
}

void solvecomp(int v){
    int p=v2[v]/v1[v];
    for(int i=1;i*i<=p||!p&&i==1;++i){
        if(p%i)
            continue;
        if(subsolve(v,i*v1[v]))
            return;
        if(subsolve(v,p/i*v1[v]))
            return;
    }
    fail();
}

int main(int argc,char **argv){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    int m;
    cin>>n>>m;
    memset(D,-1,sizeof(D));
    forn(i,m){
        int a,b,d,t;
        cin>>a>>b>>d>>t;
        --a;--b;
        if(t%d)
            fail();
        D[a][b]=D[b][a]=d;
        M[a][b]=M[b][a]=t;
        gr[a].pb(b);
        gr[b].pb(a);
    }
    forn(i,n){
        v1[i]=1;
        v2[i]=0;
        forn(j,n){
            if(D[i][j]==-1)
                continue;
            lng t=1LL*v1[i]*D[i][j]/gcd(v1[i],D[i][j]);
            if(t>2000000)
                fail();
            v1[i]=t;
            v2[i]=gcd(v2[i],M[i][j]);
        }
        if(v2[i]%v1[i])
            fail();
    }
    forn(i,n)
        if(!done[i])
            solvecomp(i);
    cout<<"YES\n";
    forn(i,n)
        cout<<res[i]<<' ';

    return 0;
}