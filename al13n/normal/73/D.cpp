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

vector<int> gr[1100000];
int comp[1100000];
int n;

int dfs(int v,int c){
    if(comp[v])
        return 0;
    int r=1;
    comp[v]=c;
    forv(i,gr[v])
        r+=dfs(gr[v][i],c);
    return r;
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    cin>>n;
    int m,k;
    cin>>m>>k;
    forn(i,m){
        int a,b;
        scanf("%d%d",&a,&b);
        --a;--b;
        gr[a].pb(b);
        gr[b].pb(a);
    }

    int c=0;
    int ones=0;
    int s=0;
    bool was=false;
    //vector<int> szs(n);
    forn(i,n)
        if(!comp[i]){
            int t=dfs(i,++c);
            t=min(t,k);
            //szs[i]=t;
            if(t==1)
                ++ones;
            else{
                s+=t-2;
                was=true;
            }
        }
    
    if(k==1){
        cout<<max(0,c-2);
        return 0;
    }

    cout<<max(0,(ones-s-1)/2);

    return 0;
}