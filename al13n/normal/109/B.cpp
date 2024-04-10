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
#define linf 1000000000000000000LL
#define dinf 1e200
#define left asdleft
#define prev asdprev
#define eps 1e-12
#define y1 asdy1
#define y2 asdy2
#define EQ(a,b) abs((a)-(b))<eps
#define PI 3.1415926535897932384626433832795
#define DEG2RAD PI/180
#define ulng unsigned lng
#define next asdnext
#define prev asdprev
void mytimer(string task){
#ifdef __ASD__
    static LARGE_INTEGER prev;  LARGE_INTEGER cur,freq; QueryPerformanceCounter(&cur);  QueryPerformanceFrequency(&freq);   if(task!="")        cout<<task<<" took "<<(cur.QuadPart-prev.QuadPart)*1.0/freq.QuadPart<<endl; prev=cur;
#endif
}
void ext(int c){
#ifdef __ASD__
    exit(c);
#endif
}

int a1,a2,b1,b2;
int k;
vector<int> lucky;

void gen(int a,int l){
    if(l==10)
        return;
    if(a)
        lucky.pb(a);
    gen(a*10+4,l+1);
    gen(a*10+7,l+1);
}

double doit1(int v1,int v2){
    v1=max(v1,a1);
    v2=min(v2,a2);
    if(v2<v1)
        return 0;
    return 1.*(v2-v1+1)/(a2-a1+1);
}

double doit2(int v1,int v2){
    v1=max(v1,b1);
    v2=min(v2,b2);
    if(v2<v1)
        return 0;
    return 1.*(v2-v1+1)/(b2-b1+1);
}

//double doit12(int v1,int v2){
//  int i1=max(max(a1,b1),v1);
//  int i2=min(min(a2,b2),v2);
//  if(i2<i1)
//      return doit1(v1,v2)*doit2(v1,v2);
//  int p1=max(a1,v1);
//  int p2=min(a2,v2);
//  int q1=max(b1,v1);
//  int q2=min(b2,v2);
//  return 
//  v1=max(v1,a1);
//  v2=min(v2,a2);
//  if(v2<v1)
//      return 0;
//
//}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    cin>>a1>>a2>>b1>>b2>>k;

    gen(0,0);
    lucky.pb(iinf+100);
    lucky.pb(-100);
    sort(all(lucky));

    double res=0;
    for(int i=1;i+k<lucky.size();++i){
        int p1=lucky[i-1]+1;
        int p2=lucky[i];
        int q1=lucky[i+k-1];
        int q2=lucky[i+k]-1;
        if(p2==q1){
            res+=doit1(p1,p2)*doit2(q1+1,q2)+doit2(p1,p2)*doit1(q1+1,q2)+doit1(p2,p2)*doit2(p1,p2-1)+doit2(p2,p2)*doit1(p1,p2);
        }else{
            res+=doit1(p1,p2)*doit2(q1,q2)+doit2(p1,p2)*doit1(q1,q2);
        }
    }

    printf("%.15lf",res);

    return 0;
}