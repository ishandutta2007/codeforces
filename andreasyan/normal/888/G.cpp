#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=200005;

int n;
int a[N];

int z;
int t[N*33][2];
int q[N*33];
int s[N*33];

void ave(int i,int pos,int x)
{
    int vi=0;
    if((a[x]&(1<<i)))
        vi=1;
    ++q[pos];
    if(i==-1)
    {
        s[pos]=(x);
        return;
    }
    if(!t[pos][vi])
        t[pos][vi]=++z;
    ave(i-1,t[pos][vi],x);
}

void han(int i,int pos,int x)
{
    int vi=0;
    if((a[x]&(1<<i)))
        vi=1;
    --q[pos];
    if(i==-1)
    {
        return;
    }
    han(i-1,t[pos][vi],x);
}

int qry(int i,int pos,int x)
{
    int vi=0;
    if((a[x]&(1<<i)))
        vi=1;
    if(i==-1)
    {
        return s[pos];
    }
    if(vi==0)
    {
        if(t[pos][0] && q[t[pos][0]])
            return qry(i-1,t[pos][0],x);
        else
            return qry(i-1,t[pos][1],x);
    }
    else
    {
        if(t[pos][1] && q[t[pos][1]])
            return qry(i-1,t[pos][1],x);
        else
            return qry(i-1,t[pos][0],x);
    }
}

int p[N];
int fi(int x)
{
    if(x==p[x])
        return x;
    return p[x]=fi(p[x]);
}

void kpc(int x,int y)
{
    x=fi(x);
    y=fi(y);
    p[x]=y;
}

vector<int> h[N];
vector<pair<int,int> > vv;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
    }
    vector<int> v;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)
    {
        if(i==1 || a[i]!=a[i-1])
            v.push_back(a[i]);
    }
    n=v.size();
    for(int i=1;i<=n;++i)
        a[i]=v[i-1];
    for(int i=1;i<=n;++i)
        p[i]=i;
    for(int i=1;i<=n;++i)
    {
        ave(29,0,i);
    }
    //////////////////////////////
    long long ans=0;
    int m=0;
    while(1)
    {
        if(m==n-1)
            break;
        for(int x=1;x<=n;++x)
            h[fi(x)].push_back(x);
        vv.clear();
        for(int i=1;i<=n;++i)
        {
            if(h[i].empty())
                continue;
            for(int j=0;j<h[i].size();++j)
            {
                int x=h[i][j];
                han(29,0,x);
            }
            int minu=(1<<30),xx,yy;
            for(int j=0;j<h[i].size();++j)
            {
                int x=h[i][j];
                int y=qry(29,0,x);
                if((a[x]^a[y])<minu || ((a[x]^a[y])==minu && y<yy))
                {
                    minu=(a[x]^a[y]);
                    xx=x;
                    yy=y;
                }
            }
            vv.push_back(m_p(xx,yy));
            for(int j=0;j<h[i].size();++j)
            {
                int x=h[i][j];
                ave(29,0,x);
            }
        }
        for(int x=1;x<=n;++x)
            h[fi(x)].pop_back();
        for(int i=0;i<vv.size();++i)
        {
            int x=vv[i].first;
            int y=vv[i].second;
            if(fi(x)!=fi(y))
            {
                ans+=(a[x]^a[y]);
                kpc(x,y);
                ++m;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}