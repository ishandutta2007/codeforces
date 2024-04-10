#include <bits/stdc++.h>
#define maxn 400400
#define pii pair<int,int>
#define pb push_back
#define inf 1e9
#define mod 998244353
typedef long long ll;
using namespace std;

struct edge {
    int a,b,w;
    edge (int a=0,int b=0,int w=0): a(a), b(b), w(w) {}
    bool operator<(edge comp)const{
        return w < comp.w;
    }
}

E[maxn];

int pai[maxn];
int qtd[maxn];
int spec[maxn];

int find(int x){
    return pai[x] = (x == pai[x]) ? x : find(pai[x]);
}

int merge(int a,int b){
    a = find(a);
    b = find(b);
    pai[a] = b;
    qtd[b] += qtd[a];
}

int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++){
        int u;
        scanf("%d",&u);
        spec[u-1] = 1;
    }
    for(int i=0;i<m;i++){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w), a--, b--;
        E[i] = edge(a,b,w);
    }
    sort(E,E+m);
    for(int i=0;i<n;i++)
        pai[i] = i, qtd[i] = spec[i];
    for(int i=0;i<m;i++){
        int a = E[i].a, b = E[i].b, w = E[i].w;
        a = find(a);
        b = find(b);
        if(a == b) continue;
        merge(a,b);
        if(qtd[b] == k){
            for(int j=0;j<k;j++) printf("%d ",w);
            return 0;
        }
    }
}