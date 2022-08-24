#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>

#define N_ 201000
#define pli pair<long long, int>

using namespace std;

int n, m, st, par[N_][18], Dep[N_], Deg[N_];
priority_queue<pli>PQ;
vector<int>E[N_], L[N_], G[N_], rev[N_], Tree[N_];
long long Dist[N_];

void Ins(int node, long long d){
    if(Dist[node] <= d)return;
    Dist[node] = d;
    PQ.push(pli(-d,node));
}

void Dijkstra(int source){
    int i, cur;
    for(i=1;i<=n;i++)Dist[i] = 1e18;
    Ins(source, 0);
    while(!PQ.empty()){
        pli tp = PQ.top();
        PQ.pop();
        if(Dist[tp.second] != -tp.first)continue;
        cur = tp.second;
        for(i=0;i<E[cur].size();i++){
            Ins(E[cur][i], Dist[cur] + L[cur][i]);
        }
    }
}

int Q[N_];

int LCA(int a, int b){
    if(Dep[a] < Dep[b])return LCA(b,a);
    int d = Dep[a]-Dep[b], i = 0;
    while(d){
        if(d&1)a=par[a][i];
        d>>=1;i++;
    }
    for(i=17;i>=0;i--){
        if(par[a][i]!=par[b][i])a=par[a][i],b=par[b][i];
    }
    if(a!=b)a=par[a][0];
    return a;
}

void MakeDom(){
    int i, head = 0, tail = 0, cur;
    Q[++tail] = st;
    while(head < tail){
        cur = Q[++head];
        for(i=0;i<G[cur].size();i++){
            Deg[G[cur][i]]--;
            if(!Deg[G[cur][i]])Q[++tail] = G[cur][i];
        }
        if(cur==st)continue;
        int pp = rev[cur][0];
        for(i=1;i<rev[cur].size();i++){
            pp = LCA(pp, rev[cur][i]);
        }
        Tree[pp].push_back(cur);
        Dep[cur] = Dep[pp] + 1;
        par[cur][0] = pp;
        for(i=0;i<17;i++)par[cur][i+1] = par[par[cur][i]][i];
    }
}

int C[N_], res;

void Get(int cur){
    C[cur] = 1;
    for(int i=0;i<Tree[cur].size();i++){
        Get(Tree[cur][i]);
        C[cur]+=C[Tree[cur][i]];
    }
    if(cur != st)res = max(res, C[cur]);
}

int main(){
    int i, a, b, c;
    scanf("%d%d%d",&n,&m,&st);
    for(i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&c);
        E[a].push_back(b);L[a].push_back(c);
        E[b].push_back(a);L[b].push_back(c);
    }
    Dijkstra(st);
    for(i=1;i<=n;i++){
        for(int j=0;j<E[i].size();j++){
            if(Dist[E[i][j]] == Dist[i] + L[i][j]){
                G[i].push_back(E[i][j]);
                Deg[E[i][j]]++;
                rev[E[i][j]].push_back(i);
            }
        }
    }
    MakeDom();
    Get(st);
    printf("%d\n",res);
}