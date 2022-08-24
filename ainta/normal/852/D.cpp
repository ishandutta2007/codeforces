#include<cstdio>
#include<algorithm>
#include<vector>
#define M_ 501000
#define N_ 2000
#define INF 9999999
using namespace std;
class MaxFlow{
public:
    struct Edge{
        int b, e, f;
    }E[M_ * 2];
    vector<int>G[N_];
    int Level[N_], Q[N_], PV[N_], source, sink, n, flow, EC;
    void init(int N, int S, int T){
        n = N, flow = EC = 0;
        source = S, sink = T;
    }
    void Add_Edge(int a, int b, int f){
        G[a].push_back(EC);
        G[b].push_back(EC+1);
        E[EC++] = {a,b,f};
        E[EC++] = {b,a,0};
    }
    bool GetLevel(){
        int i;
        for(i=1;i<=n;i++)Level[i] = -1;
        int head = 0, tail = 0;
        Q[++tail] = source, Level[source] = 0;
        while(head < tail){
            int x = Q[++head];
            for(auto &y : G[x]){
                if(E[y].f && Level[E[y].e] == -1){
                    Q[++tail] = E[y].e;
                    Level[E[y].e] = Level[x] + 1;
                }
            }
        }
        return Level[sink] != -1;
    }
    int BlockFlow(int a, int f){
        if(a==sink)return f;
        for(int &i = PV[a];i>=0;i--){
            int x = G[a][i];
            if(E[x].f && Level[E[x].e] == Level[a] + 1){
                int t = BlockFlow(E[x].e, min(f, E[x].f));
                if(t){
                    E[x].f -= t;
                    E[x^1].f += t;
                    return t;
                }
            }
        }
        return 0;
    }
    void Dinic(){
        int t;
        while(GetLevel()){
            for(int i=1;i<=n;i++)PV[i] = G[i].size() - 1;
            while(t = BlockFlow(source, INF))flow += t;
        }
    }
}G;
int n, m, K, T;
int w[N_], D[N_][N_], CK[N_];
bool Pos(int mid){
    G.init(n+n+2, n+n+1, n+n+2);
    int i, j;
    for(i=1;i<=n;i++)CK[i]=0;
    for(i=1;i<=K;i++){
        CK[w[i]]++;
    }
    for(i=1;i<=n;i++)if(CK[i]) G.Add_Edge(G.source, i, CK[i]);
    for(i=1;i<=n;i++){
        G.Add_Edge(n+i, G.sink, 1);
        if(!CK[i])continue;
        for(j=1;j<=n;j++){
            if(D[i][j] <= mid){
                G.Add_Edge(i, n+j, 1);
            }
        }
    }
    G.Dinic();
    for(i=1;i<=G.n;i++)G.G[i].clear();
    return G.flow >= T;
}
int main(){
    int i, j, a, b, c, k;
    scanf("%d%d%d%d",&n,&m,&K,&T);
    for(i=1;i<=K;i++){
        scanf("%d",&w[i]);
    }
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(i!=j)D[i][j]=1e9;
    for(i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&c);
        D[a][b]=min(D[a][b],c);
        D[b][a]=D[a][b];
    }
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)for(k=1;k<=n;k++)D[j][k]=min(D[j][k],D[j][i]+D[i][k]);
    int be = 0, ed = 1e8, res = -1, mid;
    while(be <= ed){
        mid = (be+ed)>>1;
        if(Pos(mid)){
            res = mid;
            ed = mid - 1;
        }
        else be = mid + 1;
    }
    printf("%d\n",res);
}