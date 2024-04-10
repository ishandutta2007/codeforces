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
const int N = 503;

int n, k;
int a[N][N];

int x1[N * N], x2[N * N], y1_[N * N], y2[N * N];

int p[N * 2][N * 2];

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n * n; ++i)
    {
        x1[i] = y1_[i] = N;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            x1[a[i][j]] = min(x1[a[i][j]], i);
            x2[a[i][j]] = max(x2[a[i][j]], i);
            y1_[a[i][j]] = min(y1_[a[i][j]], j);
            y2[a[i][j]] = max(y2[a[i][j]], j);
        }
    }

    int k0 = 0;
    for (int i = 1; i <= n * n; ++i)
    {
        if (x2[i])
            ++k0;
    }

    if (k0 <= k)
    {
        cout << k - k0 << "\n";
        return;
    }

    for (int d = 1; d <= n; ++d)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
                p[i][j] = 0;
        }
        for (int i = 1; i <= n * n; ++i)
        {
            if (!x2[i])
                continue;
            if (max(x2[i] - x1[i] + 1, y2[i] - y1_[i] + 1) > d)
                continue;
            p[x2[i]][y2[i]]++;
            p[x2[i] + d - (x2[i] - x1[i])][y2[i]]--;
            p[x2[i]][y2[i] + d - (y2[i] - y1_[i])]--;
            p[x2[i] + d - (x2[i] - x1[i])][y2[i] + d - (y2[i] - y1_[i])]++;
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                p[i][j] += p[i - 1][j];
                p[i][j] += p[i][j - 1];
                p[i][j] -= p[i - 1][j - 1];
                if (i >= d && j >= d)
                {
                    if (k0 - p[i][j] == k || k0 - p[i][j] + 1 == k)
                    {
                        cout << "1\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "2\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}