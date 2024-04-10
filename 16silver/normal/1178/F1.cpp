#include <cstdio>
int c[500];
int inv[500];
long long dp1[500][500], dp2[500][500];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&c[i]);
        c[i]--;
        inv[c[i]]=i;
    }
    for(int i=0;i<n;i++){
        dp1[i][i]=1;
        dp2[i][i]=2;
    }
    for(int d=1;d<n;d++){
        for(int i=0;i<n-d;i++){
            int minval=9999, minidx=-1;
            for(int j=i;j<=i+d;j++){
                if(c[j]<minval){
                    minval = c[j];
                    minidx = j;
                }
            }
            long long p=1LL, q=1LL;
            if(i<minidx) p=dp2[i][minidx-1];
            if(minidx<i+d) q=dp2[minidx+1][i+d];
            dp1[i][i+d] = (p*q)%998244353LL;
            for(int j=i;j<i+d;j++){
                dp2[i][i+d]=(dp2[i][i+d]+dp1[i][j]*dp1[j+1][i+d])%998244353LL;
            }
            dp2[i][i+d] = (dp2[i][i+d]+dp1[i][i+d]*2LL)%998244353LL;
        }
    }
    printf("%lld\n",dp1[0][n-1]);
}