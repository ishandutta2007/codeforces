#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int Num[501000], par[501000][20], n, Ed[501000], cnt, ReNum[501000], Dep[501000];
long long Res[501000];
vector<int>E[501000], G[501000];
void DFS(int a, int dep){
    int i;
    Num[a] = ++cnt;
    Dep[a] = dep;
    ReNum[cnt] = a;
    G[dep].push_back(a);
    for(i=0;i<19;i++)par[a][i+1]=par[par[a][i]][i];
    for(i=0;i<E[a].size();i++){
        par[E[a][i]][0] = a;
        DFS(E[a][i], dep + 1);
    }
    Ed[a] = cnt;
}
int LCA(int a, int b){
    if(Dep[a] < Dep[b])return LCA(b,a);
    int d = Dep[a]-Dep[b], i = 0;
    while(d){
        if(d&1)a = par[a][i];
        i++,d>>=1;
    }
    for(i=18;i>=0;i--)if(par[a][i]!=par[b][i])a=par[a][i],b=par[b][i];
    if(a!=b)a = par[a][0];
    return a;
}
int m, pv;
vector<int>TP;
int S[1010000];
void DFS2(int a){
    int x = ReNum[TP[a]], ck = 0;
    S[x] = 0;
    while(pv < m){
        if(TP[pv] <= Ed[x]){
            int y = ReNum[TP[pv]];
            DFS2(pv++);
            S[x] += S[y];
            ck = 1;
        }
        else break;
    }
    if(!ck) S[x]++;
}
void DFS3(int a, long long s){
    int x = ReNum[TP[a]], ck = 0;
    while(pv < m){
        if(TP[pv] <= Ed[x]){
            int y =ReNum[TP[pv]];
            DFS3(pv++, s + S[y] * (Dep[y] - Dep[x]));
            ck = 1;
        }
        else break;
    }
    if(!ck){
        Res[x] = s - 1;
    }
}
void Do(vector<int> &T){
    int i, sz = T.size();
    TP.resize(sz);
    for(i=0;i<sz;i++)TP[i] = Num[T[i]];
    sort(TP.begin(),TP.end());
    for(i=0;i<sz-1;i++){
        int t = Num[LCA(ReNum[TP[i]],ReNum[TP[i+1]])];
        TP.push_back(t);
    }
    TP.push_back(1);
    sort(TP.begin(),TP.end());
    m = unique(TP.begin(),TP.end()) - TP.begin();
    pv = 1;
    DFS2(0);
    pv = 1;
    DFS3(0, S[ReNum[1]]);
}
int main(){
    int i, rt, a, j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        if(!a)rt = i;
        else E[a].push_back(i);
    }
    DFS(rt, 0);
    for(i=0;i<n;i++){
        if(G[i].empty())break;
        Do(G[i]);
        for(j=0;j<G[i].size();j++){
            Res[G[i][j]] += Res[par[G[i][j]][0]];
        }
    }
    for(i=1;i<=n;i++)printf("%lld ",Res[i]);
}