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
using namespace std;
#define all(a) a.begin(),a.end()
#define forn(i,n) for(int i=0;i<(n);++i)
#define lng long long
#define SQ(a) ((a)*(a))
#define forv(i,v) for(int i=0;i<(int)v.size();++i)
#define mp make_pair
#define pb push_back
#define ABS(a) ((a)<0?-(a):(a))
#define iinf 1000000000
#define linf SQ(1LL*iinf)
#define left asdleft
#define prev asdprev
#define eps 1e-8
#define y1 asdy1
#define y0 asdy0
#define EQ(a,b) abs((a)-(b))<eps
#define PI 3.1415926535897932384626433832795
#define DEG2RAD PI/180
#define ulng unsigned lng
#define dinf = 1e200

vector<int> gr[110];
int dep[110];
int diam;
int n;

void dfs(int v,int pa){
    vector<int> deps;
    deps.pb(0);
    deps.pb(0);
    forv(i,gr[v]){
        int p=gr[v][i];
        if(p==pa)
            continue;
        dfs(p,v);
        deps.pb(dep[p]+1);
    }
    sort(all(deps));
    reverse(all(deps));
    dep[v]=deps[0];
    diam=max(diam,deps[0]+deps[1]);
}

#define taska ""
int main(int argc, char **argv){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
    //freopen(taska".in","r",stdin);freopen(taska".out","w",stdout);
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    
    ios_base::sync_with_stdio(false);
    
    int tc;
    cin>>tc;
    int res=0;
    forn(q,tc){
        cin>>n;
        forn(i,n)
            gr[i].clear();
        diam=0;
        forn(i,n-1){
            int a,b;
            cin>>a>>b;
            --a;--b;
            gr[a].pb(b);
            gr[b].pb(a);
        }
        dfs(0,-1);
        res+=diam;
    }
    cout<<res;
    
    return 0;
}