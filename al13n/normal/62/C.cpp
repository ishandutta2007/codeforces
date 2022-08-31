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
#ifdef __ASD__
//#include "my.h" // project euler thingy
#endif

struct vec{
    double x,y;
    vec(){}
    vec(double x,double y):x(x),y(y){}
    double dot(const vec &b)const{
        return x*b.x+y*b.y;
    }
    vec perp()const{
        return vec(-y,x);
    }
    double len()const{
        return sqrt(dot(*this));
    }
    vec norm()const{
        double l=len();
        return vec(x/l,y/l);
    }
    vec operator-(const vec &b)const{
        return vec(x-b.x,y-b.y);
    }
    vec operator+(const vec &b)const{
        return vec(x+b.x,y+b.y);
    }
    vec operator*(double b)const{
        return vec(x*b,y*b);
    }
    void read(){
        cin>>x>>y;
    }
};
struct plane{
    vec n;
    double d;
    plane(){}
    plane(vec a,vec b){
        n=(a-b).perp().norm();
        d=n.dot(a);
    }
    double dist(const vec &p)const{
        return n.dot(p)-d;
    }
    void flip(){
        n=n*-1;
        d=-d;
    }
    bool intersect(const plane &b,vec &res)const{
        vec t=n.perp();
        vec p=n*d;
        double q=b.n.dot(t);
        if(fabs(q)<eps)
            return false;
        res=p-t*(b.dist(p)/q);
        return true;
    }
};
struct tri{
    vec a,b,c;
    plane p1,p2,p3;
    tri(){}
    tri(vec a,vec b,vec c):a(a),b(b),c(c),p1(a,b),p2(b,c),p3(c,a){
        if(!contains((a+b+c)*(1.0/3))){
            p1.flip();
            p2.flip();
            p3.flip();
        }
    }
    bool contains(const vec &p)const{
        return p1.dist(p)>0&&p2.dist(p)>0&&p3.dist(p)>0;
    }
};

tri src[110];
int n;

double subsolve(vec a,vec b,int me){
    vector<double> pts;
    plane pl(a,b);
    vec li=pl.n.perp();
    vec p0=pl.n*pl.d;
    double val1=li.dot(a-p0),val2=li.dot(b-p0);
    if(val2<val1)
        swap(val2,val1);
    pts.pb(val1);
    pts.pb(val2);
    forn(i,n){
        if(i==me)
            continue;
        vec ar[3]={src[i].a,src[i].b,src[i].c};
        forn(q,3){
            plane tp(ar[q],ar[(q+1)%3]);
            vec t;
            if(/*pl.dist(ar[q])*pl.dist(ar[(q+1)%3])<=eps&&*/pl.intersect(tp,t)){
                double d=li.dot(t-p0);
                if(d>val1&&d<val2)
                    pts.pb(d);
            }
        }
    }
    sort(all(pts));
    double res=0;
    forn(i,pts.size()-1){
        vec p=p0+li*((pts[i]+pts[i+1])/2);
        bool black=false;
        forn(k,n){
            if(k==me)
                continue;
            if(src[k].contains(p)){
                black=true;
                break;
            }
        }
        if(!black)
            res+=pts[i+1]-pts[i];
    }
    return res;
}

int main(int argc,char **argv){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    cin>>n;
    forn(i,n){
        vec a,b,c;
        a.read();
        b.read();
        c.read();
        src[i]=tri(a,b,c);
    }

    double res=0;
    forn(i,n){
        double t;
        t=subsolve(src[i].a,src[i].b,i);
        res+=t;
        t=subsolve(src[i].b,src[i].c,i);
        res+=t;
        t=subsolve(src[i].c,src[i].a,i);
        res+=t;
    }
    printf("%.10lf",res);

    return 0;
}