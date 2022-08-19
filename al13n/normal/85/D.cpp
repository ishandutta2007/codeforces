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

int pts[110000];
int cnt;

lng stat[600000][5];
int shift[600000];
int trcnt[600000];

void pre(int a,int b,int k){
    shift[k]%=5;
    if(!shift[k])
        return;
    rotate(stat[k],stat[k]+shift[k],stat[k]+5);
    if(b>a+1){
        shift[k*2+1]+=shift[k];
        shift[k*2+2]+=shift[k];
    }
    shift[k]=0;
}
void post(int a,int b,int k){
    if(b>a+1){
        pre(a,b,k);
        pre(a,b,k*2+1);
        pre(a,b,k*2+2);
        forn(i,5)
            stat[k][i]=stat[k*2+1][i]+stat[k*2+2][i];
        trcnt[k]=trcnt[k*2+1]+trcnt[k*2+2];
    }
}

void shiftme(int s,int l,int r,int a,int b,int k){
    if(l==r)
        return;
    if(l==a&&r==b){
        shift[k]+=s;
        return;
    }
    pre(a,b,k);
    int c=(a+b)/2;
    if(r<=c)
        shiftme(s,l,r,a,c,k*2+1);
    else if(l>=c)
        shiftme(s,l,r,c,b,k*2+2);
    else{
        shiftme(s,l,c,a,c,k*2+1);
        shiftme(s,c,r,c,b,k*2+2);
    }
    post(a,b,k);
}

void addme(int p,int v,int t,int a,int b,int k){
    pre(a,b,k);
    if(b==a+1){
        stat[k][t]+=v;
        trcnt[k]+=v>0?1:-1;
        return;
    }
    int c=(a+b)/2;
    if(p<c)
        addme(p,v,t,a,c,k*2+1);
    else
        addme(p,v,t,c,b,k*2+2);
    post(a,b,k);
}

int cntless(int v,int a,int b,int k){
    if(!v)
        return 0;
    if(v==b)
        return trcnt[k];
    int c=(a+b)/2;
    if(v<=c)
        return cntless(v,a,c,k*2+1);
    else
        return trcnt[k*2+1]+cntless(v,c,b,k*2+2);
}

char qtype[110000];
int qa[110000];
int tc;

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    cin>>tc;
    int n=0;
    forn(i,tc){
        char cmd[10];
        scanf("%s",cmd);
        qtype[i]=cmd[0];
        if(cmd[0]!='s'){
            int a;
            scanf("%d",&a);
            qa[i]=a;
            if(cmd[0]=='a')
                pts[cnt++]=a;
        }
    }
    sort(pts,pts+cnt);
    cnt=unique(pts,pts+cnt)-pts;

    if(!cnt)
        cnt=1;

    forn(i,tc){
        if(qtype[i]=='s'){
            pre(0,cnt,0);
            printf("%I64d\n",stat[0][2]);
        }else if(qtype[i]=='a'){
            int p=lower_bound(pts,pts+cnt,qa[i])-pts;
            shiftme(4,p,cnt,0,cnt,0);
            addme(p,pts[p],cntless(p,0,cnt,0)%5,0,cnt,0);
        }else{
            int p=lower_bound(pts,pts+cnt,qa[i])-pts;
            addme(p,-pts[p],cntless(p,0,cnt,0)%5,0,cnt,0);
            shiftme(1,p,cnt,0,cnt,0);
        }
    }

    return 0;
}