#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
long long ipow(long long a, long long b)
{
    if(b==0) return 1;
    long long ans = ipow(a, b/2);
    ans *= ans;
    ans %= mod;
    if(b&1) ans *= a;
    ans %= mod;
    return ans;
}


long long k, pa, pb, pappbinv, pappbdpb;
//number of a's, number of ab's
long long dp[1010][1010];
long long solve(int a, int b)
{
    if(dp[a][b] != -1) return dp[a][b];
    if(b+a >= k)
    {
        return dp[a][b] = b + a + pappbdpb - 1;
    }
    long long appenda = solve(a+1, b)*(pa*pappbinv%mod)%mod;
    long long appendb = solve(a, b+a)*(pb*pappbinv%mod)%mod;
    return dp[a][b] = (appenda+appendb)%mod;
} 
int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%lld%lld%lld", &k, &pa, &pb);
    pappbinv = ipow(pa+pb, mod-2);
    
    pappbdpb = (pa+pb)*ipow(pb, mod-2)%mod;
    
    printf("%lld\n", solve(1, 0));
}