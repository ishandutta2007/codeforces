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
#include <memory.h>
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
#define linf SQ(1LL*iinf)
#define left asdleft
#define prev asdprev
#define hash asdhash
#define eps 1e-8
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

int gcd(int a,int b){
    return a?gcd(b%a,a):b;
}

int A[200];
int n;
bool was[200];

#define taska "four"
int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
    //freopen(taska".in","r",stdin);freopen(taska".out","w",stdout);
#endif

    //ios_base::sync_with_stdio(false);

    int k;
    cin>>n>>k;
    int k0=k;
    k=n/k;
    forn(i,n)
        cin>>A[i];
    int q;
    cin>>q;
    int res1=iinf,res2=-iinf;
    forn(asd,q){
        int s=0;
        forn(i,k){
            int v;
            cin>>v;
            --v;
            s+=A[v];
            was[v]=true;
        }
        res1=min(res1,s);
        res2=max(res2,s);
    }
    vector<int> ar;
    forn(i,n)
        if(!was[i])
            ar.pb(A[i]);

    sort(all(ar));

    if(ar.size()+k*k0!=n){
        int s;
        
        s=0;
        forn(i,k)
            s+=ar[i];
        res1=min(res1,s);

        reverse(all(ar));
        s=0;
        forn(i,k)
            s+=ar[i];
        res2=max(res2,s);
    }

    printf("%.10lf %.10lf",1.*res1/k,1.*res2/k);

    return 0;
}