#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;

int n;
int a[N];

const int m = 200;
int p[N][m + 5];

vector<int> v[m + 5];

void solv()
{
    for (int i = 1; i <= m; ++i)
        v[i].clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            p[i][j] = p[i - 1][j];
        }
        p[i][a[i]]++;
        v[a[i]].push_back(i);
    }
    int ans = 0;
    for (int j = 1; j <= m; ++j)
    {
        ans = max(ans, p[n][j]);
        for (int l = 0, r = (int)v[j].size() - 1; l < r; ++l, --r)
        {
            for (int k = 1; k <= m; ++k)
            {
                ans = max(ans, (l + 1) * 2 + p[v[j][r] - 1][k] - p[v[j][l]][k]);
            }
        }
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}