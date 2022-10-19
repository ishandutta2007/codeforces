#include <iostream>
#include <vector>

#define M 100100
#define INF 1000000000
#define pb push_back

using namespace std;

long n,m,k,s,t,p[M],r[M],q[M],d[M];
vector<long> g[M],v(M);
vector<bool> b(M,0),u(M,0);

void init(void){
    for (long i=1; i<=n; ++i){
        p[i]=i;
        r[i]=0;
        d[i]=INF;
        u[i]=0;
        q[i]=0;
    }
}

long get(long x){
    if (p[x]==x)
    return x;
    else
    return p[x]=get(p[x]);
}

void uni(long a, long b){
    a=get(a);
    b=get(b);
    if (r[a]<r[b])
    swap(a,b);
    p[b]=a;
    r[a]++;
}

void bfs(long x, long h){
    long qb=0,qe=0,l,to;
    q[0]=x;
    u[x]=1;
    d[x]=0;
    while (qb<=qe){
        to=q[qb++];
        l=d[to];
        if (l<h)
        for(long i=0; i<g[to].size(); ++i)
        if (!u[g[to][i]]){
            q[++qe]=g[to][i];
            u[g[to][i]]=1;
            d[g[to][i]]=l+1;
            if (b[g[to][i]])
            uni(x,g[to][i]);
        }
    }
    for(long i=0; i<=qe+1; ++i){
        u[q[i]]=0;
        //d[q[i]]=0;
        q[i]=0;
    }
}


void read(void){
    cin>>n>>m>>k;
    for (long i=0; i<k; ++i){
        cin>>v[i];
        b[v[i]]=1;
    }
    for (long i=0,a,b; i<m; ++i){
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    cin>>s>>t;
    --k;
    if (!b[t]){
        v[++k]=t;
        b[t]=1;
    }
}

long way(void){
    long qb=0,qe=0,l,to;
    q[0]=s;
    u[s]=1;
    d[s]=0;
    while (qb<=qe){
        to=q[qb++];
        l=d[to];
        for(long i=0; i<g[to].size(); ++i)
        if (!u[g[to][i]]){
            q[++qe]=g[to][i];
            u[g[to][i]]=1;
            d[g[to][i]]=l+1;
        }
    }
    return d[t];
}
bool che(long h){
    init();
    for (long i=0; i<=k; ++i){
        bfs(v[i],h);
        if (get(s)==get(t))
        return 1;
    }
    return get(s)==get(t);
}

int main()
{
    read();
    init();
    long l=0,r=way(),m;
    if (r==INF){
        cout<<-1;
        return 0;
    }
    while (l<r){
        m=(l+r)/2;
        if (che(m))
        r=m;
        else
        l=m+1;
    }
    cout<<l;
    return 0;
}