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
#define linf 1000000000000000000LL
#define dinf 1e200
#define left asdleft
#define prev asdprev
#define eps 1e-12
#define y1 asdy1
#define y2 asdy2
#define EQ(a,b) abs((a)-(b))<eps
#define PI 3.1415926535897932384626433832795
#define DEG2RAD PI/180
#define ulng unsigned lng
#define next asdnext
#define prev asdprev
void mytimer(string task){
#ifdef __ASD__
        static LARGE_INTEGER prev;      LARGE_INTEGER cur,freq; QueryPerformanceCounter(&cur);  QueryPerformanceFrequency(&freq);       if(task!="")            cout<<task<<" took "<<(cur.QuadPart-prev.QuadPart)*1.0/freq.QuadPart<<endl;     prev=cur;
#endif
}
void ext(int c){
#ifdef __ASD__
        exit(c);
#endif
}

bool was[2][510000][2];
char line[510000];

const int mod=1000003;

#define taska "burai"
int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
    //freopen(taska".in","r",stdin);freopen(taska".out","w",stdout);
#endif

    int n,m;
    cin>>n>>m;
    gets(line);
    forn(i,n){
        gets(line);
        forn(j,m){
            char c=line[j];
            if(c=='.')
                continue;
            int v=c-'1';
            int v1=v/2;
            int v2=(v+1)%4/2;
            was[0][i][(j%2)^v1]=true;
            was[1][j][(i%2)^v2]=true;
        }
    }
    int len[]={n,m};

    int res=1;
    forn(q,2){
        forn(i,len[q]){
            bool w1=was[q][i][0];
            bool w2=was[q][i][1];
            if(w1&&w2)
                res=0;
            else if(!w1&&!w2)
                res=res*2%mod;
        }
    }

    cout<<res;

    return 0;
}