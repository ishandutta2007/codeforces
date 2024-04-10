#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n;
long long K, w[201000], D[2][201000];
void Solve(){
    int i;
    scanf("%d",&n);
    long long s=0;
    for(i=1;i<=n;i++){
        scanf("%lld",&w[i]);
        if(i>1 && w[i-1]>w[i]){
            s+=w[i-1]-w[i];
        }
    }
    printf("%lld\n",s);
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}