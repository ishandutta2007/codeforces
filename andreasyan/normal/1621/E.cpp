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
const int N = 100005;

int n, m;
int a[N];

int kk[N];
vector<int> b[N];
ll s[N];

bool stg(int i, int j)
{
    return s[i] <= a[j] * 1LL * kk[i];
}

bool so(int i, int j)
{
    return s[i] * kk[j] < s[j] * kk[i];
}
int p[N];

bool pr[N], su[N];

int p1[N], s1[N];

vector<bool> ans[N];
void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        b[i].clear();
        s[i] = 0;
        ans[i].clear();
    }

    for (int i = 1; i <= m; ++i)
    {
        cin >> kk[i];
        for (int ii = 0; ii < kk[i]; ++ii)
        {
            int x;
            cin >> x;
            b[i].push_back(x);
            s[i] += x;
        }
    }

    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    n = m;
    reverse(a + 1, a + n + 1);

    for (int i = 1; i <= n; ++i)
        p[i] = i;
    sort(p + 1, p + n + 1, so);

    pr[0] = true;
    for (int i = 1; i <= n; ++i)
    {
        pr[i] = pr[i - 1];
        if (!stg(p[i], i))
            pr[i] = false;
    }

    su[n + 1] = true;
    for (int i = n; i >= 1; --i)
    {
        su[i] = su[i + 1];
        if (!stg(p[i], i))
            su[i] = false;
    }

    p1[0] = 0;
    p1[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        p1[i] = p1[i - 1] + !stg(p[i], i - 1);
    }

    s1[n + 1] = 0;
    s1[n] = 1;
    for (int i = n - 1; i >= 1; --i)
    {
        s1[i] = s1[i + 1] + !stg(p[i], i + 1);
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < sz(b[p[i]]); ++j)
        {
            int u;

            if ((s[p[i]] - b[p[i]][j]) * kk[p[i]] == s[p[i]] * (kk[p[i]] - 1))
                u = i;
            else if ((s[p[i]] - b[p[i]][j]) * kk[p[i]] > s[p[i]] * (kk[p[i]] - 1))
            {
                int l = i + 1, r = n;
                u = i;
                while (l <= r)
                {
                    int m = (l + r) / 2;
                    if ((s[p[i]] - b[p[i]][j]) * kk[p[m]] >= s[p[m]] * (kk[p[i]] - 1))
                    {
                        u = m;
                        l = m + 1;
                    }
                    else
                        r = m - 1;
                }
            }
            else
            {
                int l = 1, r = i - 1;
                u = i;
                while (l <= r)
                {
                    int m = (l + r) / 2;
                    if ((s[p[i]] - b[p[i]][j]) * kk[p[m]] <= s[p[m]] * (kk[p[i]] - 1))
                    {
                        u = m;
                        r = m - 1;
                    }
                    else
                        l = m + 1;
                }
            }

            bool z = false;
            if (i <= u)
            {
                if (pr[i - 1] && su[u + 1])
                {
                    if (p1[u] - p1[i] == 0)
                    {
                        z = true;
                    }
                }
            }
            else
            {
                if (pr[u - 1] && su[i + 1])
                {
                    if (s1[u] - s1[i] == 0)
                    {
                        z = true;
                    }
                }
            }

            if ((s[p[i]] - b[p[i]][j]) > a[u] * 1LL * (kk[p[i]] - 1))
                z = false;

            ans[p[i]].push_back(z);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < sz(ans[i]); ++j)
        {
            if (ans[i][j])
                putchar('1');
            else
                putchar('0');
        }
    }
    putchar('\n');
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