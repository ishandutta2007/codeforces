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

int n, m;
char a[N][N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> (a[i] + 1);
        for (int j = 1; j <= m; ++j)
            a[i][j] -= '0';
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            ans += a[i][j];
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            int q = 0;
            if (!a[i][j])
                ++q;
            if (!a[i + 1][j])
                ++q;
            if (!a[i][j + 1])
                ++q;
            if (!a[i + 1][j + 1])
                ++q;
            if (q >= 2)
            {
                cout << ans << "\n";
                return;
            }
        }
    }

    bool z = false;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (!a[i][j])
                z = true;
        }
    }

    if (z)
    {
        cout << ans - 1 << "\n";
    }
    else
    {
        cout << ans - 2 << "\n";
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}