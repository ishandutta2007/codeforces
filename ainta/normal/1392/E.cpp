#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n;
long long w[30][30];
int main(){
    int i, j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            long long t = 1ll<<(i+j);
            w[i][j] = t * (i&1);
            printf("%lld ", w[i][j]);
        }
        puts("");
        fflush(stdout);
    }
    int Q;
    scanf("%d",&Q);
    while(Q--){
        long long K;
        scanf("%lld",&K);
        int sx = 0, sy = 0;
        printf("%d %d\n",sx+1,sy+1);
        fflush(stdout);
        for(i=1;i<=n-1+n-1;i++){
            int tp = (K>>i)&1;
            int ck = sx&1;
            if(tp==ck){
                sy++;
            }
            else sx++;
            printf("%d %d\n",sx+1,sy+1);
            fflush(stdout);
        }
    }
}