#pragma comment(linker,"/STACK:228000000")
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
#define fornr(i,n) for(int i=(n)-1;i>=0;--i)
#define lng long long
#define ulng unsigned long long
#define PI 3.1415926535897932384626433832795
#define SQ(a) ((a)*(a))
#define sqr(a) ((a)*(a))
#define VI vector<int>
#define VD vector<double>
#define VS vector<string>
#define forv(i,v) for(int i=0;i<(int)v.size();++i)
#define forvr(i,v) for(int i=(int)v.size()-1;i>=0;--i)
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define ABS(a) ((a)<0?-(a):(a))
#define EQ(a,b) (ABS((a)-(b))<eps)
#define iinf 1000000000
#define dinf 100000000000000000000.0
#define linf 1000000000000000000LL
#define y0 asdy0
#define y1 asdy1
#define y2 asdy2
#define DEG2RAD 0.01745329251994329576923690768489
#define eps 1e-12
#define prev asdprev
#define left asdleft
#define fixed asdfixed
#define time asdtime
#define free asdfree
#define ends asdends
inline lng abs(lng a){return a<0?-a:a;}

lng gcd(lng a,lng b){
    return a?gcd(b%a,a):b;
}

struct frac{
    lng a,b;
    void norm(){
        if(b<0)
            a*=-1,b*=-1;
        lng g=gcd(abs(a),b);
        a/=g,b/=g;
    }
    frac(lng a,lng b):a(a),b(b){
        norm();
    }
    bool operator<(const frac &f)const{
        return a*f.b<b*f.a;
    }
    lng down()const{
        if(a<0)
            return -((-a+b-1)/b);
        else
            return a/b;
    }
    lng up()const{
        if(a<0)
            return -((-a)/b);
        else
            return (a+b-1)/b;
    }
};

pair<lng,lng> src[1100];

int main(int argc,char **argv){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    int n;
    cin>>n;
    forn(i,n)
        cin>>src[i].first>>src[i].second;
    if(src[1].first<src[0].first){
        rotate(src,src+2,src+n);
        reverse(src,src+n);
        forn(i,n)
            src[i].second*=-1;
    }
    lng y0=src[0].second;
    frac xx1(src[0].first,1),xx2(src[1].first,1);
    for(int i=1;i<n;++i){
        lng x1,y1,x2,y2;
        x1=src[i].first;
        y1=src[i].second;
        x2=src[(i+1)%n].first;
        y2=src[(i+1)%n].second;
        if(y1==y2){
            if(x2>x1){
                cout<<0;
                exit(0);
            }
            continue;
        }
        frac p((x2-x1)*(y0-y2)+x2*(y2-y1),y2-y1);
        if(y1<y2)
            xx1=max(xx1,p);
        else
            xx2=min(xx2,p);
    }
    lng t1=xx1.up(),t2=xx2.down();
    lng res=max(0LL,t2-t1+1);
    cout<<res;

    return 0;
}