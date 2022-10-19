#include <bits/stdc++.h>
using namespace std;
const int N=200002;

struct ban
{
    int laz;
    int m,a;
    ban()
    {
        laz=0;
        m=a=0;
    }
};

int n;
vector<int> a[N];
int g[N];

vector<int> dfs_list;

void dfs(int x)
{
    dfs_list.push_back(x);
    for(int i=0;i<a[x].size();++i)
    {
        int h=a[x][i];
        dfs(h);
        dfs_list.push_back(x);
    }
}

ban t[N*8];

void shi(int pos)
{
    if(!t[pos].laz)
        return;
    swap(t[pos].m,t[pos].a);
    t[pos*2].laz^=1;
    t[pos*2+1].laz^=1;
    t[pos].laz=0;
}

ban mer(const ban& l,const ban& r)
{
    ban res;
    res.a=l.a+r.a;
    res.m=l.m+r.m;
    return res;
}

ban crt(ban x)
{
    if(!x.laz)
        return x;
    else
    {
        swap(x.a,x.m);
        return x;
    }
}

void ubd0(int tl,int tr,int x,bool z,int pos)
{
    if(tl==tr)
    {
        if(z)
            t[pos].m++;
        else
            t[pos].a++;
        return;
    }
    int m=(tl+tr)/2;
    if(x<=m)
        ubd0(tl,m,x,z,pos*2);
    else
        ubd0(m+1,tr,x,z,pos*2+1);
    t[pos]=mer(crt(t[pos*2]),crt(t[pos*2+1]));
}

void ubd(int tl,int tr,int l,int r,int pos)
{
    if(tl==l && tr==r)
    {
        t[pos].laz^=1;
        return;
    }
    shi(pos);
    int m=(tl+tr)/2;
    if(r<=m)
        ubd(tl,m,l,r,pos*2);
    else if(l>m)
        ubd(m+1,tr,l,r,pos*2+1);
    else
    {
        ubd(tl,m,l,m,pos*2);
        ubd(m+1,tr,m+1,r,pos*2+1);
    }
    t[pos]=mer(crt(t[pos*2]),crt(t[pos*2+1]));
}

ban qry(int tl,int tr,int l,int r,int pos)
{
    if(tl==l && tr==r)
        return crt(t[pos]);
    shi(pos);
    int m=(tl+tr)/2;
    if(r<=m)
        return qry(tl,m,l,r,pos*2);
    if(l>m)
        return qry(m+1,tr,l,r,pos*2+1);
    return mer(qry(tl,m,l,m,pos*2),qry(m+1,tr,m+1,r,pos*2+1));
}

int first[N],last[N];
void pre()
{
    for(int i=1;i<=n;++i)
        first[i]=-1;
    for(int i=0;i<dfs_list.size();++i)
    {
        int x=dfs_list[i];
        if(first[x]==-1)
            first[x]=i;
        last[x]=i;
    }

    for(int i=1;i<=n;++i)
    {
        ubd0(0,dfs_list.size()-1,first[i],g[i],1);
    }
}

int main()
{
    cin>>n;
    for(int i=2;i<=n;++i)
    {
        int p;
        cin>>p;
        a[p].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;++i)
        cin>>g[i];
    pre();
    int q;
    cin>>q;
    while(q--)
    {
        string x;
        int y;
        cin>>x>>y;
        if(x=="get")
            cout<<qry(0,dfs_list.size()-1,first[y],last[y],1).m<<endl;
        else
            ubd(0,dfs_list.size()-1,first[y],last[y],1);
    }
    return 0;
}