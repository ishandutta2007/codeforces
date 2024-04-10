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
const int N = 400005;

struct ban
{
    int l, r;
};
bool operator<(const ban& a, const ban& b)
{
    return a.r < b.r;
}

int n;
ban a[N];

int t[N * 4];
void ubd(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        t[pos]++;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, pos * 2);
    else
        ubd(m + 1, tr, x, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

int qry(int tl, int tr, int l, int r, int pos)
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
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].l, &a[i].r);
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n * 8 + 4; ++i)
        t[i] = 0;

    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        v.push_back(a[i].l);
        v.push_back(a[i].r);
    }
    sort(all(v));
    for (int i = 1; i <= n; ++i)
    {
        a[i].l = lower_bound(all(v), a[i].l) - v.begin() + 1;
        a[i].r = lower_bound(all(v), a[i].r) - v.begin() + 1;
    }

    int ans = n;
    for (int i = n; i >= 1; --i)
    {
        int yans = 0;
        int l = 1, r = i - 1;
        int u = i;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (a[m].r >= a[i].l)
            {
                u = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        yans += (i - u + 1);
        yans += qry(1, n * 2, 1, a[i].r, 1);
        ubd(1, n * 2, a[i].l, 1);
        ans = min(ans, n - yans);
    }

    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}