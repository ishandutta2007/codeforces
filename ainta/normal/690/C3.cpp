#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[201000];
int n, cnt, res, Dep[201000], par[201000][18];
int Num[201000], Ed[201000];
void DFS(int a){
    int i;
    Num[a] = ++cnt;
    for(i=0;i<E[a].size();i++){
        Dep[E[a][i]] = Dep[a] + 1;
        par[E[a][i]][0] = a;
        DFS(E[a][i]);
    }
    Ed[a] = cnt;
}
int LCA(int a, int b){
    if(Dep[a]<Dep[b])return LCA(b,a);
    int d = Dep[a]-Dep[b], i = 0;
    while(d){
        if(d&1)a = par[a][i];
        d>>=1;i++;
    }
    for(i=17;i>=0;i--){
        if(par[a][i]!=par[b][i])a=par[a][i],b=par[b][i];
    }
    if(a!=b)a=par[a][0];
    return a;
}
int Dist(int a, int b){
    int L = LCA(a,b);
    return Dep[a]+Dep[b]-Dep[L]*2;
}
int main(){
    int i, a, b, j;
    scanf("%d",&n);
    for(i=2;i<=n;i++){
        scanf("%d",&a);
        E[a].push_back(i);
    }
    DFS(1);
    res = 1;
    for(i=0;i<17;i++){
        for(j=1;j<=n;j++){
            par[j][i+1] = par[par[j][i]][i];
        }
    }
    for(i=2;i<=n;i++){
        if(i==2){
            printf("%d ",res);
            a = 1, b = 2;
            continue;
        }
        int d1, d2;
        d1 = Dist(a,i);
        d2 = Dist(b,i);
        if(d1>res && d1 >= d2){
            res = d1;
            b = i;
        }
        else if(d2 >res){
            res = d2;
            a = i;
        }
        printf("%d ",res);
    }
}