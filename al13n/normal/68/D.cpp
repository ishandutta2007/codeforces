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

struct vert{
    int val;
    int sum;
    vert *l,*r;
} vertalloc[10000000];
int vertcnt;
vert* alloc(){
    vert *r=vertalloc+vertcnt++;
    return r;
}

vert *root=alloc();

int path[100];
int pl;

void add(vert *v,int val,int p){
    v->sum+=val;
    if(p==pl){
        v->val+=val;
        return;
    }
    if(path[p]){
        if(!v->r)
            v->r=alloc();
        add(v->r,val,p+1);
    }else{
        if(!v->l)
            v->l=alloc();
        add(v->l,val,p+1);
    }
}
double get(vert *v,int mx){
    if(!v)
        return mx;
    int s1=0,s2=0;
    if(v->l)
        s1=v->l->sum;
    if(v->r)
        s2=v->r->sum;
    if(!s1&&!s2)
        return max(mx,v->val);
    if(s2>s1)
        return (max(mx,v->r->sum+v->val)+get(v->r,max(mx,v->val+s1)))*0.5;
    else
        return (max(mx,v->l->sum+v->val)+get(v->l,max(mx,v->val+s2)))*0.5;
}
void getpath(int k){
    pl=0;
    while(k>1){
        path[pl++]=k%2;
        k/=2;
    }
    reverse(path,path+pl);
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    int h,q;
    scanf("%d%d\n",&h,&q);
    forn(qqq,q){
        char line[100];
        scanf("%s",line);
        if(line[0]=='a'){
            int v,e;
            scanf("%d%d\n",&v,&e);
            getpath(v);
            add(root,e,0);
        }else if(line[0]=='d'){
            scanf("\n");
            printf("%.10lf\n",get(root,0));
        }else
            exit(123);
    }

    return 0;
}