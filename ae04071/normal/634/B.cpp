#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int s[60],v[60],n;
lli dp[60][2][2][2];

lli DP(int idx,int t,int af,int bf) {
    lli &ret=dp[idx][t][af][bf];
    if(ret!=-1) return ret;

    if(idx==n) return ret=((t==0) && af && bf);
    ret=0;
    for(int i=0;i<2;i++)for(int j=0;j<2;j++) if((i^j)==v[idx] && (i+j+t)%2==s[idx]) {
        int ns = (t+i+j)>=2;
        ret += DP(idx+1,ns,af|i,bf|j);
    }
    return ret;
}
int main() {
    lli a,b;
    scanf("%lld %lld",&a,&b);
    while(a || b) {
        s[n]=a%2; v[n]=b%2;
        n++;
        a>>=1;b>>=1;
    }

    memset(dp,-1,sizeof(dp));
    printf("%lld\n",DP(0,0,0,0));

    return 0;
}