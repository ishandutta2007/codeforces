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
const int N = 102;

int n, m, k;
int a[N][N];

void solv()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            scanf("%d", &a[i][j]);
    }
    if (n <= k)
    {
        int ans = N * N;
        for (int x = 0; x < (1 << n); ++x)
        {
            int yans = 0;
            for (int j = 0; j < m; ++j)
            {
                int ans1 = 0, ans2 = 0;
                for (int i = 0; i < n; ++i)
                {
                    int u = 0;
                    if ((x & (1 << i)))
                        u = 1;
                    if (a[i][j] != u)
                        ++ans1;
                    else
                        ++ans2;
                }
                yans += min(ans1, ans2);
            }
            ans = min(ans, yans);
        }
        if (ans > k)
            printf("-1\n");
        else
            printf("%d\n", ans);
        return;
    }
    int ans = N * N;
    for (int i0 = 0; i0 < n; ++i0)
    {
        int yans = 0;
        for (int i = 0; i < n; ++i)
        {
            int ans1 = 0, ans2 = 0;
            for (int j = 0; j < m; ++j)
            {
                if (a[i][j] != a[i0][j])
                    ++ans1;
                else
                    ++ans2;
            }
            yans += min(ans1, ans2);
        }
        ans = min(ans, yans);
    }
    if (ans > k)
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
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}