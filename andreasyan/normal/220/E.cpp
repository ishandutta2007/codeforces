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

int n;
ll k;
int a[N];

void ubd(int t[], int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] += y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(t, tl, m, x, y, pos * 2);
    else
        ubd(t, m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

int qry(int t[], int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return (qry(t, tl, m, l, min(m, r), pos * 2) +
            qry(t, m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int tl[N * 4], tr[N * 4];

void solv()
{
    scanf("%d%lld", &n, &k);
    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        v.push_back(a[i]);
    }
    sort(all(v));
    for (int i = 1; i <= n; ++i)
    {
        a[i] = lower_bound(all(v), a[i]) - v.begin() + 1;
    }
    ll yk = 0;
    for (int i = n; i >= 2; --i)
    {
        yk += qry(tr, 1, n, 1, a[i] - 1, 1);
        ubd(tr, 1, n, a[i], 1, 1);
    }
    yk += qry(tr, 1, n, 1, a[1] - 1, 1);
    ubd(tl, 1, n, a[1], 1, 1);
    if (yk <= k)
    {
        printf("%lld\n", (n * 1LL * (n - 1)) / 2);
        return;
    }
    ll ans = 0;
    int r = 2;
    for (int l = 1; l <= n - 1; ++l)
    {
        while (yk > k && r <= n)
        {
            yk -= qry(tl, 1, n, a[r] + 1, n, 1);
            yk -= qry(tr, 1, n, 1, a[r] - 1, 1);
            ubd(tr, 1, n, a[r], -1, 1);
            ++r;
        }
        ans += (n - r + 1);
        yk += qry(tl, 1, n, a[l + 1] + 1, n, 1);
        yk += qry(tr, 1, n, 1, a[l + 1] - 1, 1);
        ubd(tl, 1, n, a[l + 1], 1, 1);
    }
    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}