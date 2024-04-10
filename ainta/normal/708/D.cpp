#include<stdio.h>
#include<algorithm>
#include<vector>
#define INF 99999999
using namespace std;
struct Edge{
    int e, f, c;
}E[10100];
int EC, n, m, Q[101000], InQ[110], D[110], Path[110];
int source, sink;
int head, tail;
vector<int>G[110];
void Add_Edge(int b, int e, int f, int c){
    G[b].push_back(EC);
    G[e].push_back(EC+1);
    E[EC].e = e, E[EC].f = f, E[EC].c = c; EC++;
    E[EC].e = b, E[EC].f = 0, E[EC].c = -c; EC++;
}
void Ins(int a, int d, int p){
    if(D[a]<=d)return;
    D[a]=d, Path[a] = p;
    if(!InQ[a]){
        InQ[a]=1;
        Q[++tail] = a;
    }
}
int SPFA(){
    int i, x, t;
    for(i=0;i<=sink;i++)D[i] = INF;
    head = tail = 0;
    Ins(source,0,-1);
    while(head < tail){
        x = Q[++head];
        InQ[x] = 0;
        for(i=0;i<G[x].size();i++){
            t = G[x][i];
            if(E[t].f) Ins(E[t].e, D[x] + E[t].c, t);
        }
    }
    if(D[sink] == INF)return -1;
    return D[sink];
}
int MCMF(){
    int i, f, res = 0;
    while((f = SPFA()) >= 0){
        int M = INF, t, x;
        x = sink;
        while(x != source){
            t = Path[x];
            M = min(M, E[t].f);
            x = E[t^1].e;
        }
        res += f * M;
        x = sink;
        while(x != source){
            t = Path[x];
            E[t].f -= M;
            E[t^1].f += M;
            x = E[t^1].e;
        }
    }
    return res;
}
int main(){
    int i, a, b, f1, f2, res = 0;
    scanf("%d%d",&n,&m);
    source = 0, sink = n+1;
    for(i=0;i<m;i++){
        scanf("%d%d%d%d",&a,&b,&f1,&f2);
        if(f2 <= f1){
            Add_Edge(b, a, f2, 1);
            Add_Edge(a, b, f1 - f2, 1);
        }
        else{
            res += f2 - f1;
            Add_Edge(b, a, f2 - f1, 0);
            Add_Edge(b, a, f1, 1);
        }
        Add_Edge(a, b, INF, 2);
        Add_Edge(source, b, f2, 0);
        Add_Edge(a, sink, f2, 0);
    }
    Add_Edge(n, 1, INF, 0);
    res += MCMF();
    printf("%d\n",res);
}