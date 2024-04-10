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

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n;
int a[N];

int t[N * 4];
void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = a[tl];
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = gcd(t[pos * 2], t[pos * 2 + 1]);
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);

    return gcd(qry(tl, m, l, m, pos * 2),
               qry(m + 1, tr, m + 1, r, pos * 2 + 1));
}

int f[N];
int ans[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    bil(1, n, 1);

    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < sz(v); ++j)
            v[j] = gcd(v[j], a[i]);
        v.push_back(a[i]);

        vector<int> vv;
        for (int j = 0; j < sz(v); ++j)
        {
            if (!j || (v[j] != v[j - 1]))
                vv.push_back(v[j]);
        }
        v = vv;

        f[i] = f[i - 1];
        for (int j = 0; j < sz(v); ++j)
        {
            if (i - v[j] + 1 >= 1 && qry(1, n, i - v[j] + 1, i, 1) == v[j])
                f[i] = max(f[i], i - v[j] + 1);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (f[i] == 0)
        {
            ans[i] = 0;
            continue;
        }
        ans[i] = ans[f[i] - 1] + 1;
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}