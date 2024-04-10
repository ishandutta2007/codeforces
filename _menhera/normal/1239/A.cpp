#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
long long dp[101010];
long long ipow(long long a, int b)
{
    if(b==0) return 1;
    long long ret = ipow(a,b/2);
    ret = ret*ret%MOD;
    if(b%2==1) ret=ret*a%MOD;
    return ret;
}
int main()
{
    int N, M; scanf("%d%d", &N, &M);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<101010; ++i)
    {
        dp[i] = (dp[i-1]+dp[i-2])%MOD;
    }
    int ansm = 2*(dp[N] + dp[M]-1)%MOD;
    cout << ansm << endl;
}