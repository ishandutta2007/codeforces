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
const int N = 88, INF = 1000000009;

int n;
int a[N];

int dp[N * N][N * 2];
int ndp[N * N][N * 2];

void ubd(int& x, int y)
{
    x = max(x, y);
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    vector<int> v;
    int q = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 1)
        {
            v.push_back(q);
            q = 0;
        }
        else
            ++q;
    }
    v.push_back(q);

    int s = 0;
    for (int i = 0; i < sz(v); ++i)
        s += v[i];

    for (int q = 0; q <= n * (n - 1) / 2; ++q)
    {
        for (int p = 0; p <= s * 2; ++p)
            ndp[q][p] = dp[q][p] = -INF;
    }
    ndp[0][s] = dp[0][s] = 0;

    int g = 0;
    for (int i = 0; i < sz(v); ++i)
    {
        for (int q = 0; q <= s * sz(v); ++q)
        {
            for (int p = 0; p <= s * 2; ++p)
            {
                for (int h = 0; h <= s; ++h)
                {
                    if (0 <= p + v[i] - h && p + v[i] - h <= s * 2 && q + abs(p + v[i] - h - s) <= s * sz(v))
                        ubd(ndp[q + abs(p + v[i] - h - s)][p + v[i] - h], dp[q][p] + h * (s - h));
                }
            }
        }
        memcpy(dp, ndp, sizeof ndp);
    }

    int ans = 0;
    for (int q = 0; q <= n * (n - 1) / 2; ++q)
    {
        ans = max(ans, dp[q][s] / 2);
        cout << ans << ' ';
    }
    cout << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //scanf("%d", &tt);
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}