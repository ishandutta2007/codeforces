#include<bits/stdc++.h>
using namespace std;
long long MOD = (long long)1e18+9;
vector<int> popv[10101];
vector<int> pushv[10101];
bool pos[10101];
long long dp[10101];
int N, Q;
void push(int x)
{
    for(int i=N; i>=x; --i)
    {
        dp[i] += dp[i-x];
        if(dp[i] >= MOD) dp[i] -= MOD;
    }
}
void pop(int x)
{
    for(int i=x; i<=N; ++i)
    {
        dp[i] -= dp[i-x];
        if(dp[i] < 0) dp[i] += MOD;
        if(dp[i] >= MOD) dp[i] -= MOD;
    }
}
int main()
{
    scanf("%d%d", &N, &Q);
    for(int i=0; i<Q; ++i)
    {
        int L, R, X;
        scanf("%d%d%d", &L, &R, &X);
        pushv[L].push_back(X);
        popv[R].push_back(X);
    }
    dp[0] = 1;
    for(int i=1; i<=N; ++i)
    {
        for(auto x: pushv[i]) push(x);
        for(int i=1; i<=N; ++i)
            if(dp[i]) pos[i] = true;
        for(auto x: popv[i]) pop(x);
    }
    int cnt = 0;
    for(int i=1; i<=N; ++i)
        if(pos[i]) ++cnt;
        
    printf("%d\n", cnt);
    for(int i=1; i<=N; ++i)
        if(pos[i])
            printf("%d ", i);
    puts("");
    return 0;
}