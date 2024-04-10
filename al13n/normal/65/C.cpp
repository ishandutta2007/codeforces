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
#ifdef __ASD__
//#include "my.h" // project euler thingy
#endif

struct vec{
    double x,y,z;
    vec(){}
    vec(double x,double y,double z):x(x),y(y),z(z){}
    void read(){
        cin>>x>>y>>z;
    }
    vec operator-(const vec &b)const{
        return vec(x-b.x,y-b.y,z-b.z);
    }
    vec operator+(const vec &b)const{
        return vec(x+b.x,y+b.y,z+b.z);
    }
    vec operator*(double b)const{
        return vec(x*b,y*b,z*b);
    }
    double dot(const vec &b)const{
        return x*b.x+y*b.y+z*b.z;
    }
    double len(){
        return sqrt(dot(*this));
    }
};

vec src[100000];
vec p0;
double vs,vp;
int n;

int main(int argc,char **argv){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    cin>>n;
    forn(i,n+1)
        src[i].read();
    cin>>vp>>vs;
    p0.read();

    double q=0;
    forn(i,n){
        if((p0-src[i+1]).len()/vp>(q+(src[i+1]-src[i]).len())/vs){
            q+=(src[i+1]-src[i]).len();
            continue;
        }
        double a=0,b=1;
        forn(qqqqq,1000){
            double v=(a+b)*0.5;
            if((p0-(src[i]+(src[i+1]-src[i])*v)).len()/vp<(q+v*(src[i+1]-src[i]).len())/vs)
                b=v;
            else
                a=v;
        }
        vec p=src[i]+(src[i+1]-src[i])*a;
        double t=(q+a*(src[i+1]-src[i]).len())/vs;
        printf("YES\n%.10lf\n%.10lf %.10lf %.10lf",t,p.x,p.y,p.z);
        exit(0);
    }
    cout<<"NO";

    return 0;
}