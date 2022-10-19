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
const int N = 503, M = 998244353;

int n;
int a[N * 2][N];

bool c[N * 2];
int q[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n * 2; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n * 2; ++i)
        c[i] = false;

    int ans = 1;
    vector<int> ansv;
    while (1)
    {
        bool z = true;
        for (int i = 1; i <= n * 2; ++i)
        {
            if (!c[i])
            {
                z = false;
                break;
            }
        }
        if (z)
            break;

        int u = 0;
        for (int j = 1; j <= n; ++j)
        {
            for (int i = 1; i <= n; ++i)
                q[i] = 0;
            for (int i = 1; i <= n * 2; ++i)
            {
                if (c[i])
                    continue;
                if (!q[a[i][j]])
                    q[a[i][j]] = i;
                else
                    q[a[i][j]] = -1;
            }
            for (int i = 1; i <= n; ++i)
            {
                if (q[i] > 0)
                {
                    u = q[i];
                    break;
                }
            }
        }

        if (u == 0)
        {
            ans = (ans * 2) % M;
            for (int i = 1; i <= n * 2; ++i)
            {
                if (!c[i])
                {
                    u = i;
                    break;
                }
            }
        }

        for (int i = 1; i <= n * 2; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (a[i][j] == a[u][j])
                {
                    c[i] = true;
                    break;
                }
            }
        }
        ansv.push_back(u);
    }

    cout << ans << "\n";
    sort(all(ansv));
    for (int i = 0; i < n; ++i)
        cout << ansv[i] << ' ';
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}