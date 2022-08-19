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

lng gcd(lng a,lng b){
    return a?gcd(b%a,a):b;
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    lng a,b;
    cin>>a>>b;
    bool sw=false;
    if(a<b){
        sw=true;
        swap(a,b);
    }
    lng g=gcd(a,b);
    lng c=a*b/gcd(a,b);
    vector<pair<lng,int> > v;
    forn(i,b/g+1)
        v.pb(mp(1LL*i*a,0));
    forn(i,a/g+1)
        v.pb(mp(1LL*i*b,1));
    sort(all(v));

    lng r[2]={0,0};
    forn(i,v.size()-2){
        lng l=v[i+1].first-v[i].first;
        r[v[i+1].second]+=l;
    }
    if(sw)
        swap(r[0],r[1]);
    if(r[0]>r[1])
        cout<<"Dasha";
    else if(r[0]<r[1])
        cout<<"Masha";
    else
        cout<<"Equal";

    return 0;
}