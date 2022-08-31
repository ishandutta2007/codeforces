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
#define div asddiv
#define eps 1e-10
#define y1 asdy1
#define y2 asdy2
#define EQ(a,b) abs((a)-(b))<eps
#define PI 3.1415926535897932384626433832795
#define DEG2RAD PI/180
#define ulng unsigned lng
const double dinf = 1e200;
void ext(int c){
#ifdef __ASD__
    exit(c);
#endif
}

lng gcd(lng a,lng b){
    return a?gcd(b%a,a):b;
}

#define taska "four"
int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
    //freopen(taska".in","r",stdin);freopen(taska".out","w",stdout);
#endif

    //ios_base::sync_with_stdio(false);

    lng t1,t2,x1,x2,t0;
    cin>>t1>>t2>>x1>>x2>>t0;
    if(t1==t2){
        cout<<x1<<' '<<x2;
        return 0;
    }

    pair<pair<double,lng>,pair<lng,lng> > res(mp(1e200,0LL),mp(0LL,0LL));
    res=min(res,mp(mp(t2*1.,-x2),mp(0LL,x2)));
    if(t0==t1)
        res=min(res,mp(mp(t1*1.,-x1),mp(x1,0LL)));
    for(lng y1=0;y1<=x1;++y1){
        lng a=y1?0:1,b=x2+2;
        while(b>a+1){
            lng v=(a+b)/2;
            if(t1*y1+t2*(v-1)>=t0*(y1+v-1))
                b=v;
            else
                a=v;
        }
        if(a>x2)
            continue;
        lng tt1=t1*y1+t2*a;
        lng tt2=y1+a;
        lng g=gcd(tt1,tt2);
        tt1/=g;
        tt2/=g;
        res=min(res,mp(mp(1.*tt1/tt2,-(y1+a)),mp(y1,a)));
    }

    cout<<res.second.first<<' '<<res.second.second;

    return 0;
}