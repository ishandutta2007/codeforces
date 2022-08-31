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
#define fornn(i,n) for(i=0;i<(n);++i)
#define lng long long
#define SQ(a) ((a)*(a))
#define forv(i,v) for(int i=0;i<(int)v.size();++i)
#define mp make_pair
#define pb push_back
#define ABS(a) ((a)<0?-(a):(a))
#define iinf 1000000000
#define left asdleft

struct node{
    int v;
    int pr;
    int sz;
    node *l,*r;
    node(){}
} nodealloc[1000000];
int nodecnt;

node *alloc(int v){
    node &n=nodealloc[nodecnt++];
    n.v=v;
    n.sz=1;
    n.pr=rand();
    return &n;
}

void post(node *n){
    if(!n)
        return;
    n->sz=1;
    if(n->l)
        n->sz+=n->l->sz;
    if(n->r)
        n->sz+=n->r->sz;
}

int sz(node *n){
    if(n)
        return n->sz;
    else
        return 0;
}

node *merge(node *a,node *b){
    if(!a)
        return b;
    if(!b)
        return a;
    if(a->pr<b->pr){
        a->r=merge(a->r,b);
        post(a);
        return a;
    }else{
        b->l=merge(a,b->l);
        post(b);
        return b;
    }
}

void split(int v,node *n,node *&a,node *&b){
    if(!n)
        return void(a=b=0);
    if(n->v<v){
        a=n;
        split(v,a->r,a->r,b);
        post(a);
    }else{
        b=n;
        split(v,b->l,a,b->l);
        post(b);
    }
}

int first(node *n){
    while(n->l)
        n=n->l;
    return n->v;
}

int last(node *n){
    while(n->r)
        n=n->r;
    return n->v;
}

struct seg{
    int a,b;
    seg(){}
    seg(int a,int b):a(a),b(b){}
    bool operator<(const seg &s)const{
        return mp(b-a,a)<mp(s.b-s.a,s.a);
    }
};

priority_queue<seg> qu;

node *root;

int getcnt(int a,int b){
    node *l,*c,*r;
    split(a,root,l,c);
    split(b+1,c,c,r);
    int res=sz(c);
    l=merge(l,c);
    root=merge(l,r);
    return res;
}

bool valid(const seg &s){
    node *l,*c,*r;
    split(s.a,root,l,c);
    split(s.b+1,c,c,r);
    bool res=!c&&(!r||first(r)==s.b+1)&&(!l||last(l)==s.a-1);
    l=merge(l,c);
    root=merge(l,r);
    return res;
}

int addcoat(){
    seg s;
    do{
        s=qu.top();
        qu.pop();
    }while(!valid(s));
    int p=(s.b+s.a+1)/2;
    node *l,*r;
    split(p,root,l,r);
    l=merge(l,alloc(p));
    root=merge(l,r);
    if(s.a<=p-1)
        qu.push(seg(s.a,p-1));
    if(s.b>=p+1)
        qu.push(seg(p+1,s.b));
    return p;
}

void delcoat(int p){
    node *l,*c,*r;
    split(p,root,l,c);
    split(p+1,c,c,r);
    qu.push(seg(last(l)+1,first(r)-1));
    root=merge(l,r);
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

    int len,tc;
    cin>>len>>tc;
    root=merge(alloc(0),alloc(len+1));
    qu.push(seg(1,len));
    map<int,int> place;
    forn(qqq,tc){
        int v;
        scanf("%d",&v);
        if(!v){
            int a,b;
            scanf("%d%d",&a,&b);
            printf("%d\n",getcnt(a,b));
        }else{
            if(place[v]){
                delcoat(place[v]);
                place[v]=0;
            }else{
                place[v]=addcoat();
            }
        }
    }

    return 0;
}