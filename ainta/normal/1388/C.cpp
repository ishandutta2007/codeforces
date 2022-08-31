#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, chk;
int w[101000];
long long U[101000], S[101000];
vector<int>E[101000];
void DFS(int a, int pp){
    long long s=0;
    S[a]=w[a];
    for(auto &x : E[a]){
        if(x==pp)continue;
        DFS(x,a);
        s+=U[x];
        S[a]+=S[x];
    }
    if(U[a]<s-w[a] || U[a] <-S[a] || U[a] > S[a] || abs(U[a])%2 != S[a]%2){
        chk=1;
    }
}
void Solve(){
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        E[i].clear();
        S[i]=0;
    }
    for(i=1;i<=n;i++)scanf("%d",&w[i]);
    for(i=1;i<=n;i++)scanf("%lld",&U[i]);
    for(i=1;i<n;i++){
        int a, b;
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    chk=0;
    DFS(1,0);
    if(chk)puts("NO");
    else puts("YES");
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}