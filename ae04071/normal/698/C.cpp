#include <bits/stdc++.h>
using namespace std;

int n,k;
double p[20],ans[20],dp[1<<20];

int main() {
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%lf",p+i);

    int cnt=0;
    for(int i=0;i<n;i++) if(p[i]!=0.0) cnt++;
    if(cnt <= k) {
        for(int i=0;i<n;i++) {
            if(p[i]==0) printf("0 ");
            else printf("1 ");
        }
        return 0;
    }

    dp[0] = 1;
    for(int s=0;s<1<<n;s++) {
        double sum=0;
        cnt=0;
        for(int i=0;i<n;i++) if(s>>i&1) sum+=p[i], cnt++;
        if(cnt < k) {
            for(int i=0;i<n;i++) if(!(s>>i&1)) {
                ans[i] += dp[s] * p[i] / (1 - sum);
                dp[s|1<<i] += dp[s] * p[i] / (1-sum);
            }
        }
    }
    for(int i=0;i<n;i++) printf("%.10lf ",ans[i]);
    
    return 0;
}