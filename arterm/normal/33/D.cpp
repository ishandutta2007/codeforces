#include <iostream>
#include <vector>

#define long long long
#define M 1070
#define R 2010101010

using namespace std;

/*ifstream cin ("input.txt");
ofstream cout("output.txt");*/

struct point{
    long x,y;
    void read(void){
        cin>>x>>y;
    }
};

long n,m,k,r[M],time=0, tin[M], tout[M], p[M], ind[M], l[M];
point o[M],c[M];
vector<long> g[M],t[M], ord;
bool u[M];

long dist(point a, point b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

void read(void){
    cin>>n>>m>>k;
    for (long i=1; i<=n ;++i)
    o[i].read();
    for (long i=1; i<=m; ++i){
        cin>>r[i];
        c[i].read();
    }
    c[0].x=0;
    c[0].y=0;
    r[0]=R;
}

bool inp(point a, long b){
    return dist(a,c[b])<r[b]*r[b];
}

bool in(long a, long b){
    return dist(c[a],c[b])<r[b]*r[b] && r[a]<r[b];
}

void make(void){
    for (long i=0; i<=m; ++i)
    for (long j=0; j<=m; ++j)
    if (i!=j && in(j,i))
    g[i].push_back(j);
}

void top(long v){
    u[v]=1;
    for (long i=0; i<g[v].size(); ++i)
    if (!u[g[v][i]])
    top(g[v][i]);
    tout[v]=time++;
    ord.push_back(v);
}

void make_tree(void){
    for (long i=0; i<m; ++i)
    for (long j=i+1; j<=m; ++j)
    if (in(ord[i],ord[j])){
        //cout<<ord[i]<<" in "<<ord[j]<<"\n";
        p[ord[i]]=ord[j];
        //cout<<p[ord[i]]<<"\n";
        t[ord[j]].push_back(ord[i]);
        break;
    }
    p[0]=0;
    l[0]=0;

    for (long i=1; i<=n; ++i)
    for (long j=0; j<=m; ++j)
    if (inp(o[i],j) && tout[ind[i]]>tout[j])
    ind[i]=j;

}

void lay(long v){
    tin[v]=time++;
    for (long i=0; i<t[v].size(); ++i){
        l[t[v][i]]=l[v]+1;
        lay(t[v][i]);
    }
    tout[v]=time++;
}

bool anc (long x, long y){
    return (tin[y]<=tin[x] && tout[x]<=tout[y]);
}

long ans(long x, long y){
    long lca=y;
    while (!anc(x,lca))
    lca=p[lca];
    return l[x]+l[y]-2*l[lca];
}

int main()
{
    read();//
    make();//
    top(0);
    make_tree();
    time=0;
    lay(0);
    /*cout<<"Ord:\n";
    for (long i=0; i<=m; ++i)
    cout<<ord[i]<<" ";
    cout<<"\n";
    for (long i=0; i<=m; ++i){
        cout<<i<<"<-"<<p[i]<<"-----------\n";
        for (long j=0; j<t[i].size(); ++j)
        cout<<t[i][j]<<" ";
        cout<<"\n++++\n";
    }*/
    for (long i=0,a,b; i<k; ++i){
        cin>>a>>b;
        cout<<ans(ind[a],ind[b])<<"\n";
    }
    return 0;
}