#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;
using lli = long long;

const lli MOD=998244353;

int n,arr[5001],cnt[5001],m;
lli dp[5001][5001],ival[5001];

lli power(lli a,lli p) {
    lli res=1;
    while(p) {
        if(p&1) res=res*a%MOD;
        a=a*a%MOD;
        p>>=1;
    }
    return res;
}
lli inv(lli a) {return power(a,MOD-2);}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",arr+i);
    for(int i=1;i<=n;i++) ival[i]=inv(i);
    m=n;
    
    sort(arr+1,arr+n+1);
    
    int c=0;
    for(int i=1;i<=n;i++) {
        if(i==1 || arr[i]!=arr[i-1]) {
            arr[++c] = arr[i]; 
            cnt[c]=1;
        } else {
            cnt[c]++;
        }
    }
    n=c;

    for(int j=0;j<=m-cnt[n]+1;j++) {
        dp[n][j] = (cnt[n]-1) * ival[m-j] % MOD;
        dp[n][j] = dp[n][j]*cnt[n]%MOD;
    }

    int s=cnt[n];
    for(int i=n-1;i;i--) {
        s+=cnt[i];
        for(int j=0;j<=m-s+1;j++) {
            dp[i][j] = (cnt[i]-1) * ival[m-j] % MOD;
            dp[i][j] = (dp[i][j] + dp[i+1][j+1]*ival[m-j]%MOD) % MOD;
            dp[i][j] = dp[i][j] * cnt[i] % MOD;
            dp[i][j] = (dp[i][j]+dp[i+1][j])%MOD;
        }
    }
    printf("%lld\n",dp[1][1]*ival[m]%MOD);

    return 0;
}