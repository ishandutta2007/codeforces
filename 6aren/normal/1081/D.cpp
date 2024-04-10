#include <bits/stdc++.h>
using namespace std;

const int N=100000+5;

typedef struct edge{
    int u; int v; int w;
};

int n, k, m, p[N], check[N], val[N], value, x[N];
edge e[N];

bool cmp(edge x, edge y){
    return x.w<y.w;
}

int get(int u){
    return ((u==p[u]) ? u : (p[u]=get(p[u])));
}

void unite(int u, int v){
    u=get(u);
    v=get(v);
    if (u!=v){

        if ((check[u]==1) && (check[v]==1)) val[v]=value;
        else if (check[u]==1){
            check[v]=1;
            val[v]=val[u];
        }
        p[u]=v;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(); cout.tie();
    cin >> n >> m >> k;
    for (int i=0; i<N; i++){
        check[i]=0;
        val[i]=0;
    }
    for (int i=1; i<=k; i++){
        cin >> x[i];
        check[x[i]]=1;
    }
    for (int i=1; i<=m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        e[i].u=a;
        e[i].v=b;
        e[i].w=c;
    }
    sort(e+1, e+1+m, cmp);
    for (int i=1; i<=n; i++){
        p[i]=i;
    }
    for (int i=1; i<=m; i++){
        value=e[i].w;
        unite(e[i].u, e[i].v);
    }
    for (int i=1; i<=k; i++){
        int t=get(x[i]);
        cout << val[t] << " ";
    }
}