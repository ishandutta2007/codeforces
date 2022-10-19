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
const int N = 400005, M = 1000000007;

struct ban
{
    bool z;
    int l, r;
    ban()
    {
        z = false;
        l = r = 0;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.r < b.r;
}

int n;
ban a[N];

int t[N * 4];
int q[N];

void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = (t[pos] + y) % M;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = (t[pos * 2] + t[pos * 2 + 1]) % M;
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), pos * 2) +
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1)) % M;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].l >> a[i].r;
    }
    int qq;
    cin >> qq;
    while (qq--)
    {
        int i;
        cin >> i;
        a[i].z = true;
    }

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        q[i] = (1 + qry(1, 2 * n, a[i].l, a[i].r, 1)) % M;
        ubd(1, 2 * n, a[i].l, q[i], 1);
    }

    int ans = 0;
    int i = n;
    int L = 0;
    while (1)
    {
        while (i >= 1 && (a[i].z == false || a[i].l <= L))
        {
            ubd(1, 2 * n, a[i].l, (M - q[i]) % M, 1);
            --i;
        }
        if (i == 0)
            break;

        ans = (ans + qry(1, 2 * n, L + 1, a[i].r, 1) - q[i] + 1) % M;
        L = a[i].l;
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}