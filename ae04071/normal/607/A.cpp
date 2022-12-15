#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii = pair<int,int>;

pii arr[100001];
int n,dp[100001];

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&arr[i].fi,&arr[i].se);
    sort(arr+1,arr+n+1);

    int ans=0;
    for(int i=1;i<=n;i++) {
        int idx = lower_bound(arr+1,arr+n+1,pii(arr[i].first-arr[i].second,0))-arr-1;
        dp[i] = dp[idx]+1;
        ans = max(ans,dp[i]);
    }
    printf("%d\n",n-ans);

    return 0;
}