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

#define X first
#define Y second

pair<int,int> ar[11000];
pair<int,int> res[500000];
int resl;

int tmp[30][11000];

void doit(int a,int b,int dep){
    int n=b-a;
    if(!n)
        return;
    int *ys=tmp[dep]+a;
    forn(i,n)
        ys[i]=ar[i+a].Y;
    sort(ys,ys+n);
    int cnt=unique(ys,ys+n)-ys;

    int c1,c2;
    c1=(a+b)/2;
    c2=c1+1;
    while(c1>a&&ar[c1-1].X==ar[c1].X)
        --c1;
    while(c2<b&&ar[c2].X==ar[c2-1].X)
        ++c2;
    
    forn(i,cnt){
        int t=lower_bound(ar+c1,ar+c2,mp(ar[c1].X,ys[i]))-ar;
        if(t<c2&&ar[t].Y==ys[i])
            continue;
        res[resl++]=mp(ar[c1].X,ys[i]);
    }

    doit(a,c1,dep+1);
    doit(c2,b,dep+1);
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    int n;
    cin>>n;
    forn(i,n)
        scanf("%d%d",&ar[i].X,&ar[i].Y);
    sort(ar,ar+n);
    doit(0,n,0);
    if(resl+n>200000)
        exit(221);
    cout<<resl+n<<endl;
    forn(i,n)
        printf("%d %d\n",ar[i].X,ar[i].Y);
    forn(i,resl)
        printf("%d %d\n",res[i].X,res[i].Y);

    return 0;
}