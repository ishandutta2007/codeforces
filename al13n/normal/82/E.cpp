#pragma comment (linker, "/STACK:90000000")
#include <string>
#include <memory.h>
#include <cassert>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <utility>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forv(i, v) for (int i = 0; i < (int)(v.size()); ++i)
#define fors(i, s) for (int i = 0; i < (int)(s.length()); ++i)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-9
#define iinf 1000000000
#define SQ(a) ((a)*(a))
#define EQ(a,b) fabs((a)-(b))<eps

struct vec{
    double x,y;
    vec(){}
    vec(double x,double y):x(x),y(y){}
    bool operator<(const vec &b)const{
        return false;
    }
};

struct seg{
    double a,b;
    seg(){}
    seg(lng a,lng b):a(a),b(b){}
};

double H,F;

bool seginters(seg a,seg b,vec &res){
    if((a.a-b.a)*(a.b-b.b)>=-eps)
        return false;
    double t=abs(a.a-b.a)*1.0/abs(a.b-b.b);
    double x=(t*a.b+a.a)/(t+1);
#ifdef __ASD__
    if(!EQ(x,(t*b.b+b.a)/(t+1)))
        exit(321);
#endif
    res=vec(x,H*(1-t)/(t+1));
    return true;
}

double intersect(seg l1,seg r1,seg l2,seg r2){
    vector<pair<double,vec> > pts;
    vec t;
    if(seginters(l1,l2,t))
        pts.pb(mp(.0,t));
    if(seginters(l1,r2,t))
        pts.pb(mp(.0,t));
    if(seginters(r1,l2,t))
        pts.pb(mp(.0,t));
    if(seginters(r1,r2,t))
        pts.pb(mp(.0,t));
    if(l1.a>=l2.a&&l1.a<=r2.a)
        pts.pb(mp(.0,vec(l1.a,H)));
    if(r1.a>=l2.a&&r1.a<=r2.a)
        pts.pb(mp(.0,vec(r1.a,H)));
    if(l2.a>=l1.a&&l2.a<=r1.a)
        pts.pb(mp(.0,vec(l2.a,H)));
    if(r2.a>=l1.a&&r2.a<=r1.a)
        pts.pb(mp(.0,vec(r2.a,H)));
    if(l1.b>=l2.b&&l1.b<=r2.b)
        pts.pb(mp(.0,vec(l1.b,-H)));
    if(r1.b>=l2.b&&r1.b<=r2.b)
        pts.pb(mp(.0,vec(r1.b,-H)));
    if(l2.b>=l1.b&&l2.b<=r1.b)
        pts.pb(mp(.0,vec(l2.b,-H)));
    if(r2.b>=l1.b&&r2.b<=r1.b)
        pts.pb(mp(.0,vec(r2.b,-H)));

    if(pts.size()==0)
        return 0;
#ifdef __ASD__
    if(pts.size()<3)
        exit(123);
#endif

    vec av(0,0);
    forv(i,pts){
        av.x+=pts[i].second.x/pts.size();
        av.y+=pts[i].second.y/pts.size();
    }
    forv(i,pts)
        pts[i].first=atan2(pts[i].second.y-av.y,pts[i].second.x-av.x);
    sort(all(pts));

    double res=0;
    forv(i,pts){
        int ii=(i+1)%pts.size();
        res+=pts[i].second.x*pts[ii].second.y-pts[i].second.y*pts[ii].second.x;
    }

    return fabs(res)/2;
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    int n;
    cin>>n>>H>>F;
    F-=H;
    vector<seg> hol(n);
    forn(i,n)
        cin>>hol[i].a>>hol[i].b;
    double res=0;
    forn(i,n){
        seg l1,r1;
        l1.a=hol[i].a;
        r1.a=hol[i].b;
        l1.b=hol[i].a*(F+H+H)/F;
        r1.b=hol[i].b*(F+H+H)/F;
        res+=((r1.a-l1.a)+(r1.b-l1.b))*H*2;
        forn(j,n){
            seg l2,r2;
            l2.b=hol[j].a;
            r2.b=hol[j].b;
            l2.a=hol[j].a*(F+H+H)/F;
            r2.a=hol[j].b*(F+H+H)/F;

            double t=intersect(l1,r1,l2,r2);
            res-=t;
        }
    }

    printf("%.10lf",res);

    return 0;
}