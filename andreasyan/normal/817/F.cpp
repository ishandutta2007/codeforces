#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000000000000000000;
struct ban
{
    int sum;
    int laz;
    ban *l,*r;
    ban()
    {
        sum=laz=0;
        l=r=0;
    }
};

ban* t;

int kpc(int x,int y)
{
    if(x==0)
        return y;
    if(y==0)
        return x;
    if(x==1 && y==1)
    {
        return 1;
    }
    if(x==1 && y==2)
    {
        return 2;
    }
    if(x==1 && y==3)
    {
        return 2;
    }
    if(x==2 && y==1)
    {
        return 1;
    }
    if(x==2 && y==2)
    {
        return 2;
    }
    if(x==2 && y==3)
    {
        return 1;
    }
    if(x==3 && y==1)
    {
        return 1;
    }
    if(x==3 && y==2)
    {
        return 2;
    }
    if(x==3 && y==3)
    {
        return 0;
    }
}

void ave(ban* pos)
{
    if(!pos->l)
        pos->l=new ban;
    if(!pos->r)
        pos->r=new ban;
}

void shi(int l,int r,ban* pos)
{
    if(pos->laz==0)
        return;
    int m=(l+r)/2;
    if(pos->laz==1)
    {
        pos->l->sum=(m-l+1);
        pos->r->sum=(r-m);
    }
    if(pos->laz==2)
    {
        pos->l->sum=0;
        pos->r->sum=0;
    }
    if(pos->laz==3)
    {
        pos->l->sum=(m-l+1)-pos->l->sum;
        pos->r->sum=(r-m)-pos->r->sum;
    }
    pos->l->laz=kpc(pos->l->laz,pos->laz);
    pos->r->laz=kpc(pos->r->laz,pos->laz);
    pos->laz=0;
}

void ubd(int tl,int tr,int l,int r,int x,ban* pos)
{
    if(tl==l && tr==r)
    {
        if(x==1)
            pos->sum=(r-l+1);
        if(x==2)
            pos->sum=0;
        if(x==3)
            pos->sum=(r-l+1)-pos->sum;
        pos->laz=kpc(pos->laz,x);
        return;
    }
    ave(pos);
    shi(tl,tr,pos);
    int m=(tl+tr)/2;
    if(r<=m)
        ubd(tl,m,l,r,x,pos->l);
    else if(l>m)
        ubd(m+1,tr,l,r,x,pos->r);
    else
    {
        ubd(tl,m,l,m,x,pos->l);
        ubd(m+1,tr,m+1,r,x,pos->r);
    }
    pos->sum=pos->l->sum+pos->r->sum;
}

int qry(int tl,int tr,ban* pos)
{
    if(tl==tr)
        return tl;
    ave(pos);
    shi(tl,tr,pos);
    int m=(tl+tr)/2;
    if(pos->l->sum!=(m-tl+1))
        return qry(tl,m,pos->l);
    else
        return qry(m+1,tr,pos->r);
}

int bb[1000000];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    vector<int> x(q),l(q),r(q),v;
    for(int i=0;i<q;++i)
    {
        cin>>x[i]>>l[i]>>r[i];
        if(l[i]-1>=1)
            v.push_back(l[i]-1);
        v.push_back(l[i]);
        if(l[i]+1<=N)
            v.push_back(l[i]+1);
        if(r[i]-1>=1)
            v.push_back(r[i]-1);
        v.push_back(r[i]);
        if(r[i]+1<=N)
            v.push_back(r[i]+1);
    }
    v.push_back(1);
    v.push_back(N);
    v.push_back(N+1);
    sort(v.begin(),v.end());
    map<int,int> b;
    int z=0;
    for(int i=0;i<v.size();++i)
    {
        if(!i || v[i]!=v[i-1])
        {
            b[v[i]]=++z;
            bb[z]=v[i];
        }
    }
    b[v.back()]=++z;
    bb[z]=v.back();
    t=new ban;
    for(int i=0;i<q;++i)
    {
        ubd(1,N,b[l[i]],b[r[i]],x[i],t);
        cout<<bb[qry(1,N,t)]<<endl;
    }
    return 0;
}