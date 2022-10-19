#include <iostream>
#include <vector>

#define M 100100
#define N 20
#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

long n,k,p[M],a[M][N],in[M],out[M],ti=0;
vector<long> g[M],t[M], beg(M,0),end(M,0), be(M,0), en(M,0);
vector<bool> u(M,0);
vector<pair<long,long> > e(M);

void maketree(long v){
    ti++;
    in[v]=ti;
    u[v]=1;
    for (long i=0; i<g[v].size(); ++i)
    if (!u[g[v][i]]){
        p[g[v][i]]=v;
        t[v].pb(g[v][i]);
        maketree(g[v][i]);
    }
    ti++;
    out[v]=ti;
}

void binanc(void){
    for (long i=1; i<=n; ++i)
    a[i][0]=p[i];
    for (long j=1; j<20; ++j)
    for (long i=1; i<=n; ++i)
    a[i][j]=a[a[i][j-1]][j-1];
}

bool anc(long x, long y){
    if (in[y]<in[x])
    return 0;
    if (in[x]<=in[y])
    if (out[y]<=out[x])
    return 1;
    return 0;
}

long lca(long x, long y){
    long h,j;
    if (in[y]<in[x])
    swap(x,y);
    h=x;
    while (!anc(h,y)){
            j=0;
            while (!anc(a[h][j],y))
            j++;
            if (j>0)
            h=a[h][j-1];
            else
            h=a[h][0];
        }
    return h;
}

void letsgo(long x, long y){
    end[lca(x,y)]+=2;
    beg[x]++;
    beg[y]++;
}

void summ(long v){
    be[v]+=beg[v];
    en[v]+=end[v];
    for (long i=0; i<t[v].size(); ++i){
        summ(t[v][i]);
        en[v]+=en[t[v][i]];
        be[v]+=be[t[v][i]];
     }
}

void read(void){
    long x,y;
    cin>>n;
    for (long i=1; i<n; ++i){
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
        e[i]=mp(x,y);
    }
    p[1]=1;
    maketree(1);
    binanc();
    cin>>k;
    for (long i=0; i<k; ++i){
        cin>>x>>y;
        letsgo(x,y);
    }
    summ(1);
    for (long i=1; i<n; ++i)
    if (p[e[i].f]==e[i].s)
    cout<<be[e[i].f]-en[e[i].f]<<" ";
    else
    cout<<be[e[i].s]-en[e[i].s]<<" ";
}


int main()
{
    read();
    return 0;
}