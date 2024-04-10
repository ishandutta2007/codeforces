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

priority_queue<int,vector<int>,greater<int> > qus[3];
priority_queue<pair<lng,pair<int,int> >,vector<pair<lng,pair<int,int> > >,greater<pair<lng,pair<int,int> > > > evs;
int cap[3];
int tim[3];
int cur[3];

void doit(lng t){
    forn(i,3){
        if(cur[i]<cap[i]&&qus[i].size()){
            evs.push(mp(t+tim[i],mp(i+1,qus[i].top())));
            qus[i].pop();
            ++cur[i];
        }
    }
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);

    forn(i,3)
        cin>>cap[i];
    forn(i,3)
        cin>>tim[i];
    int n;
    cin>>n;
    forn(i,n){
        int c;
        cin>>c;
        evs.push(mp(1LL*c,mp(0,c)));
    }
    lng res=0;
    while(!evs.empty()){
        lng t=evs.top().first;
        int q=evs.top().second.first;
        int c=evs.top().second.second;
        evs.pop();
        if(q)
            --cur[q-1];
        if(q<3)
            qus[q].push(c);
        else
            res=max(res,t-c);
        doit(t);
    }
    cout<<res;

    return 0;
}