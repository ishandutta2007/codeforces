#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[201000];
int n, w[201000], Num[201000], ReNum[201000], cnt, par[201000][20], K, Dep[201000];
long long Res;
void DFS(int a, int pp){
    Num[a] = ++cnt;
    ReNum[cnt] = a;
    par[a][0] = pp;
    int i;
    for(i=0;i<E[a].size();i++){
        if(E[a][i] ==pp)continue;
        Dep[E[a][i]] = Dep[a] + 1;
        DFS(E[a][i], a);
    }
}
int LCA(int a, int b){
    if(Dep[a] < Dep[b])return LCA(b,a);
    int d = Dep[a]-Dep[b], i = 0;
    while(d){
        if(d&1)a = par[a][i];
        i++;d>>=1;
    }
    for(i=17;i>=0;i--){
        if(par[a][i]!=par[b][i])a=par[a][i],b=par[b][i];
    }
    if(a!=b)a=par[a][0];
    return a;
}
int main(){
    int i, a, b, j;
    scanf("%d%d",&n,&K);
    for(i=1;i<=2*K;i++){
        scanf("%d",&w[i]);
    }
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    DFS(1,0);
    for(i=1;i<=2*K;i++)w[i] = Num[w[i]];
    sort(w+1,w+2*K+1);
    for(i=1;i<=2*K;i++){
        w[i] = ReNum[w[i]];
    }
    for(i=0;i<17;i++){
        for(j=1;j<=n;j++){
            par[j][i+1] = par[par[j][i]][i];
        }
    }
    for(i=1;i<=K;i++){
        Res += Dep[w[i]] + Dep[w[K+i]] - 2*Dep[LCA(w[i],w[K+i])];
    }
    printf("%lld\n",Res);
}