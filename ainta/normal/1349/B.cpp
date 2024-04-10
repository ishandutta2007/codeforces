#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int n, w[101000], K;
void Solve(){
    int i, ck=0;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        if(w[i]==K)ck=1;
    }
    if(!ck){
        puts("no");
        return;
    }
    if(n==1){
        puts("yes");
        return;
    }
    for(i=1;i<n;i++){
        if(w[i]>=K&&w[i+1]>=K){
            puts("yes");
            return;
        }
    }
    for(i=1;i<n-1;i++){
        if(w[i]>=K&&w[i+2]>=K){
            puts("yes");
            return;
        }
    }
    puts("no");
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}