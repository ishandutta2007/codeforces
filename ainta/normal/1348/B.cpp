#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, K, w[110];
void Solve(){
    int i, j, k;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    vector<int>V;
    for(i=1;i<=n;i++){
        int ck=0;
        for(j=1;j<=n;j++)if(w[j]==i)ck=1;
        if(!ck)continue;
        V.push_back(i);
    }
    if(V.size()>K){
        puts("-1");
        return;
    }
    while(V.size()<K)V.push_back(V[0]);
    int sz = V.size();
    printf("%d\n",n*sz);
    for(i=1;i<=n;i++){
        for(auto &x : V)printf("%d ",x);
    }
    puts("");
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}