#include <bits/stdc++.h>
using namespace std;
#define int long long
#define m_p make_pair
const int N=100005;
struct ban
{
    int i;
    int x,y;
    int d;
};
bool operator<(const ban& a,const ban& b)
{
    return a.d<b.d;
}

int ans[N];

int n;
ban a[N];

int p[N],q[N];
void pre()
{
    for(int i=1;i<=n;++i)
    {
        p[i]=i;
        q[i]=1;
    }
}

int fi(int x)
{
    if(p[x]==x)
        return x;
    return p[x]=fi(p[x]);
}

void kpc(int x,int y)
{
    x=fi(x);
    y=fi(y);
    if(q[x]<q[y])
    {
        p[x]=y;
        q[y]+=q[x];
    }
    else
    {
        p[y]=x;
        q[x]+=q[y];
    }
}

int qq[N];

vector<bool> c;
vector<int> eq;

void dfs(const vector<vector<pair<int,int> > >& g,int x,int pp)
{
    c[x]=true;
    eq[x]=qq[x];
    for(int i=0;i<g[x].size();++i)
    {
        int h=g[x][i].first;
        if(h==pp)continue;
        dfs(g,h,x);
        eq[x]+=eq[h];
    }
}

void dfs1(const vector<vector<pair<int,int> > >& g,int x,int pp,int mq,int pi)
{
    c[x]=true;
    if(pi!=-1)
        ans[pi]=eq[x]*mq;
    for(int i=0;i<g[x].size();++i)
    {
        int h=g[x][i].first;
        int j=g[x][i].second;
        if(h==pp)continue;
        dfs1(g,h,x,mq+eq[x]-eq[h],j);
    }
}

void stg(const vector<ban>& v)
{
    int z=0;
    map<int,int> m;
    for(int i=0;i<v.size();++i)
    {
        ban t=v[i];
        if(m.find(fi(t.x))==m.end())
        {
            z++;
            m[fi(t.x)]=z;
            qq[z]=q[fi(t.x)];
        }
        if(m.find(fi(t.y))==m.end())
        {
            z++;
            m[fi(t.y)]=z;
            qq[z]=q[fi(t.y)];
        }
    }
    vector<vector<pair<int,int> > > g(z+2);
    for(int i=0;i<v.size();++i)
    {
        ban t=v[i];
        g[m[fi(t.x)]].push_back(m_p(m[fi(t.y)],t.i));
        g[m[fi(t.y)]].push_back(m_p(m[fi(t.x)],t.i));
    }
    eq.assign(z+2,0);
    c.assign(z+2,0);
    for(int i=1;i<=z;++i)
        if(!c[i])
            dfs(g,i,-1);
    c.assign(z+2,0);
    for(int i=1;i<=z;++i)
        if(!c[i])
            dfs1(g,i,-1,0,-1);
    for(int i=0;i<v.size();++i)
    {
        ban t=v[i];
        kpc(t.x,t.y);
    }
}

int32_t main()
{
    cin>>n;
    for(int i=0;i<n-1;++i)
    {
        cin>>a[i].x>>a[i].y>>a[i].d;
        a[i].i=i;
    }
    sort(a,a+n-1);
    pre();
    vector<ban> v;
    v.push_back(a[0]);
    for(int i=1;i<n-1;++i)
    {
        if(a[i-1].i==2)
            cout<<"";
        if(a[i].d!=a[i-1].d)
        {
            stg(v);
            v.clear();
            v.push_back(a[i]);
        }
        else
            v.push_back(a[i]);
    }
    stg(v);
    int maxu=0;
    for(int i=0;i<n-1;++i)
        maxu=max(maxu,ans[i]);
    vector<int> ansv;
    for(int i=0;i<n-1;++i)
        if(ans[i]==maxu)
            ansv.push_back(i);
    cout<<maxu*2<<' '<<ansv.size()<<endl;
    for(int i=0;i<ansv.size();++i)
        cout<<ansv[i]+1<<' ';
    cout<<endl;
    return 0;
}