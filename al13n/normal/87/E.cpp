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
void mytimer(string task){
#ifdef __ASD__
    static LARGE_INTEGER prev;  LARGE_INTEGER cur,freq; QueryPerformanceCounter(&cur);  QueryPerformanceFrequency(&freq);   if(task!="")        cout<<task<<" took "<<(cur.QuadPart-prev.QuadPart)*1.0/freq.QuadPart<<endl; prev=cur;
#endif
}

lng gcd(lng a,lng b){
    return a?gcd(b%a,a):b;
}
lng abs(lng a){
    return a<0?-a:a;
}

struct vec{
    lng x,y;
    double ang;
    vec(){}
    vec(lng x,lng y):x(x),y(y){}
    vec operator+(const vec &b)const{
        return vec(x+b.x,y+b.y);
    }
    vec operator-(const vec &b)const{
        return vec(x-b.x,y-b.y);
    }
    lng dot(const vec &b)const{
        return x*b.x+y*b.y;
    }
    void getang(){
        lng g=gcd(abs(x),abs(y));
        ang=atan2(.0+y/g,.0+x/g);
    }
    bool lexl(const vec &b)const{
        if(y!=b.y)
            return y<b.y;
        return x>b.x;
    }
    bool operator<(const vec &b)const{
        return ang<b.ang;
    }
    void read(){
        int a,b;
        scanf("%d%d",&a,&b);
        x=a,y=b;
    }
};

struct event{
    int type;
    int id;
    vec p1,p2;
    event(){}
    bool operator<(const event &b)const{
        if(p1.x!=b.p1.x)
            return p1.x<b.p1.x;
        return type<b.type;
    }
};

int sgn(lng a){
    if(a<0)
        return -1;
    if(a>0)
        return 1;
    return 0;
}

int compare(const vec &p,const event &e){
    if(p.x<e.p1.x||p.x>e.p2.x)
        return -2;
    vec n(e.p2.y-e.p1.y,e.p1.x-e.p2.x);
    return sgn(n.dot(p-e.p1));
}

vec sides[200000];
int n;
event evs[500000];
int cnt;
vec pts[200000];

bool ans[200000];

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    vec ori(0,0);
    forn(q,3){
        int m;
        cin>>m;
        vec mx(-iinf,-iinf);
        forn(i,m){
            vec v;
            v.read();
            if(mx.lexl(v))
                mx=v;
            pts[i]=v;
        }
        ori=ori+mx;
        forn(i,m){
            sides[n]=pts[(i+1)%m]-pts[i];
            sides[n].getang();
            ++n;
        }
    }
    int m;
    cin>>m;
    forn(i,m){
        vec v;
        v.read();
        v.x*=3;
        v.y*=3;
        evs[cnt].id=i;
        evs[cnt].type=2;
        evs[cnt].p1=v;
        ++cnt;
    }

    sort(sides,sides+n);
    vec p=ori;
    forn(i,n){
        vec q=p+sides[i];
        if(q.x<p.x){
            evs[cnt].type=0;
            evs[cnt].p1=q;
            evs[cnt].p2=p;
            ++cnt;
        }
        if(q.x>p.x){
            evs[cnt].type=1;
            evs[cnt].p1=p;
            evs[cnt].p2=q;
            ++cnt;
        }
        p=q;
    }

    sort(evs,evs+cnt);

    event u[2];
    bool nothing=true;
    forn(q,cnt){
        if(evs[q].type==2){
            int c1,c2;
            if(nothing)
                c1=c2=-2;
            else{
                c1=compare(evs[q].p1,u[0]);
                c2=compare(evs[q].p1,u[1]);
            }
            if(c1==-2||c2==-2)
                if(c1==-2&&c2==-2)
                    ans[evs[q].id]=false;
                else
                    exit(123);
            else
                ans[evs[q].id]=c1>=0&&c2<=0;
        }else{
            nothing=false;
            u[evs[q].type]=evs[q];
        }
    }

    forn(i,m)
        if(ans[i])
            printf("YES\n");
        else
            printf("NO\n");

    return 0;
}