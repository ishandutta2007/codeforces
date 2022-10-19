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
const int N = 300005, m = 20;

int n, qq;
int a[N];

int z;
int t[N * m][2];
int q[N * m];

void solv()
{
    cin >> n >> qq;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        if (i == 1 || a[i] != a[i - 1])
        {
            int pos = 0;
            for (int j = m - 1; j >= 0; --j)
            {
                int u = 0;
                if ((a[i] & (1 << j)))
                    u = 1;

                if (!t[pos][u])
                    t[pos][u] = ++z;
                pos = t[pos][u];
                ++q[pos];
            }
        }
    }

    int x = 0;
    while (qq--)
    {
        int y;
        cin >> y;
        x ^= y;

        int ans = 0;
        int pos = 0;
        for (int j = m - 1; j >= 0; --j)
        {
            if (j != m - 1 && pos == 0)
                break;

            int u = 0;
            if ((x & (1 << j)))
                u = 1;

            if (q[t[pos][u]] < (1 << j))
            {
                pos = t[pos][u];
            }
            else
            {
                ans |= (1 << j);
                pos = t[pos][(u ^ 1)];
            }
        }

        cout << ans << "\n";
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}