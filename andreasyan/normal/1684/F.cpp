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
int a[N];

int ul[N], ur[N];

int minu[N * 4], maxu[N * 4];
void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        minu[pos] = ur[tl];
        maxu[pos] = ul[tl];
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    minu[pos] = min(minu[pos * 2], minu[pos * 2 + 1]);
    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
}

int qrymin(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
    {
        if (minu[pos] > y)
            return 0;
    }
    if (tl == tr)
        return tl;
    int m = (tl + tr) / 2;
    int u = qrymin(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    if (u)
        return u;
    return qrymin(tl, m, l, min(m, r), y, pos * 2);
}

int qrymax(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return n + 1;
    if (tl == l && tr == r)
    {
        if (maxu[pos] < y)
            return n + 1;
    }
    if (tl == tr)
        return tl;
    int m = (tl + tr) / 2;
    int u = qrymax(tl, m, l, min(m, r), y, pos * 2);
    if (u != n + 1)
        return u;
    return qrymax(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
}

int l[N], r[N];
int tl[N], tr[N];

int u[N];

void solv()
{
    cin >> n >> qq;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    map<int, int> mp;
    for (int i = 1; i <= n; ++i)
    {
        ul[i] = mp[a[i]];
        mp[a[i]] = i;
    }

    mp.clear();
    for (int i = n; i >= 1; --i)
    {
        ur[i] = mp[a[i]];
        if (ur[i] == 0)
            ur[i] = n + 1;
        mp[a[i]] = i;
    }

    bil(1, n, 1);

    int ansl = n + 1, ansr = 0;
    for (int i = 1; i <= qq; ++i)
    {
        cin >> l[i] >> r[i];

        tl[i] = qrymax(1, n, l[i], r[i], l[i], 1);
        tr[i] = qrymin(1, n, l[i], r[i], r[i], 1);
        ansl = min(ansl, tl[i]);
        ansr = max(ansr, tr[i]);
    }

    for (int i = 1; i <= n; ++i)
        u[i] = n + 1;
    for (int i = 1; i <= qq; ++i)
    {
        u[r[i]] = min(u[r[i]], l[i]);
    }
    for (int i = n - 1; i >= 1; --i)
        u[i] = min(u[i], u[i + 1]);

    mp.clear();
    for (int i = 1; i < ansl; ++i)
        mp[a[i]] = i;

    int ans = n;
    int j = ansl;
    for (int i = n; i >= max(1, ansr); --i)
    {
        ans = min(ans, i - j + 1);
        if (u[i] <= mp[a[i]])
            j = min(j, mp[a[i]]);
    }

    ans = max(ans, 0);
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