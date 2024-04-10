#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 201000
using namespace std;
int C[N_], n, Dep[N_];
vector<int>E[N_];
void DFS(int a, int pp) {
    C[a]=1;
    for(auto &x : E[a]){
        if(x==pp)continue;
        Dep[x]=Dep[a]+1;
        DFS(x,a);
        C[a]+=C[x];
    }
}
int main(){
    int i, K;
    scanf("%d%d",&n,&K);
    for(i=1;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    DFS(1,0);
    vector<int>V;
    for(i=1;i<=n;i++){
        V.push_back(Dep[i]+1-C[i]);
    }
    sort(V.begin(),V.end());
    long long res=0;
    for(i=0;i<K;i++)res+=V[n-1-i];
    printf("%lld\n",res);
}