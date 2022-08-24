#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 101000
using namespace std;
int n, par[N_], C[N_], w[N_];
long long res;
vector<int>T, E[N_];

void DFS1(int a, int pp){
    C[a]=1;
    for(auto &x : E[a]){
        if(x==pp)continue;
        DFS1(x,a);
        C[a]+=C[x];
    }
    res=res+min(C[a],n-C[a])*2;
}
void DFS2(int a, int pp){
    T.push_back(a);
    for(auto &x : E[a]){
        if(x==pp)continue;
        DFS2(x,a);
    }
}
int get_mid(int a, int pp, int c){
    for(auto &x : E[a]){
        if(x==pp)continue;
        if(C[x]>c)return get_mid(x,a,c);
    }
    return a;
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        int a, b;
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    DFS1(1, 0);
    int m = get_mid(1, 0, C[1]/2);
    DFS2(m, 0);
    for(i=0;i<n;i++){
        w[T[i]]=T[(i+n/2)%n];
    }
    printf("%lld\n",res);
    for(i=1;i<=n;i++)printf("%d ",w[i]);
}