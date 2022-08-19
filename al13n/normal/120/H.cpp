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

map<string,int> comp;
vector<string> decomp;
vector<int> gr[210];
int n,k;

void doit(string word,string part,int v0){
    if(part.length()){
        int v=comp.size();
        if(!comp.count(part)){
            comp[part]=v;
            decomp.pb(part);
        }else
            v=comp[part];
        gr[v0].pb(v);
    }
    if(part.length()==4||word.length()==0)
        return;
    doit(word.substr(1),part,v0);
    doit(word.substr(1),part+word[0],v0);
}

vector<int> mt;
vector<char> used;

bool try_kuhn (int v) {
    if (used[v])  return false;
    used[v] = true;
    for (size_t i=0; i<gr[v].size(); ++i) {
        int to = gr[v][i];
        if (mt[to] == -1 || try_kuhn (mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int invmt[210];

#define taska ""
int main(int argc, char **argv){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
    //freopen(taska".in","r",stdin);freopen(taska".out","w",stdout);
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    
    ios_base::sync_with_stdio(false);
    
    cin>>n;
    forn(i,n){
        string s;
        cin>>s;
        doit(s,"",i);
    }
    forn(i,n){
        sort(all(gr[i]));
        gr[i].erase(unique(all(gr[i])),gr[i].end());
    }
    
    k=comp.size();
    
    mt.assign (k, -1);
    for (int v=0; v<n; ++v) {
        used.assign (n, false);
        try_kuhn (v);
    }
    
    memset(invmt,-1,sizeof(invmt));
    forn(i,k)
        if(mt[i]!=-1)
            invmt[mt[i]]=i;
    
    forn(i,n)
        if(invmt[i]==-1){
            cout<<-1;
            return 0;
        }
    
    forn(i,n)
        cout<<decomp[invmt[i]]<<'\n';
    
    return 0;
}