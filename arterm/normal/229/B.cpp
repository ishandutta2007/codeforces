#include <iostream>
#include <vector>
#include <set>

#define M 100100
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define long long long
#define INF 10000000000LL

using namespace std;

long n,m,k[M],p[M];
vector<pair<long, long > > g[M];
vector<long> t[M],l[M];
set<pair<long,long> > s;

void read(void){
    cin>>n>>m;
    for (long i=0,a,b,w; i<m; ++i){
        cin>>a>>b>>w;
        g[a].pb(mp(b,w));
        g[b].pb(mp(a,w));
    }
    for (long i=1; i<=n; ++i){
        cin>>k[i];
        p[i]=INF;
        if (k[i]>0){
        t[i].resize(k[i]+1);
        l[i].resize(k[i]+1);
        for (long j=0; j<k[i]; ++j)
        cin>>t[i][j];
        l[i][k[i]-1]=t[i][k[i]-1]+1;
        for (long j=k[i]-2; j>=0; --j)
        if (t[i][j+1]==t[i][j]+1)
        l[i][j]=l[i][j+1];
        else
        l[i][j]=t[i][j]+1;
        }

    }
}

long dir(long v, long h){
    if (k[v]==0)
    return h;
    if (h>t[v][k[v]-1])
    return h;
    long le=0,re=k[v]-1,m;
    while (le<re){
        m=(le+re)/2;
        if (t[v][m]>=h)
        re=m;
        else
        le=m+1;
    }
    if (t[v][le]==h)
    return l[v][le];
    return h;
}

void dij(void){
    p[1]=0;
    s.insert(mp(p[1],1));
    long f,to,w,d,t;
    while (!s.empty()){
        f=s.begin()->s;
        t=dir(f,p[f]);
        s.erase(s.begin());
        for (long i=0; i<g[f].size(); ++i){
            to=g[f][i].f;
            w=g[f][i].s;
            d=w+t;
            if (p[to]>d){
                s.erase(mp(p[to],to));
                p[to]=d;
                s.insert(mp(p[to],to));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    read();
    dij();
    if (p[n]>=INF)
    cout<<-1;
    else
    cout<<p[n];
    return 0;
}