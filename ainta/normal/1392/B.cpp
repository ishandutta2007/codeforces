#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n;
long long K, w[201000], D[2][201000];
void Solve(){
    int i;
    scanf("%d%lld",&n,&K);
    long long Mx=-1e18;
    for(i=1;i<=n;i++){
        scanf("%lld",&w[i]);
        Mx=max(Mx,w[i]);
    }
    for(i=1;i<=n;i++)w[i]=Mx-w[i];
    long long Mx2 = -1e18;
    for(i=1;i<=n;i++){
        D[1][i]=w[i];
        Mx2=max(Mx2,w[i]);
    }
    for(i=1;i<=n;i++){
        w[i]=Mx2-w[i];
        D[0][i]=w[i];
    }
    for(i=1;i<=n;i++){
        printf("%lld ", D[K%2][i]);
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