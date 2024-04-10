#include <iostream>
#include <vector>
#include <algorithm>

#define M 100100
#define long long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

using namespace std;

pair<long,pair<long, pair<long,long> > > edge[M];
pair<long, long> e[M];
long n,w[M],num[M],p[M],s[M],siz[M],gl[M],ans[M];
vector<long> g[M],vert;
bool u[M];

void read(void){
    cin>>n;
    for (long i=1,a,b,w; i<n; ++i){
        cin>>a>>b>>w;
        edge[i]=mp(w,mp(i,mp(a,b)));
    }
    sort(edge+1,edge+n);
    for (long i=1; i<n; ++i){
        e[i]=edge[i].s.s;
        num[i]=edge[i].s.f;
        w[i]=edge[i].f;
    }
}

void dsu_ini(void){
    for (long i=0; i<=n; ++i){
        p[i]=i;
        s[i]=1;
    }
}

long dsu_get(long x){
    if (p[x]==x)
    return x;
    return p[x]=dsu_get(p[x]);
}

void dsu_uni(long x, long y){
    x=dsu_get(x);
    y=dsu_get(y);
    if (s[x]<s[y])
    swap(x,y);
    p[y]=x;
    s[x]+=s[y];
}

void dfs(long v,long global){
    u[v]=1;
    gl[v]=global;
    siz[v]=s[v];
    for (long i=0; i<g[v].size(); ++i)
    if (!u[g[v][i]]){
        dfs(g[v][i],global);
        siz[v]+=siz[g[v][i]];
    }
}

void work(long l, long r){
    for (long i=l; i<r; ++i){
        long a=dsu_get(e[i].f),b=dsu_get(e[i].s);

        if (!u[a]){
            u[a]=1;
            vert.pb(a);
        }
        if (!u[b]){
            u[b]=1;
            vert.pb(b);
        }
        g[a].pb(b);
        g[b].pb(a);
    }
    for (long i=0; i<vert.size(); ++i)
    u[vert[i]]=0;
    for (long i=0; i<vert.size(); ++i)
    if (!u[vert[i]])
    dfs(vert[i],vert[i]);

    for (long i=0; i<vert.size(); ++i){
        u[vert[i]]=0;
        g[vert[i]].clear();
    }

    for (long i=l; i<r; ++i){
        long a=dsu_get(e[i].f),b=dsu_get(e[i].s);
        long t=min(siz[a],siz[b]);
        ans[i]=t*(siz[gl[a]]-t);
    }

    for (long i=l; i<r; ++i)
    dsu_uni(e[i].f,e[i].s);

    vert.clear();

}

int main()
{
    long m=0;
    read();
    dsu_ini();

    for (long i=1,j; i<n; i=j){
        for (j=i; j<n && w[j]==w[i]; ++j);
        work(i,j);
    }

    for (long i=1; i<n; ++i)
    m=max(ans[i],m);

    for (long i=1; i<n; ++i)
    if (ans[i]==m)
    vert.pb(num[i]);

    cout<<2*m<<" "<<vert.size()<<"\n";
    for (long i=0; i<vert.size(); ++i)
    cout<<vert[i]<<"\n";

    return 0;
}