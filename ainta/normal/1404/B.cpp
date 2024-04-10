#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, K, A, B, DA, DB, D[201000];
vector<int>E[201000];
void DFS(int a, int pp, int d){
    D[a]=d;
    for(auto &x : E[a]){
        if(x!=pp)DFS(x,a,d+1);
    }
}
void Solve(){
    int i;
    scanf("%d%d%d%d%d",&n,&A,&B,&DA,&DB);
    for(i=1;i<=n;i++)E[i].clear();
    for(i=1;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    if(DA*2>=DB){
        puts("Alice");
        return;
    }
    DFS(A,0,0);
    if(D[B]<=DA){
        puts("Alice");
        return;
    }
    int Mx=-1,pv=-1;
    for(i=1;i<=n;i++)if(Mx < D[i])Mx=D[i],pv=i;
    DFS(pv,0,0);
    Mx=-1;
    for(i=1;i<=n;i++)Mx=max(Mx,D[i]);
    if(Mx<=DA*2){
        puts("Alice");
        return;
    }
    puts("Bob");
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}