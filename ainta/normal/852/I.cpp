#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#define N_ 101000
using namespace std;
int n, w[N_], F[N_], Dep[N_], par[N_][18], Num[N_], cnt, Ed[N_], m;
vector<int>E[N_];
map<int,int>Map;
void DFS(int a, int pp){
    par[a][0]=pp;
    Num[a] = ++cnt;
    int i;
    for(i=0;i<17;i++)par[a][i+1]=par[par[a][i]][i];
    for(i=0;i<E[a].size();i++){
        if(E[a][i]!=pp){
            Dep[E[a][i]] = Dep[a] + 1;
            DFS(E[a][i], a);
        }
    }
    Ed[a] = cnt;
}
int LCA(int a, int b){
    if(Dep[a] < Dep[b])return LCA(b,a);
    int d = Dep[a]-Dep[b], i = 0;
    while(d){
        if(d&1)a = par[a][i];
        d>>=1;i++;
    }
    for(i=16;i>=0;i--)if(par[a][i]!=par[b][i])a=par[a][i],b=par[b][i];
    if(a!=b)a=par[a][0];
    return a;
}
struct Query{
    int a, b, p, num;
}Q[101000];
int C[101000];
int D[101000][2];
void DFS2(int a, int pp, int num){
    D[a][0] = D[pp][0], D[a][1] = D[pp][1];
    if(F[a] == num){
        D[a][w[a]]++;
    }
    int i;
    for(i=0;i<E[a].size();i++){
        if(E[a][i]!=pp)DFS2(E[a][i], a, num);
    }
}
long long Res[N_];
void Do(int num){
    DFS2(1, 0, num);
    int i;
    for(i=1;i<=m;i++){
        Res[i] += 1ll * (D[Q[i].a][0] + D[Q[i].b][0] - D[Q[i].p][0] - D[par[Q[i].p][0]][0]) * (D[Q[i].a][1] + D[Q[i].b][1] - D[Q[i].p][1] - D[par[Q[i].p][0]][1]);
    }
}
int main(){
    int i, j, a, b;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    int cc = 0;
    for(i=1;i<=n;i++){
        scanf("%d",&F[i]);
        if(!Map.count(F[i])){
            Map[F[i]] = ++cc;
        }
        F[i] = Map[F[i]];
        C[F[i]]++;
    }
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    DFS(1,0);
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        scanf("%d%d",&Q[i].a,&Q[i].b);
        Q[i].num = i,Q[i].p = LCA(Q[i].a,Q[i].b);
    }
    for(i=1;i<=n;i++){
        if(C[i] >= 2){
            Do(i);
        }
    }
    for(i=1;i<=m;i++)printf("%lld\n",Res[i]);
}