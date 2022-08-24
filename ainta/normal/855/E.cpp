#include<cstdio>
#include<algorithm>
using namespace std;
long long D[12][12][120], INF = 2e18;
int w[100], C[12];
long long Calc(int b, long long n){
    int i, j, k, cnt = 0;
    long long res = 0;
    while(n){
        w[cnt++] = n%b;
        n/=b;
    }
    int s = 0;
    for(i=0;i<cnt-1;i++){
        res += (b-1) * D[b][1][i];
      //  printf("%d %d %lld\n",b,i,D[b][1][i]);
    }
    //printf("%lld\n",res);
    for(i=cnt-1;i>=0;i--){
        for(j=0;j<w[i];j++){
            if(i==cnt-1 && j==0)continue;
            s ^= (1<<j);
            int t = __builtin_popcount(s);
            //printf("%d %d %d %lld\n",b,t,i,D[b][t][i]);
            res += D[b][t][i];
            s ^= (1<<j);
        }
        s ^= (1<<w[i]);
    }
    return res;
}
int main(){
    int i, j, k, l, Q;
    long long ll, rr;
    for(i=2;i<=10;i++){
        D[i][0][0] = 1;
        for(k=1;k<=100;k++){
            for(j=0;j<=i;j++){
                long long s = 0;
                for(l=0;l<i;l++){
                    if(l <j) s += D[i][j-1][k-1];
                    else s += D[i][j+1][k-1];
                    s = min(s, INF);
                }
                D[i][j][k] = s;
            //    printf("%d %d %d %lld\n",i,j,k,D[i][j][k]);
            }
        }
    }
    scanf("%d",&Q);
    while(Q--){
        scanf("%d%lld%lld",&i,&ll,&rr);
        printf("%lld\n",Calc(i,rr+1) - Calc(i, ll));
    }
}