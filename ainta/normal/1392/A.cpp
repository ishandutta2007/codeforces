#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, w[201000];
void Solve(){
    int i, ck =0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        if(i>1 && w[i]!=w[i-1])ck=1;
    }
    if(ck)puts("1");
    else printf("%d\n",n);
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}