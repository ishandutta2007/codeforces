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
int n,m,a[50],w[50];
lli dp[51][51][51];

int oi,pp,nn,w_sum,pw_sum,nw_sum;;

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

lli DP(int rem,int pc,int nc){
    lli &ret=dp[rem][pc][nc];
    if(ret!=-1) return ret;

    int c=m-(rem+pc+nc);
    c*=a[oi];
    ret=0;
    if(rem==0) return ret = w[oi]+c;
    
    int cur_w=w[oi]+c;
    int s=w_sum + cur_w + pc - nc;
    if(a[oi]==1 || cur_w>0) {
        ret = (ret + DP(rem-1,pc,nc) * cur_w%MOD*inv(s)%MOD)%MOD;
    }
    if(nw_sum - nc > 0) {
        ret = (ret + DP(rem-1,pc,nc+1)*(nw_sum-nc)%MOD*inv(s)%MOD)%MOD;
    }
    ret = (ret + DP(rem-1,pc+1,nc)*(pw_sum+pc)%MOD*inv(s)%MOD)%MOD;
    return ret;
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    for(int i=0;i<n;i++) scanf("%d",w+i);
    for(int i=0;i<n;i++) if(a[i]==0) a[i]=-1;
    
    for(int i=0;i<n;i++) {
        memset(dp,-1,sizeof(dp));
        oi = i;
        pw_sum = nw_sum = w_sum = 0;
        for(int j=0;j<n;j++) if(j!=i) {
            if(a[j]==1) pw_sum += w[j];
            else nw_sum += w[j];
            w_sum += w[j];
        }
        printf("%lld\n",DP(m,0,0));
    }
    
    return 0;
}