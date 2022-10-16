#include <iostream>
#include <algorithm>
#include <string>

#define NMAX 1000005
using namespace std;

struct nod
{
    int st;
    int dr;

    int zero;
    int unu;

    int cresc;
    int desc;

    bool lazy;

    nod(int st=0,int dr=0,int zero=0,int unu=0,int cresc=0,int desc=0,bool lazy=0): st(st), dr(dr), zero(zero), unu(unu), cresc(cresc), desc(desc), lazy(lazy) {}

}arb[4*NMAX];

char sir[NMAX];

inline void make_lazy(nod &a)
{
    a.lazy^=1;

    swap(a.zero,a.unu);
    swap(a.cresc,a.desc);
}

inline void fii_lazy(int nod)
{
    make_lazy(arb[nod<<1]);
    make_lazy(arb[(nod<<1)+1]);

    arb[nod].lazy=0;
}

inline void unite(nod &a,nod &b,nod &c)
{
    a.zero=b.zero+c.zero;
    a.unu=b.unu+c.unu;

    a.cresc=max(b.cresc+c.unu,b.zero+c.cresc);
    a.desc=max(b.desc+c.zero,b.unu+c.desc);
}

void build(int st,int dr,int nod)
{
    arb[nod].st=st;
    arb[nod].dr=dr;


    if(st==dr){
        arb[nod].cresc=arb[nod].desc=1;

        if(sir[st]=='4')
            arb[nod].zero=1;
        else
            arb[nod].unu=1;
        return;
    }

    int mijl=(st+dr)>>1;
    build(st,mijl,nod<<1);
    build(mijl+1,dr,(nod<<1)+1);

    unite(arb[nod],arb[nod<<1],arb[(nod<<1)+1]);
}

void update(int st,int dr,int nod)
{
    if(arb[nod].st==st && arb[nod].dr==dr){
        make_lazy(arb[nod]);
        return;
    }

    if(arb[nod].lazy)
        fii_lazy(nod);

    int mijl=(arb[nod].st+arb[nod].dr)>>1;
    if(dr<=mijl)
        update(st,dr,nod<<1);
    else if(st>mijl)
        update(st,dr,(nod<<1)+1);
    else{
        update(st,mijl,nod<<1);
        update(mijl+1,dr,(nod<<1)+1);
    }

    unite(arb[nod],arb[nod<<1],arb[(nod<<1)+1]);
}

int main()
{
    int n=0,m=0;
    cin>>n>>m;

    cin.get();
    cin.get(sir+1,NMAX);

    build(1,n,1);

    string aux;
    while(m--){
        cin>>aux;

        if(aux=="count")
            cout<<arb[1].cresc<<'\n';
        else{
            int a,b;
            cin>>a>>b;

            update(a,b,1);
        }
    }

    return 0;
}