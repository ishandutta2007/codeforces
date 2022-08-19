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
#define y1 asdy1
#define y2 asdy2
#define EQ(a,b) abs((a)-(b))<eps
#define PI 3.1415926535897932384626433832795
#define DEG2RAD PI/180
void mytimer(string task){
#ifdef __ASD__
    static LARGE_INTEGER prev;  LARGE_INTEGER cur,freq; QueryPerformanceCounter(&cur);  QueryPerformanceFrequency(&freq);   if(task!="")        cout<<task<<" took "<<(cur.QuadPart-prev.QuadPart)*1.0/freq.QuadPart<<endl; prev=cur;
#endif
}

int src[110000];
bool was[110000];
vector<int> loops[110000];
vector<int> loops2,loops3;
vector<int> resv[110000];
int rlen;
int cnt;
int n;

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    cin>>n;
    forn(i,n)
        cin>>src[i],--src[i];

    forn(i,n){
        if(was[i])
            continue;
        for(int j=i;!was[j];j=src[j]){
            loops[cnt].pb(j);
            was[j]=true;
        }
        ++cnt;
    }

    forn(i,cnt){
        vector<int> &loop=loops[i];
        while(loop.size()>3){
            vector<int> &res=resv[rlen++];
            int l=min(5,(int)loop.size());
            forn(j,l)
                res.pb(loop[loop.size()-l+j]);
            forn(j,l)
                res.pb(loop[loop.size()-l+(j+1)%l]);
            forn(j,l-1)
                loop.pop_back();
        }
        if(loop.size()==2)
            loops2.pb(i);
        if(loop.size()==3)
            loops3.pb(i);
    }
    while(loops3.size()>loops2.size()&&loops3.size()>=2){
        vector<int> &res=resv[rlen++];
        int l1i=loops3.back();
        vector<int> l1=loops[l1i];
        loops3.pop_back();
        int l2i=loops3.back();
        vector<int> l2=loops[l2i];
        loops3.pop_back();

        res.pb(l1[0]);
        res.pb(l1[1]);
        res.pb(l1[2]);
        res.pb(l2[1]);
        res.pb(l2[2]);
        res.pb(l1[1]);
        res.pb(l1[2]);
        res.pb(l1[0]);
        res.pb(l2[2]);
        res.pb(l2[1]);

        loops[l2i].pop_back();
        loops2.pb(l2i);
    }
    while(loops2.size()&&loops3.size()){
        vector<int> &res=resv[rlen++];
        vector<int> &l2=loops[loops2.back()];
        vector<int> &l3=loops[loops3.back()];
        loops2.pop_back();
        loops3.pop_back();

        res.pb(l2[0]);
        res.pb(l2[1]);
        res.pb(l3[0]);
        res.pb(l3[1]);
        res.pb(l3[2]);

        res.pb(l2[1]);
        res.pb(l2[0]);
        res.pb(l3[1]);
        res.pb(l3[2]);
        res.pb(l3[0]);
    }
    while(loops3.size()){
        vector<int> &res=resv[rlen++];
        vector<int> l=loops[loops3.back()];
        loops3.pop_back();

        res.pb(l[0]);
        res.pb(l[1]);
        res.pb(l[2]);
        res.pb(l[1]);
        res.pb(l[2]);
        res.pb(l[0]);
    }
    while(loops2.size()>=2){
        vector<int> &res=resv[rlen++];
        vector<int> l1=loops[loops2.back()];
        loops2.pop_back();
        vector<int> l2=loops[loops2.back()];
        loops2.pop_back();

        res.pb(l1[0]);
        res.pb(l1[1]);
        res.pb(l2[0]);
        res.pb(l2[1]);

        res.pb(l1[1]);
        res.pb(l1[0]);
        res.pb(l2[1]);
        res.pb(l2[0]);
    }
    while(loops2.size()){
        vector<int> &res=resv[rlen++];
        vector<int> l=loops[loops2.back()];
        loops2.pop_back();

        res.pb(l[0]);
        res.pb(l[1]);
        res.pb(l[1]);
        res.pb(l[0]);
    }

    cout<<rlen<<'\n';
    forn(i,rlen){
        cout<<resv[i].size()/2<<'\n';
        forn(j,resv[i].size()/2)
            cout<<resv[i][j]+1<<' ';
        cout<<'\n';
        forn(j,resv[i].size()/2)
            cout<<resv[i][resv[i].size()/2+j]+1<<' ';
        cout<<'\n';
    }

    return 0;
}