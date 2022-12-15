#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

#define V_ 100005
#define E_ 100005
#define INF 2147483600
struct S{
    int n, v; S(){ n=0; v=INF; }
    S(int n,int v): n(n), v(v) {}
    bool operator< (const S&t) const{ return v<t.v; }
}; 
typedef vector<S> vS;
typedef vS::iterator vSi;
typedef vector<int> vi;
typedef vi::iterator vii;

int V, E;
vector<vS> G;
vector<vi> X, C;

int mintime(int i,int t){
    if(X[i].empty()) return t;
    vii it = lower_bound(X[i].begin(),X[i].end(),t);
    if(it == X[i].end() || *it != t) return t;
    return C[i][it-X[i].begin()];
}

S Tree[V_*3]; int TS;
bool Chk[V_+1];

void update(int x, int dat){
    x += TS; Tree[x].v = dat;
    while(x>>=1) Tree[x] = min(Tree[x*2], Tree[x*2+1]);
}

int main(){
    int i, j;

    scanf("%d%d",&V,&E); G.resize(V+1);
    while(E--){
        int u, v, c; scanf("%d%d%d",&u,&v,&c);
        G[u].push_back(S(v,c));
        G[v].push_back(S(u,c));
    }

    X.resize(V+1); C.resize(V+1);
    for(i=1; i<=V; i++){
        int sz; scanf("%d",&sz);
        C[i].resize(sz);
        for(j=0; j<sz; j++){
            int t; scanf("%d",&t);
            X[i].push_back(t);
        }
        if(sz > 0){
            C[i][sz-1] = X[i][sz-1] + 1;
            for(j=sz-2; j>=0; j--){
                if(X[i][j]+1 != X[i][j+1]) C[i][j] = X[i][j] + 1;
                else C[i][j] = C[i][j+1];
            }
        }
    }

    for(TS=1; TS<V; TS<<=1); --TS;
    for(i=1; i<=V; i++) Tree[i+TS].n = i;
    for(i=TS; i>0; i--) Tree[i].n = Tree[i*2].n;

    update(1, 0);
    while(Tree[1].v != INF){
        S m = Tree[1]; update(m.n, INF); Chk[m.n] = true;
        int at = mintime(m.n, m.v);
        if(m.n == V){ printf("%d\n",m.v); return 0; }
        for(vSi g = G[m.n].begin(); g != G[m.n].end(); g++){
            if(Chk[g->n]) continue;
            if(Tree[g->n+TS].v > at+g->v) update(g->n, at+g->v);
        }
    }

    puts("-1");
    return 0;
}