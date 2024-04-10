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

vector<lng> fib;

void genfib(){
    lng a=1,b=2;
    fib.pb(a);
    while(b<=linf){
        fib.pb(b);
        lng t=a+b;
        a=b;
        b=t;
    }
}

#define taska "four"
int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
    //freopen(taska".in","r",stdin);freopen(taska".out","w",stdout);
#endif

    ios_base::sync_with_stdio(false);

    genfib();
    int tc;
    cin>>tc;
    forn(qqq,tc){
        lng v;
        cin>>v;
        vector<int> r;
        for(int i=fib.size()-1;i>=0;--i){
            if(fib[i]<=v){
                v-=fib[i];
                r.pb(i);
            }
        }
        r.pb(-1);
        reverse(all(r));
        lng c0=1,c1=0;
        for(int i=1;i<r.size();++i){
            int l=r[i]-r[i-1];
            lng cc1=c1,cc0=c0;
            c0=cc0+cc1;
            c1=cc0*((l-1)/2)+cc1*(l/2);
        }
        cout<<c0+c1<<'\n';
    }

    return 0;
}