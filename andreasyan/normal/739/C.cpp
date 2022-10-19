#include <bits/stdc++.h>
using namespace std;
const int N=300005;

struct ban
{
    long long laz;
    int e;
    int maxs,maxl,maxr;
    int nl,nr;
    long long l,r;
    void nor(long long x)
    {
        laz=0;
        e=1;
        maxs=maxl=maxr=1;
        nl=nr=1;
        l=r=x;
    }
    void mer(const ban& ll,const ban& rr)
    {
        e=ll.e+rr.e;
        maxs=max(ll.maxs,rr.maxs);
        maxl=ll.maxl;
        maxr=rr.maxr;
        nl=ll.nl;
        nr=rr.nr;
        l=ll.l;
        r=rr.r;
        //////////////////////////
        if(ll.r>rr.l)
        {
            maxs=max(maxs,ll.maxr+rr.nl);
            if(ll.maxr==ll.e)
                maxl=ll.maxr+rr.nl;
            if(rr.nl==rr.e)
                maxr=ll.maxr+rr.nl;
        }
        if(rr.l>ll.r)
        {
            maxs=max(maxs,rr.maxl+ll.nr);
            if(rr.maxl==rr.e)
                maxr=rr.maxl+ll.nr;
            if(ll.nr==ll.e)
                maxl=rr.maxl+ll.nr;
        }
        //////////////////////////
        if(ll.nl==ll.e && ll.r>rr.l)
            nl=ll.nl+rr.nl;
        if(rr.nr==rr.e && rr.l>ll.r)
            nr=rr.nr+ll.nr;
    }
};

int n;
long long a[N];

ban t[N*4];

void shi(int pos)
{
    if(t[pos].laz==0)
        return;
    t[pos].l+=t[pos].laz;
    t[pos].r+=t[pos].laz;
    if(t[pos].e>1)
    {
        t[pos*2].laz+=t[pos].laz;
        t[pos*2+1].laz+=t[pos].laz;
    }
    t[pos].laz=0;
}

ban crt(ban u)
{
    u.l+=u.laz;
    u.r+=u.laz;
    return u;
}

void bil(int tl,int tr,int pos)
{
    if(tl==tr)
    {
        t[pos].nor(a[tl]);
        return;
    }
    int m=(tl+tr)/2;
    bil(tl,m,pos*2);
    bil(m+1,tr,pos*2+1);
    t[pos].mer(crt(t[pos*2]),crt(t[pos*2+1]));
}

void ubd(int tl,int tr,int l,int r,long long g,int pos)
{
    if(tl==l && tr==r)
    {
        t[pos].laz+=g;
        return;
    }
    shi(pos);
    int m=(tl+tr)/2;
    if(r<=m)
        ubd(tl,m,l,r,g,pos*2);
    else if(l>m)
        ubd(m+1,tr,l,r,g,pos*2+1);
    else
    {
        ubd(tl,m,l,m,g,pos*2);
        ubd(m+1,tr,m+1,r,g,pos*2+1);
    }
    t[pos].mer(crt(t[pos*2]),crt(t[pos*2+1]));
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    bil(1,n,1);
    int q;
    cin>>q;
    while(q--)
    {
        int l,r,g;
        cin>>l>>r>>g;
        ubd(1,n,l,r,g,1);
        cout<<t[1].maxs<<endl;
    }
    return 0;
}