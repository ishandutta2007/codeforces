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
const int N = 200005, M = 1000000007;

int n;
int a[N];

int t[N];
void ubd(int x, int y)
{
    while (x <= n)
    {
        t[x] = (t[x] + y) % M;
        x += (x & (-x));
    }
}

int qry(int l, int r)
{
    int ans = 0;
    while (r)
    {
        ans = (ans + t[r]) % M;
        r -= (r & (-r));
    }

    --l;
    while (l)
    {
        ans = (ans - t[l]) % M;
        l -= (l & (-l));
    }

    return ans;
}

int ul[N], ur[N];

int smax[N];

vector<int> g[N];

void solv()
{
    cin >> n;

    for (int i = 0; i <= n + 1; ++i)
    {
        g[i].clear();
    }

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    vector<int> v;
    for (int i = 1; i <= n; ++i)
        v.push_back(a[i]);
    sort(all(v));

    for (int i = 1; i <= n; ++i)
        a[i] = lower_bound(all(v), a[i]) - v.begin() + 1;

    memset(t, 0, sizeof t);
    for (int i = 1; i <= n; ++i)
    {
        ul[i] = (qry(1, a[i] - 1) + 1) % M;
        ubd(a[i], ul[i]);
    }

    memset(t, 0, sizeof t);
    for (int i = n; i >= 1; --i)
    {
        ur[i] = (qry(a[i] + 1, n) + 1) % M;
        ubd(a[i], ur[i]);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = (ans + ul[i] * 1LL * ur[i]) % M;
    }

    smax[n] = a[n];
    for (int i = n - 1; i >= 1; --i)
        smax[i] = max(smax[i + 1], a[i]);

    for (int i = 1; i <= n; ++i)
    {
        int l = i + 1, r = n;
        int u = n + 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (smax[m] > a[i])
            {
                u = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }

        g[u].push_back(i);
    }

    memset(t, 0, sizeof t);
    for (int i = 1; i <= n + 1; ++i)
    {
        for (int j = sz(g[i]) - 1; j >= 0; --j)
        {
            ur[g[i][j]] = (qry(a[g[i][j]] + 1, n) + 1) % M;
            ubd(a[g[i][j]], ur[g[i][j]]);
        }

        for (int j = 0; j < sz(g[i]); ++j)
        {
            ans = (ans - ul[g[i][j]] * 1LL * ur[g[i][j]]) % M;
        }

        for (int j = sz(g[i]) - 1; j >= 0; --j)
        {
            ubd(a[g[i][j]], -ur[g[i][j]]);
        }
    }

    ans = (ans + M) % M;
    cout << ans << "\n";
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