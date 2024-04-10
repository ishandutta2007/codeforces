#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

const lli INF = 1e16;

int n,c,p[10001],s[10001];
lli dp[2][10001];
int main() {
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++) scanf("%d",p+i);
    for(int i=1;i<=n;i++) scanf("%d",s+i);

    for(int i=0;i<=n;i++) dp[0][i] = dp[1][i] = INF;
    dp[0][0] = 0;

    int cur=1,pr=0;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=i;j++) {
            if(!j) dp[cur][j] = dp[pr][j] + p[i] + 1ll*j*c;
            else dp[cur][j] = min(dp[pr][j] + p[i] + 1ll*j*c, dp[pr][j-1] + s[i]);
        }
        swap(cur,pr);
    }
    
    printf("%lld\n",*min_element(dp[pr], dp[pr]+n+1));

    return 0;
}