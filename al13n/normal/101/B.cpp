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
#define left asdleft
#define prev asdprev
#define eps 1e-10
#define y1 asdy1
#define y2 asdy2
#define EQ(a,b) abs((a)-(b))<eps
#define PI 3.1415926535897932384626433832795
#define DEG2RAD PI/180
#define ulng unsigned lng
const double dinf = 1e200;
void mytimer(string task){
#ifdef __ASD__
    static LARGE_INTEGER prev;  LARGE_INTEGER cur,freq; QueryPerformanceCounter(&cur);  QueryPerformanceFrequency(&freq);   if(task!="")        cout<<task<<" took "<<(cur.QuadPart-prev.QuadPart)*1.0/freq.QuadPart<<endl; prev=cur;
#endif
}
void ext(int c){
#ifdef __ASD__
    exit(c);
#endif
}

pair<int,int> segs[110000];
int dp[110000];
int sum[110000];
const int mod = iinf+7;

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);

    /*forn(i,100000)
        cout<<"0 "<<i+1<<'\n';
    return 0;*/

    int l,n;
    cin>>l>>n;

    forn(i,n)
        cin>>segs[i].second>>segs[i].first;

    segs[n++]=mp(0,0);
    segs[n++]=mp(-1,-1);

    sort(segs,segs+n);

    dp[0]=0;
    sum[0]=0;
    dp[1]=1;
    sum[1]=1;

    int res=0;
    for(int i=2;i<n;++i){
        int a=lower_bound(segs,segs+n,mp(segs[i].second,-100))-segs-1;
        int b=lower_bound(segs,segs+n,mp(segs[i].first ,-100))-segs-1;
        dp[i]=(sum[b]-sum[a]+mod)%mod;
        sum[i]=(sum[i-1]+dp[i])%mod;
        if(segs[i].first==l)
            res=(res+dp[i])%mod;
    }

    cout<<res;

    return 0;
}