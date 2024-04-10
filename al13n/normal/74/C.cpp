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
#define fornn(i,n) for(i=0;i<(n);++i)
#define lng long long
#define SQ(a) ((a)*(a))
#define forv(i,v) for(int i=0;i<(int)v.size();++i)
#define mp make_pair
#define pb push_back
#define ABS(a) ((a)<0?-(a):(a))
#define iinf 1000000000
#define left asdleft

int comp[1100000];
int n,m;

int doit(int a){
    a=(a%(n*2-2)+n*2-2)%(n*2-2);
    if(a<n)
        return a;
    else
        return n*2-2-a;
}

void dfs(int v,int c){
    if(comp[v]!=-1)
        return;
    comp[v]=c;
    dfs(doit(v+m+m-2),c);
    dfs(doit(v-m-m+2),c);
}

int solve(int nn,int mm){
    n=nn;
    m=mm;
    memset(comp,-1,sizeof(comp));
    int c=0;
    forn(i,n){
        if(comp[i]==-1)
            dfs(i,c++);
    }
    return c;
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    int n,m;
    cin>>n>>m;
    cout<<max(solve(n,m),solve(m,n));

    return 0;
}