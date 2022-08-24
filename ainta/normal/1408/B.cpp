#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[1100];
void Solve(){
    int i, K, c = 0;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        if(i!=1 && w[i]!=w[i-1])c++;
    }
    if(K==1){
        if(c)puts("-1");
        else printf("%d\n",1);
        return;
    }
    K--;
    printf("%d\n",max(1,(c+K-1)/K));
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}