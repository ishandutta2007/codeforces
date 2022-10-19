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
const int N = 200005, S = 400;

int n, m;
int x[N], y[N];

int ty[N], u[N];

int mp[N];
int h[N];

int q[N][S];
int qq[N];

int s[N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> x[i] >> y[i];

    for (int i = 1; i <= m; ++i)
        cin >> ty[i] >> u[i];

    for (int i = 1; i <= n; ++i)
        mp[i] = m + 1;

    for (int i = m; i >= 1; --i)
    {
        if (ty[i] == 1)
            h[i] = mp[u[i]];
        else
            mp[u[i]] = i;
    }

    int ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        int ty = ::ty[i];
        int u = ::u[i];
        if (ty == 1)
        {
            s[u] = i;
            if (x[u] + y[u] >= S)
            {
                for (int j = i + x[u]; j < h[i]; j += (x[u] + y[u]))
                {
                    qq[j]++;
                }
                for (int j = i + x[u] + y[u]; j < h[i]; j += (x[u] + y[u]))
                {
                    qq[j]--;
                }
            }
            else
            {
                if (i + x[u] <= m)
                    q[i + x[u]][x[u] + y[u]]++;
                if (i + x[u] + y[u] <= m)
                    q[i + x[u] + y[u]][x[u] + y[u]]--;
            }
        }
        else
        {
            if (i - 1 >= (s[u] + x[u]))
            {
                int o = (i - 1 - (s[u] + x[u]) + 1);
                o %= (x[u] + y[u]);
                if (o == 0)
                    o += (x[u] + y[u]);
                if (o <= y[u])
                    --ans;
            }
            if (x[u] + y[u] < S)
            {
                {
                    int l = 0, r = m;
                    int gt = m + 1;
                    while (l <= r)
                    {
                        int m = (l + r) / 2;
                        if (s[u] + x[u] + (x[u] + y[u]) * m >= i)
                        {
                            gt = s[u] + x[u] + (x[u] + y[u]) * m;
                            r = m - 1;
                        }
                        else
                            l = m + 1;
                    }
                    if (gt <= m)
                        q[gt][x[u] + y[u]]--;
                }
                {
                    int l = 0, r = m;
                    int gt = m + 1;
                    while (l <= r)
                    {
                        int m = (l + r) / 2;
                        if (s[u] + x[u] + y[u] + (x[u] + y[u]) * m >= i)
                        {
                            gt = s[u] + x[u] + y[u] + (x[u] + y[u]) * m;
                            r = m - 1;
                        }
                        else
                            l = m + 1;
                    }
                    if (gt <= m)
                        q[gt][x[u] + y[u]]++;
                }
            }
        }

        ans += qq[i];
        for (int j = 1; j < S; ++j)
        {
            ans += q[i][j];
            if (i + j <= m)
                q[i + j][j] += q[i][j];
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
        solv();
    return 0;
}