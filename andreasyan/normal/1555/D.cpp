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
const int N = 200005;

int n, qq;
char a[N];

int p[3][N];

int qry(int u, int l, int r)
{
    while ((r % 3 + 3) % 3 != l % 3)
        --r;
    if (l > r)
        return 0;
    if (l - 3 >= 0)
        return (r - l) / 3 + 1 - (p[u][r] - p[u][l - 3]);
    return (r - l) / 3 + 1 - p[u][r];
}

void solv()
{
    cin >> n >> qq;
    cin >> (a + 1);

    for (int u = 0; u < 3; ++u)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] - 'a' == u)
                p[u][i] = 1;
            else
                p[u][i] = 0;
            if (i - 3 >= 0)
                p[u][i] += p[u][i - 3];
        }
    }

    while (qq--)
    {
        int l, r;
        cin >> l >> r;

        int ans = (r - l + 1);

        int t[3] = {0, 1, 2};
        do
        {
            ans = min(ans, qry(t[0], l, r) + qry(t[1], l + 1, r) + qry(t[2], l + 2, r));
        } while (next_permutation(t, t + 3));

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