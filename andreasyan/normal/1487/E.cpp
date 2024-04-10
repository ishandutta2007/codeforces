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
const int N = 200005, INF = 500000008;

int n[5];
int a[5][N];

int dp[5][N];

vector<int> v[N];

void solv()
{
    for (int i = 1; i <= 4; ++i)
        scanf("%d", &n[i]);
    for (int i = 1; i <= 4; ++i)
    {
        for (int j = 1; j <= n[i]; ++j)
            scanf("%d", &a[i][j]);
    }

    for (int i = 1; i <= 4; ++i)
        for (int j = 1; j <= n[i]; ++j)
            dp[i][j] = -INF;
    for (int j = 1; j <= n[1]; ++j)
        dp[1][j] = a[1][j];

    for (int i = 2; i <= 4; ++i)
    {
        for (int j = 1; j <= n[i]; ++j)
            v[j].clear();
        int qq;
        scanf("%d", &qq);
        while (qq--)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            v[y].push_back(x);
        }

        multiset<int> s;
        for (int j = 1; j <= n[i - 1]; ++j)
            s.insert(dp[i - 1][j]);
        for (int j = 1; j <= n[i]; ++j)
        {
            for (int k = 0; k < v[j].size(); ++k)
                s.erase(s.find(dp[i - 1][v[j][k]]));
            if (s.empty())
                dp[i][j] = INF;
            else
                dp[i][j] = a[i][j] + *s.begin();
            for (int k = 0; k < v[j].size(); ++k)
                s.insert(dp[i - 1][v[j][k]]);
        }
    }

    int ans = INF;
    for (int j = 1; j <= n[4]; ++j)
        ans = min(ans, dp[4][j]);

    if (ans == INF)
        printf("-1\n");
    else
        printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}