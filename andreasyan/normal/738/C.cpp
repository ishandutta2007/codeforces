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

struct ban
{
    int c, v;
};
bool operator<(const ban& a, const ban& b)
{
    return a.v < b.v;
}

int n, k, s, t;
ban a[N];
int g[N];

bool stg(int v)
{
    int tt = 0;
    for (int i = 0; i <= k; ++i)
    {
        int d = g[i + 1] - g[i];
        if (v >= d * 2)
            tt += d;
        else if (v < d)
            return false;
        else
            tt += (v - d) + (d - (v - d)) * 2;
    }

    return (tt <= t);
}

void solv()
{
    cin >> n >> k >> s >> t;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].c >> a[i].v;
    for (int i = 1; i <= k; ++i)
        cin >> g[i];

    sort(a + 1, a + n + 1);
    sort(g + 1, g + k + 1);
    g[k + 1] = s;

    for (int i = n - 1; i >= 1; --i)
        a[i].c = min(a[i].c, a[i + 1].c);

    int l = 1, r = n;
    int u = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(a[m].v))
        {
            u = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }

    if (u == -1)
        cout << "-1\n";
    else
        cout << a[u].c << "\n";
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