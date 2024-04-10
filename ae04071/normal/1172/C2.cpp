#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;
using pdd = pair<double,double>;

const lli MOD=998244353;

int n,m,a[200001];
lli w[200001],dp[3001][3001];
lli ps,ns;
vector<int> pv,nv;

lli power(lli a, lli p) {
    lli ret=1;
    while(p) {
        if(p&1) ret = ret*a%MOD;
        a=a*a%MOD;
        p>>=1;
    }
    return ret;
}
lli inv(lli a) {
    return power(a,MOD-2);
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    for(int i=0;i<n;i++) scanf("%lld",w+i);
    for(int i=0;i<n;i++) {
        if(a[i]==0) nv.push_back(w[i]),ns+=w[i];
        else pv.push_back(w[i]),ps+=w[i];
    }

    lli val[10000];
    for(int i=-m;i<=m;i++) val[i+m] = inv(ps + ns + i);
    
    dp[0][0]=1;
    for(int i=1;i<=m;i++) {
        for(int j=0;j<=min(1ll*i,ns);j++) {
            int pc=i-j,nc=j;
            if(pc) dp[pc][nc] = (dp[pc][nc] + dp[pc-1][nc] * (ps+pc-1)%MOD * inv(ps+ns+pc-1-nc)%MOD)%MOD;
            if(nc) dp[pc][nc] = (dp[pc][nc] + dp[pc][nc-1] * (ns-(nc-1))%MOD * inv(ps+ns+pc-nc+1)%MOD)%MOD;
        }
    }

    lli pinv=inv(ps),ninv=inv(ns),pv=0,nv=0;
    for(int i=0;i<=m;i++) pv = (pv + dp[i][m-i] * (ps+i) % MOD)%MOD;
    for(int i=0;i<=min(1ll*m,ns);i++) nv = (nv + dp[m-i][i] * (ns-i) % MOD)%MOD;
    pv = (pv * pinv)%MOD;
    nv = (nv * ninv)%MOD;
    for(int i=0;i<n;i++) {
        lli ans=0;
        if(a[i]==1) {
            ans = pv * w[i] % MOD;
        } else {
            ans = nv * w[i] % MOD;
        }
        printf("%lld\n",ans);
    }

    return 0;
}