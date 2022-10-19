#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1000006;

bool dp[N];
void pre()
{
    dp[0] = true;
    for (int i = 1; i < N; ++i)
    {
        if (i - 2020 >= 0 && dp[i - 2020])
            dp[i] = true;
        if (i - 2021 >= 0 && dp[i - 2021])
            dp[i] = true;
    }
}

void solv()
{
    int n;
    scanf("%d", &n);
    if (dp[n])
        printf("YES\n");
    else
        printf("NO\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
    //ios_base::sync_with_stdio(false), cin.tie(0);

    pre();

    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}