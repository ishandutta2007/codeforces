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

struct vec{
    int x,y,id;
    vec(){}
    vec(int x,int y):x(x),y(y){}
    void read(){
        cin>>x>>y;
    }
    lng dot(const vec &b)const{
        return ((lng)x)*b.x+((lng)y)*b.y;
    }
    bool operator<(const vec &b)const{
        if(x!=b.x)
            return x<b.x;
        return y<b.y;
    }
    vec rperp()const{
        return vec(y,-x);
    }
    bool cw(const vec &b)const{
        return b.dot(rperp())>0;
    }
    vec operator-(const vec &b)const{
        return vec(x-b.x,y-b.y);
    }
    vec operator+(const vec &b)const{
        return vec(x+b.x,y+b.y);
    }
};

vec ars[20][110000];
int len[20][110000];

int hullify(vec *ar,int n){
    int l=1;
    for(int i=1;i<n;++i){
        vec v=ar[i];
        while(l>0&&v.y>=ar[l-1].y)
            --l;
        while(l>1&&!(ar[l-1]-ar[l-2]).cw(v-ar[l-1]))
            --l;
        ar[l++]=v;
    }
    return l;
}

void build(int a,int b,int d){
    if(b==a+1){
        len[d][a]=1;
        return;
    }
    int c=(a+b)/2;
    build(a,c,d+1);
    build(c,b,d+1);
    merge(ars[d+1]+a,ars[d+1]+a+len[d+1][a],ars[d+1]+c,ars[d+1]+c+len[d+1][c],ars[d]+a);
    len[d][a]=hullify(ars[d]+a,len[d+1][a]+len[d+1][c]);
}

pair<lng,int> subquery(vec v,vec *ar,int n){
    int a=-1,b=n-1;
    while(b>a+1){
        int k=(a+b)/2;
        lng t1=v.dot(ar[k]);
        lng t2=v.dot(ar[k+1]);
        if(t2>t1)
            a=k;
        else
            b=k;
    }
    return mp(v.dot(ar[b]),ar[b].id);
}

pair<lng,int> query(vec v,int l,int r,int a,int b,int d){
    if(l==a&&r==b)
        return subquery(v,ars[d]+a,len[d][a]);
    int c=(a+b)/2;
    if(r<=c)
        return query(v,l,r,a,c,d+1);
    if(l>=c)
        return query(v,l,r,c,b,d+1);
    return max(query(v,l,c,a,c,d+1),query(v,c,r,c,b,d+1));
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);

    int n,q;
    cin>>n>>q;
    forn(i,n){
        ars[0][i].read();
        ars[0][i].id=i;
    }
    forn(i,19)
        memcpy(ars[i+1],ars[i],sizeof(ars[i]));
    build(0,n,0);

    forn(i,q){
        int a,b,t;
        cin>>a>>b>>t;
        --a;
        cout<<query(vec(1,t),a,b,0,n,0).second+1<<'\n';
    }

    return 0;
}