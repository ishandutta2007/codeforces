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

struct pt {
    int x, y, id;
};

inline bool cmp_x (const pt & a, const pt & b) {
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

inline bool cmp_y (const pt & a, const pt & b) {
    return a.y < b.y;
}

const int MAXN=110000;

pt a[MAXN];

double mindist;
int ansa, ansb;

inline void upd_ans (const pt & a, const pt & b) {
    double dist = sqrt ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + .0);
    if (dist < mindist)
        mindist = dist,  ansa = a.id,  ansb = b.id;
}

void rec (int l, int r) {
    if (r - l <= 3) {
        for (int i=l; i<=r; ++i)
            for (int j=i+1; j<=r; ++j)
                upd_ans (a[i], a[j]);
        sort (a+l, a+r+1, &cmp_y);
        return;
    }
    
    int m = (l + r) >> 1;
    int midx = a[m].x;
    rec (l, m),  rec (m+1, r);
    inplace_merge (a+l, a+m+1, a+r+1, &cmp_y);
    
    static pt t[MAXN];
    int tsz = 0;
    for (int i=l; i<=r; ++i)
        if (abs (a[i].x - midx) < mindist) {
            for (int j=tsz-1; j>=0 && a[i].y - t[j].y < mindist; --j)
                upd_ans (a[i], t[j]);
            t[tsz++] = a[i];
        }
}

int turn[MAXN];

#define taska ""
int main(int argc, char **argv){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
    //freopen(taska".in","r",stdin);freopen(taska".out","w",stdout);
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    
    //ios_base::sync_with_stdio(false);
    
    int n;
    cin>>n;
    forn(i,n){
        int x,y;
        scanf("%d%d",&x,&y);
        a[i].x=abs(x);
        a[i].y=abs(y);
        a[i].id=i;
        if(x<0)
            turn[i]|=1;
        if(y<0)
            turn[i]|=2;
    }
    
    sort (a, a+n, &cmp_x);
    mindist = 1E20;
    rec (0, n-1);
    
    int t1=turn[ansa]+1;
    int t2=(turn[ansb]^3)+1;
    cout<<ansa+1<<' '<<t1<<' '<<ansb+1<<' '<<t2;
    
    return 0;
}