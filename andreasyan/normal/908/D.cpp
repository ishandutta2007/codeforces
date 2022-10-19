#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 2003;
const int M = 1000000007;

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int k;
int pa, pb;
int sa, sb;
int rsb;

int dp[N][N];
bool c[N][N];

int rec(int qa, int qe)
{
    if (c[qa][qe])
        return dp[qa][qe];
    c[qa][qe] = true;
    if (qa + qe >= k)
    {
        return dp[qa][qe] = (((rsb - 1 + M) % M + qa) % M + qe) % M;
    }
    return dp[qa][qe] = ((rec(qa + 1, qe) * 1LL * sa) % M + (rec(qa, qe + qa) * 1LL * sb) % M) % M;
}

int main()
{
    scanf("%d%d%d", &k, &pa, &pb);
    sa = (pa * 1LL * ast((pa + pb) % M, M - 2)) % M;
    sb = (pb * 1LL * ast((pa + pb) % M, M - 2)) % M;
    rsb = ast(sb, M - 2);
    printf("%d\n", rec(1, 0));
    return 0;
}