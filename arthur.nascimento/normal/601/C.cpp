#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 99999999999999999LL
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-5

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 300300

using namespace std;

typedef complex<double> C;

C poly1[maxn], poly2[maxn], val[maxn], result[maxn];

void fft(int deg, C *rd, C *wr, int step, int w){
    if(deg == 1){
        *wr = *rd;
        return;
    }

    fft(deg/2, rd, wr, 2*step, w);
    fft(deg/2, rd+step, wr+deg/2, 2*step, w);

    C omega = 1, omega_n = exp(C(0, w*2*acos(-1)/deg));

    for(int i = 0; i < deg/2; ++i){
        C x = wr[i], y = wr[i+deg/2];
        wr[i] = x+omega*y;
        wr[i+deg/2] = x-omega*y;
        omega = omega * omega_n;
    }
}

int mul(int d1, int d2){
    int d = d1 + d2;

    while(d & (d-1)) d++;

    for(int i = d1; i < d; ++i)
        poly1[i] = C(0,0);

    for(int i = d2; i < d; ++i)
        poly2[i] = C(0,0);

    fft(d, poly1, val, 1, 1);
    fft(d, poly2, result, 1, 1);

    for(int i = 0; i < d; ++i)
        val[i] *= result[i];

    fft(d, val, result, 1, -1);

    for(int i = 0; i < d; ++i)
        result[i] /= C(d,0);

    return d;
}

vector<long double> _fft(vector<long double> a,vector<long double> b){

    int dg = 1+max(a.size(),b.size());

    for(int i=0;i<=dg;i++){
        if(a.size() > i)
            poly1[i] = C(a[i],0);
        else
            poly1[i] = C(0,0);
        if(b.size() > i)
            poly2[i] = C(b[i],0);
        else
            poly2[i] = C(0,0);
    }

    mul(dg,dg);
    vector<long double> ret;
    for(int i=0;i<2*dg;i++)
        ret.pb(result[i].real());
    return ret; 

}
int rrank[maxn];

vector<long double> poly[maxn];

vector<long double> eval(int a,int b){
    if(a == b)return poly[a];
    int mid = (a+b)/2;
    vector<long double> p1 = eval(a,mid);
    vector<long double> p2 = eval(mid+1,b);
    return _fft(p1,p2);
}

main(){

    int n,caras, sum = 0;
    scanf("%d%d",&n,&caras);

    for(int i=0;i<n;i++)
        scanf("%d",rrank+i), sum += rrank[i];

    for(int i=0;i<n;i++){
        poly[i].pb(0.0);
        for(int j=1;j<=caras;j++){
            if(rrank[i] == j)
                poly[i].pb(0.0);
            else
                poly[i].pb(1.0/(caras-1));
        }
    }

    vector<long double> r = eval(0,n-1);

    long double p = 0;
    for(int i=0;i<sum;i++)
        p += r[i];
    printf("%.10lf\n",(double)p*(caras-1)+1);
}