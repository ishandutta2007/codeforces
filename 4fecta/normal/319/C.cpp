#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 100005;

int n; ll a[MN], b[MN], dp[MN];
int deq[MN];
int l=0,r=-1;
ll calc(int x, int i){
    return dp[x]+a[i]*b[x];
}
int ip(int x, int y){
    int lo=x,hi=n;
    while(lo!=hi){
        int mid=(lo+hi)/2;
        if(calc(x,mid)<=calc(y,mid))hi=mid;
        else lo=mid+1;
    }
    if(calc(x,lo)>calc(y,lo))return n+1;
    return lo;
}
int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    memset(dp, 0x3f, sizeof(dp));
    dp[1] = 0;
    deq[++r]=1;
    for (int i = 2; i <= n; i++) {
        while(r-l>=1&&calc(deq[l+1],i)<=calc(deq[l],i))l++;
        dp[i]=calc(deq[l],i);
        while(r-l>=1&&ip(i,deq[r])<=ip(deq[r],deq[r-1]))r--;
        deq[++r]=i;
    }
    printf("%lld\n", dp[n]);
    return 0;
}