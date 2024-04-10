#include <iostream>
#include <algorithm>
#include <vector>

#define NMAX 100005
using namespace std;

struct time{
    int val,st,dr;
    int pref,mid,suf;
    int pos_st,pos_dr;

    time(int val=0,int st=0,int dr=0,int pref=0,int mid=0,int suf=0,int pos_st=0,int pos_dr=0): val(val), st(st), dr(dr), pref(pref), mid(mid), suf(suf), pos_st(pos_st), pos_dr(pos_dr) {}
};

struct node{
    int st,dr;
    vector<time> times;

    node(int st=0,int dr=0): st(st), dr(dr) {}
}arb[4*NMAX];

int t;
time unite(time a,time &b){
    time c(t,a.st,b.dr);

    c.pref=a.pref;
    c.suf=b.suf;
    c.mid=max(max(a.mid,b.mid),a.suf+b.pref);

    if(a.dr-a.st+1==a.pref)
        c.pref=max(c.pref,a.pref+b.pref);
    if(b.dr-b.st+1==b.suf)
        c.suf=max(c.suf,a.suf+b.suf);

    return c;
}

void build(int st,int dr,int pos){
    arb[pos].st=st,arb[pos].dr=dr;
    arb[pos].times.push_back(time(0,st,dr));

    if(st==dr)
        return;

    int mijl=(st+dr)>>1;
    build(st,mijl,pos<<1);
    build(mijl+1,dr,(pos<<1)+1);
}

void update(int unde,int pos){
    if(arb[pos].st==arb[pos].dr){
        arb[pos].times.push_back(time(t,arb[pos].st,arb[pos].dr,1,1,1,0,0));
        return;
    }

    int mijl=(arb[pos].st+arb[pos].dr)>>1;
    if(unde<=mijl)
        update(unde,pos<<1);
    else
        update(unde,(pos<<1)+1);

    arb[pos].times.push_back(unite(arb[pos<<1].times[arb[pos<<1].times.size()-1],arb[(pos<<1)+1].times[arb[(pos<<1)+1].times.size()-1]));
    arb[pos].times.back().pos_st=arb[pos<<1].times.size()-1;
    arb[pos].times.back().pos_dr=arb[(pos<<1)+1].times.size()-1;
}

time aux;

void query(int st,int dr,int p,int pos){
    if(arb[pos].st==st && arb[pos].dr==dr){
        if(aux.st==-1)
            aux=arb[pos].times[p];
        else
            aux=unite(aux,arb[pos].times[p]);
        return;
    }

    int mijl=(arb[pos].st+arb[pos].dr)>>1;

    if(dr<=mijl)
        query(st,dr,arb[pos].times[p].pos_st,pos<<1);
    else if(st>mijl)
        query(st,dr,arb[pos].times[p].pos_dr,(pos<<1)+1);
    else{
        query(st,mijl,arb[pos].times[p].pos_st,pos<<1);
        query(mijl+1,dr,arb[pos].times[p].pos_dr,(pos<<1)+1);
    }
}

struct elem{
    int val;
    int poz;
}v[NMAX];

bool operator<(const elem &a,const elem &b){
    return a.val>b.val;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n=0;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>v[i].val;
        v[i].poz=i;
    }

    sort(v+1,v+n+1);
    build(1,n,1);

    for(int i=1;i<=n;i++){
        t=i;
        update(v[i].poz,1);
    }

    int q=0;

    cin>>q;

    int l,r,w;

    int st,dr,mijl,rasp;
    while(q--){
        cin>>l>>r>>w;

        st=1;
        dr=n;
        mijl=(1+n)>>1;
        rasp=n;

        while(st<=dr){
            aux.st=-1;
            query(l,r,mijl,1);

            if(aux.mid>=w){
                rasp=mijl;
                dr=mijl-1;
            }
            else
                st=mijl+1;

            mijl=(st+dr)>>1;
        }

        cout<<v[rasp].val<<'\n';
    }

    return 0;
}