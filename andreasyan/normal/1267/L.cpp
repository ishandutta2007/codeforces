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
const int N = 1003;

int n, m, k;
char a[N * N];

char ans[N][N];

void solv()
{
    cin >> n >> m >> k;
    cin >> a;

    sort(a, a + n * m);

    int u = 0;
    int t = 0;
    for (int j = 0; j < m; ++j)
    {
        for (int i = u; i < k; ++i)
        {
            ans[i][j] = a[t++];
        }

        u = k - 1;
        while (u > 0 && ans[u - 1][j] == ans[u][j])
            --u;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!ans[i][j])
                ans[i][j] = a[t++];
        }
    }

    for (int i = 0; i < n; ++i)
        cout << ans[i] << "\n";
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