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
const int N = 1000006;

int n, k;
int a[N];

ll s[N * 4];
ll laz[N * 4];

void shi(int tl, int tr, int pos)
{
    if (laz[pos] == 0)
        return;
    int m = (tl + tr) / 2;
    s[pos * 2] += laz[pos] * (m - tl + 1);
    laz[pos * 2] += laz[pos];
    s[pos * 2 + 1] += laz[pos] * (tr - m);
    laz[pos * 2 + 1] += laz[pos];
    laz[pos] = 0;
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        s[pos] += y * 1LL * (r - l + 1);
        laz[pos] += y;
        return;
    }
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    s[pos] = s[pos * 2] + s[pos * 2 + 1];
}

int qry(int tl, int tr, int k, int pos)
{
    if (tl == tr)
        return tl;
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    if (s[pos * 2] >= k)
        return qry(tl, m, k, pos * 2);
    return qry(m + 1, tr, k - s[pos * 2], pos * 2 + 1);
}

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);

    int ans = N;

    int m = 1000000;
    ubd(0, m, 0, 0, 1, 1);
    for (int i = 1; i <= n; ++i)
    {
        int u = qry(0, m, 1, 1);
        ubd(0, m, u, u, -1, 1);
        ubd(0, m, u + 2, u + 1 + (a[i] - 1) / 2, 1, 1);
        ubd(0, m, u + 2, u + 1 + (a[i] - 1) / 2 + (1 - a[i] % 2), 1, 1);
        if (s[1] >= k)
            ans = min(ans, qry(0, m, k, 1));
    }

    if (ans == N)
        cout << "-1\n";
    else
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}