#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define N_ 110
#define M_ 2010
#define INF 99999

class MaxFlow{
public:
    struct Edge{
        int b, e, f, num;
    }E[M_ * 2];
    vector<int>G[N_];
    int Level[N_], Q[N_], PV[N_], source, sink, n, flow, EC, Cut[M_];
    void init(int N, int S, int T){
        n = N, flow = EC = 0;
        source = S, sink = T;
    }
    void Add_Edge(int a, int b, int f, int num){
        G[a].push_back(EC);
        G[b].push_back(EC+1);
        E[EC++] = {a,b,f,num};
        E[EC++] = {b,a,0,num};
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
            while(t = BlockFlow(source, INF)) flow += t;
        }
    }
    void MinCut(){
        int i, j;
        GetLevel();
        for(i=0;i<EC;i+=2){
            if(Level[E[i].b] != -1 && Level[E[i].e] == -1) Cut[E[i].num] = 1;
        }
    }
    
}G1;

class MaxCostCirculation{
public:
    struct Edge{
        int b, e, f, c, num;
    }E[M_ * 2];
    vector<int>G[N_];
    int n, EC, D[N_], start, Path[N_];
    bool v[N_], Instack[N_];
    
    void init(int N){
        n = N, EC = 0;
    }
    void Add_Edge(int a, int b, int f, int c, int num){
        G[a].push_back(EC);
        G[b].push_back(EC+1);
        E[EC++] = {a,b,f,c,num};
        E[EC++] = {b,a,0,-c,num};
    }
    bool dfsSPFA(int a){
        Instack[a] = true;
        int i;
        for(i=0;i<G[a].size();i++){
            Edge t = E[G[a][i]];
            if(t.f && D[t.e] < D[t.b] + t.c){
                D[t.e] = D[t.b] + t.c;
                Path[t.e] = G[a][i];
                if(Instack[t.e]){
                    start = t.e;
                    return true;
                }
                else if(dfsSPFA(t.e)){
                    return true;
                }
            }
        }
        Instack[a] = false;
        return false;
    }

    bool CycleCancel(){
        int i, a;
        for(i=1;i<=n;i++){
            Instack[i]=0;
            D[i]=0;
            v[i]=0;
        }
        for(i=1;i<=n;i++){
            if(dfsSPFA(i))break;
        }
        if(i==n+1)return false;
        a = start;
        while(!v[a]){
            v[a] = true;
            a = E[Path[a]].b;
        }
        int b = a, f = INF;
        while(1){
            f = min(f, E[Path[a]].f);
            a = E[Path[a]].b;
            if(a==b)break;
        }
        while(1){
            E[Path[a]].f -= f;
            E[Path[a]^1].f += f;
            a = E[Path[a]].b;
            if(a==b)break;
        }
        return true;
    }
    void MCC(){
        while(CycleCancel());
    }
}G2;
int F[M_];

int main(){
    int n, m, i, a, b, c, st, ed;
    scanf("%d%d%d%d",&n,&m,&st,&ed);
    G1.init(n,st,ed);
    G2.init(n);
    G2.Add_Edge(ed, st, INF, 0, -1);
    for(i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&c);
        if(!c) G1.Add_Edge(a, b, INF, i);
        else{
            G1.Add_Edge(a, b, 1, i);
            G1.Add_Edge(b, a, INF, i);
            G2.Add_Edge(a, b, 1, 1, i);
            G2.Add_Edge(a, b, INF, 0, i);
        }
    }
    G1.Dinic();
    G1.MinCut();
    printf("%d\n",G1.flow);
    G2.MCC();
    for(i=3;i<G2.EC;i+=2){
        if(G2.E[i].f){
            F[G2.E[i].num] += G2.E[i].f;
        }
    }
    for(i=0;i<m;i++){
        printf("%d %d\n",F[i], F[i] + !G1.Cut[i]);
    }
}