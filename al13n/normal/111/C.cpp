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

int dp[50][1<<6][1<<6];

#define taska "burai"
int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
    //freopen(taska".in","r",stdin);freopen(taska".out","w",stdout);
#endif

    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;
    if(m<n)
        swap(n,m);
    forn(i,50)
        forn(j,1<<6)
            forn(k,1<<6)
                dp[i][j][k]=iinf;
    dp[0][0][0]=0;
    forn(q,m){
        forn(m1,1<<n){
            forn(m2,1<<n){
                if(dp[q][m1][m2]==iinf)
                    continue;
                forn(p,1<<n){
                    bool good=true;
                    int c=0;
                    int m3=0;
                    forn(i,n){
                        if((m1&(1<<i))&&!(p&(1<<i))){
                            good=false;
                            break;
                        }
                        if(!(m2&(1<<i))&&(!i||!(p&(1<<(i-1))))&&!(p&(1<<i))&&(i==n-1||!(p&(1<<(i+1))))){
                            m3|=1<<i;
                        }
                        if(p&(1<<i))
                            ++c;
                    }
                    if(!good)
                        continue;
                    dp[q+1][m3][p]=min(dp[q+1][m3][p],dp[q][m1][m2]+c);
                }
            }
        }
    }
    int res=iinf;
    forn(i,1<<n)
        res=min(res,dp[m][0][i]);
    cout<<n*m-res;

    return 0;
}