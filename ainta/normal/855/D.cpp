#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[101000], L[101000];
int Dep[101000], Dep2[101000], par[101000][20];
void DFS(int a, int pp){
    par[a][0] = pp;
    Dep[a] = Dep[pp] + 1;
    int i;
    for(i=0;i<18;i++)par[a][i+1]=par[par[a][i]][i];
    for(i=0;i<E[a].size();i++){
        if(E[a][i]!=pp){
            Dep2[E[a][i]] = Dep2[a] + L[a][i];
            DFS(E[a][i], a);
        }
    }
}
int LCA(int a, int b){
    if(Dep[a] < Dep[b])return LCA(b,a);
    int d = Dep[a]-Dep[b], i =0;
    while(d){
        if(d&1)a=par[a][i];
        d>>=1;i++;
    }
    for(i=18;i>=0;i--){
        if(par[a][i]!=par[b][i])a=par[a][i],b=par[b][i];
    }
    if(a!=b)a=par[a][0];
    return a;
}
int n;
int main(){
    int i, ck, a, b, Q;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&a,&b);
        if(a!=-1){
            E[a].push_back(i);
            L[a].push_back(b);
        }
    }
    for(i=1;i<=n;i++){
        if(!Dep[i]){
            DFS(i, 0);
        }
    }
    scanf("%d",&Q);
    while(Q--){
        scanf("%d%d%d",&ck,&a,&b);
        int l = LCA(a,b);
        if(l == 0){
            printf("NO\n");
            continue;
        }
        if(ck==1){
            if(l == a && Dep2[a] == Dep2[b] && a!=b){
                printf("YES\n");
            }
            else printf("NO\n");
        }
        else{
            if(Dep2[a] == Dep2[l] && Dep2[b] > Dep2[l] && Dep2[b]-Dep2[l] == Dep[b]-Dep[l]){
                printf("YES\n");
            }
            else printf("NO\n");
        }
    }
}