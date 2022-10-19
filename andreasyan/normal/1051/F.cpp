#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=100005;
struct ban1
{
    int x,y;
    long long d;
    ban(){}
    ban(int x,int y,long long d)
    {
        this->x=x;
        this->y=y;
        this->d=d;
    }
};

struct ban
{
    int x;
    long long d;
    ban(){}
    ban(int x,long long d)
    {
        this->x=x;
        this->d=d;
    }
};
bool operator<(const ban& a,const ban& b)
{
    return a.d>b.d;
}

int n,m,l;
ban1 b[N];

vector<ban> a[N];

int pe[N][30];
int tim;
int tin[N],tout[N];

long long h[N];
void dfs(int x,int pp)
{
    tin[x]=tim++;
    pe[x][0]=pp;
    for(int i=1;i<=l;++i)
        pe[x][i]=pe[pe[x][i-1]][i-1];
    for(int i=0;i<a[x].size();++i)
    {
        ban y=a[x][i];
        if(y.x==pp)
            continue;
        h[y.x]=h[x]+y.d;
        dfs(y.x,x);
    }
    tout[x]=tim++;
}

bool per(int x,int y)
{
    return (tin[x]<=tin[y] && tout[x]>=tout[y]);
}

int lca(int x,int y)
{
    if(per(x,y))
        return x;
    if(per(y,x))
        return y;
    for(int i=l;i>=0;--i)
        if(!per(pe[x][i],y))
            x=pe[x][i];
    return pe[x][0];
}

long long d[N];
bool c[N];
void djk(int x)
{
    for(int i=1;i<=n;++i)
    {
        d[i]=0;
        c[i]=false;
    }
    priority_queue<ban> q;
    q.push(ban(x,0));
    while(1)
    {
        ban t;
        do
        {
            if(q.empty())
                return;
            t=q.top();
            q.pop();
        }while(c[t.x]);
        c[t.x]=true;
        d[t.x]=t.d;
        for(int i=0;i<a[t.x].size();++i)
        {
            ban h=a[t.x][i];
            h.d+=t.d;
            if(!c[h.x])
                q.push(h);
        }
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

vector<int> v;
long long dd[45][N];
void pre()
{
    for(int i=1;i<=n;++i)
        p[i]=i;
    for(int i=0;i<m;++i)
    {
        if(fi(b[i].x)==fi(b[i].y))
        {
            v.push_back(b[i].x);
            v.push_back(b[i].y);
            continue;
        }
        kpc(b[i].x,b[i].y);
        a[b[i].y].push_back(ban(b[i].x,b[i].d));
        a[b[i].x].push_back(ban(b[i].y,b[i].d));
    }
    dfs(1,1);
    for(int i=1;i<=n;++i)
        a[i].clear();
    for(int i=0;i<m;++i)
    {
        a[b[i].y].push_back(ban(b[i].x,b[i].d));
        a[b[i].x].push_back(ban(b[i].y,b[i].d));
    }
    for(int i=0;i<v.size();++i)
    {
        int x=v[i];
        djk(x);
        for(int j=1;j<=n;++j)
            dd[i][j]=d[j];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    while((1<<l)<n)
        ++l;
    for(int i=0;i<m;++i)
    {
        cin>>b[i].x>>b[i].y>>b[i].d;
    }
    pre();
    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        long long ans=h[x]+h[y]-2*h[lca(x,y)];
        for(int i=0;i<v.size();++i)
            ans=min(ans,dd[i][x]+dd[i][y]);
        cout<<ans<<endl;
    }
    return 0;
}