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
const int N = 80;
const int INF = 1000000009;
struct ban
{
    int i;
    int a, b;
};
bool operator<(const ban& t1, const ban& t2)
{
    return t1.b < t2.b;
}

int n, k;
ban t[N];

int dp[N][N];
int p[N][N];

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        t[i].i = i;
        scanf("%d%d", &t[i].a, &t[i].b);
    }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dp[i][j] = -INF;
    sort(t + 1, t + n + 1);
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            if (j < k)
            {
                if (dp[i][j] + t[i + 1].a + t[i + 1].b * j > dp[i + 1][j + 1])
                {
                    dp[i + 1][j + 1] = dp[i][j] + t[i + 1].a + t[i + 1].b * j;
                    p[i + 1][j + 1] = 1;
                }
            }
            if (dp[i][j] + t[i + 1].b * (k - 1) > dp[i + 1][j])
            {
                dp[i + 1][j] = dp[i][j] + t[i + 1].b * (k - 1);
                p[i + 1][j] = 0;
            }
        }
    }
    //printf("%d\n", dp[n][k]);
    vector<int> ans1, ans0;
    int j = k;
    for (int i = n; i >= 1; --i)
    {
        if (p[i][j] == 1)
        {
            ans1.push_back(t[i].i);
            --j;
        }
        else
        {
            ans0.push_back(t[i].i);
        }
    }
    reverse(all(ans1));
    printf("%d\n", sz(ans1) + sz(ans0) * 2);
    for (int i = 0; i < sz(ans1) - 1; ++i)
        printf("%d ", ans1[i]);
    for (int i = 0; i < sz(ans0); ++i)
        printf("%d %d ", ans0[i], -ans0[i]);
    printf("%d\n", ans1.back());
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}