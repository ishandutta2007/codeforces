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
#include <memory.h>
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
#define linf SQ(1LL*iinf)
#define left asdleft
#define prev asdprev
#define hash asdhash
#define eps 1e-8
#define y1 asdy1
#define y2 asdy2
#define EQ(a,b) abs((a)-(b))<eps
#define PI 3.1415926535897932384626433832795
#define DEG2RAD PI/180
#define ulng unsigned lng
const double dinf = 1e200;
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

char S1[1100000];
char S2[1100000];
int F[1100000];
int T[1100000];
int G[1100000];
char tmp[2100000];
int zf[2100000];
int n;

void zfunc(int n){
    memset(zf,0,sizeof(zf));
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            zf[i] = min (r-i+1, zf[i-l]);
        while (i+zf[i] < n && tmp[zf[i]] == tmp[i+zf[i]])
            ++zf[i];
        if (i+zf[i]-1 > r)
            l = i,  r = i+zf[i]-1;
    }
}

void genF(){
    memcpy(tmp,S2,n);
    tmp[n]=1;
    memcpy(tmp+n+1,S1,n);
    zfunc(n+n+1);
    forn(i,n)
        F[i]=zf[n+1+i];
}

void genT(){
    memcpy(tmp,S1,n);
    reverse(tmp,tmp+n);
    tmp[n]=1;
    memcpy(tmp+n+1,S2,n);
    zfunc(n+n+1);
    forn(i,n)
        T[i]=zf[n+1+i];
}

pair<int,int> qu[2100000];
int qua,qub;
void genG(){
    forn(q,n+1){
        int b=q+T[q];
        while(qua<qub&&qu[qua].second<q)
            ++qua;
        if(qub==qua||b>qu[qub-1].second)
            qu[qub++]=mp(q,b);
        G[q]=q-qu[qua].first;
    }
}

#define taska "four"
int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
    //freopen(taska".in","r",stdin);freopen(taska".out","w",stdout);
#endif

    //ios_base::sync_with_stdio(false);

    gets(S1);
    gets(S2);
    n=strlen(S1);
    if(strlen(S2)!=n){
        cout<<"-1 -1";
        return 0;
    }

    genF();
    genT();
    genG();

    pair<int,int> res(-1,1);
    for(int p=1;p<n;++p){
        if(S2[n-p]!=S1[p-1])
            break;
        if(G[n-p]>0&&F[p]+G[n-p]>=n-p)
            res=max(res,mp(p-1,G[n-p]-n));
    }
    cout<<res.first<<' '<<-res.second;

    return 0;
}