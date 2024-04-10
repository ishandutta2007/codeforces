#pragma comment(linker,"/STACK:228000000")
#include <vector>
#include <string.h>
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

using namespace std;
#define forn(i,n) for(int i=0;i<n;++i)
#define lng long long
#define PI 3.1415926535897932384626433832795
#define SQ(a) ((a)*(a))
#define sqr(a) ((a)*(a))
#define VI vector<int>
#define VD vector<double>
#define VS vector<string>
#define forv(i,v) for(int i=0;i<(int)v.size();++i)
#define forvr(i,v) for(int i=(int)v.size()-1;i>=0;--i)
#define all(a) (a).begin(),(a).end()
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define ABS(a) ((a)<0?-(a):(a))
#define EQ(a,b) (ABS((a)-(b))<eps)
#define iinf 1000000000
#define dinf 100000000000000000000.0
#define linf 1000000000000000000LL
#define y1 asdy1
#define y2 asdy2
#define DEG2RAD 0.01745329251994329576923690768489
#define eps 1e-8
#define prev asdprev
#define left asdleft
#define fixed asdfixed
#define y0 asdy0

struct vec{
    int x,y;
    vec(){}
    vec(int x,int y):x(x),y(y){}
    void write(){
        printf("%d %d\n",x,y);
    }
};

vec res[1000000];
int cnt;

struct event{
    int t,h,id;
    bool op;
    event(){}
    event(int t,int h,int id,bool op):t(t),h(h),id(id),op(op){}
    bool operator<(const event &b)const{
        return t<b.t;
    }
};

event evs[1000000];
int cevs;

int main()
{
//#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
//#endif

    int n;
    cin>>n;
    forn(i,n){
        int h,l,r;
        cin>>h>>l>>r;
        evs[cevs++]=event(l,h,i,true);
        evs[cevs++]=event(r,h,i,false);
    }
    sort(evs,evs+cevs);
    set<pair<int,int> > st;
    int i=0;
    int h=0;
    while(i<cevs){
        int j=i+1;
        while(j<cevs&&evs[j].t==evs[i].t)
            ++j;
        for(int k=i;k<j;++k){
            if(evs[k].op)
                st.insert(mp(evs[k].h,evs[k].id));
            else
                st.erase(mp(evs[k].h,evs[k].id));
        }
        int hh=0;
        if(!st.empty())
            hh=st.rbegin()->first;
        if(hh!=h){
            res[cnt++]=vec(evs[i].t,h);
            res[cnt++]=vec(evs[i].t,hh);
            h=hh;
        }
        i=j;
    }
    cout<<cnt<<endl;
    forn(i,cnt)
        res[i].write();

    return 0;
}