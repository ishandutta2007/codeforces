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

int n, q, k;
int a[N];

ll t[N * 4];

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = (a[tl + 1] - a[tl - 1] - 2);
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

ll qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), pos * 2) +
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void solv()
{
    scanf("%d%d%d", &n, &q, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    bil(1, n, 1);

    while (q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);

        if (l == r)
        {
            printf("%d\n", k - 1);
            continue;
        }

        ll ans = qry(1, n, l + 1, r - 1, 1);
        ans += (a[l + 1] - 2);
        ans += (k - a[r - 1] - 1);

        printf("%lld\n", ans);
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}