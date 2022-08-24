#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long w[101000], Mn[101000], Mx[101000];
void Solve(){
    int i, j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&w[i]);
    }
    for(int T=0;;T++){
        for(i=1;i<=n;i++){
            Mn[i]=w[i];
            Mx[i]=w[i]+(1ll<<T)-1;
        }
        long long Cur = Mn[1];
        int ck=0;
        for(i=2;i<=n;i++){
            if(Cur > Mx[i]){
                ck=1;
                break;
            }
            Cur = max(Cur, Mn[i]);
        }
        if(!ck){
            printf("%d\n",T);
            return;
        }
    }
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}