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

vector<pair<int,int> > src[100];

int sign(int a){
    if(a<0)
        return -1;
    if(a>0)
        return 1;
    return 0;
}

int solve(vector<pair<int,int> > &ve1,vector<pair<int,int> > &ve2){
    int i1=0,i2=0;
    int v1=0,v2=0;
    int p1=0,p2=0;
    int time=0;
    int res=0;
    while(i1<ve1.size()&&i2<ve2.size()){
        int t,vv1=v1,vv2=v2;
        t=min(ve1[i1].first,ve2[i2].first);
        if(ve1[i1].first==t)
            vv1=ve1[i1++].second;
        if(ve2[i2].first==t)
            vv2=ve2[i2++].second;
        int pp1=p1+(t-time)*v1;
        int pp2=p2+(t-time)*v2;
        if(pp1==pp2&&sign(v1-v2)*sign(vv1-vv2)>0)
            ++res;
        if(sign(p1-p2)*sign(pp1-pp2)<0)
            ++res;
        time=t;
        v1=vv1;
        v2=vv2;
        p1=pp1;
        p2=pp2;
    }
    return res;
}

#define filename "exam"
int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
    //freopen(filename".in","r",stdin);freopen(filename".out","w",stdout);
#endif

    int n;
    int s;
    cin>>n>>s;
    forn(i,n){
        int k;
        cin>>k;
        int t=0;
        forn(j,k){
            int v,l;
            cin>>v>>l;
            src[i].pb(mp(t,v));
            t+=l;
        }
        src[i].pb(mp(t,0));
    }
    int res=0;
    forn(i,n)
        forn(j,i)
            res+=solve(src[i],src[j]);
    cout<<res;

    return 0;
}