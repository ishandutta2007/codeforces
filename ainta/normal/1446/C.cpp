#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, cc = 1;
struct Trie{
    int Ch[2], cnt;
}T[8100000];
int D[8100000];
void Put(int nd, int a, int pv){
    T[nd].cnt++;
    if(pv==-1){
        return;
    }
    int t = ((a>>pv)&1);
    if(!T[nd].Ch[t]){
        T[nd].Ch[t]=++cc;
    }
    Put(T[nd].Ch[t], a, pv-1);
}
void DFS(int a){
    int i;
    int c1 = T[a].Ch[0], c2 = T[a].Ch[1];
    D[a] = 1;
    if(T[c1].cnt && T[c2].cnt){
        DFS(c1);
        DFS(c2);
        D[a] = max(D[c1],D[c2]) + 1;
        return;
    }
    else if(T[c1].cnt){
        DFS(c1);
        D[a]=max(D[a],D[c1]);
    }
    else if(T[c2].cnt){
        DFS(c2);
        D[a]=max(D[a],D[c2]);
    }
}
void Solve(){
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        Put(1, a, 29);
    }
    DFS(1);
    printf("%d\n",n-D[1]);
}
int main(){
    int TC = 1;
    while(TC--){
        Solve();
    }
}