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

int n;
ll a[N];

void ka()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
}

void gen()
{
    n = rnd() % 100 + 3;
    a[1] = rnd() % 100;
    for (int i = 2; i <= n; ++i)
    {
        a[i] = a[i - 1] + rnd() % 100 + 1;
    }
}

ll t[N];
void ubdd(int x, ll y)
{
    while (x <= n)
    {
        t[x] += y;
        x += (x & (-x));
    }
}
void ubd(int tl, int tr, int l, int r, ll y, int pos)
{
    if (l > r)
        return;
    ubdd(l, y);
    ubdd(r + 1, -y);
}

ll qry(int tl, int tr, int x, int pos)
{
    ll ans = 0;
    while (x)
    {
        ans += t[x];
        x -= (x & (-x));
    }
    return ans;
}

bool c[N];

ll b[N];

void solv()
{
    //gen();
    ka();

    for (int i = 1; i <= n; ++i)
        ubd(1, n, i, i, a[i], 1);

    for (int i = 1; i <= n; ++i)
    {
        b[i] = a[i];
    }

    /*int j = n;
    for (int i = n - 1; i >= 1; --i)
    {
        while (b[i] + 2 <= b[i + 1])
        {
            if (j == i)
                j = n;
            --b[j];
            ++b[i];
            --j;
        }
        if (j != n && b[j] != b[j + 1])
            j = n;
    }
    for (int i = 1; i <= n; ++i)
        printf("%lld ", b[i]);
    printf("\n");*/

    int j = n;
    for (int i = n - 1; i >= 1; --i)
    {
        ll x = qry(1, n, i + 1, 1);
        ll l = 0, r = x;
        ll ans;
        while (l <= r)
        {
            ll m = (l + r) / 2;
            ll q = 0;
            if (j - m <= i)
            {
                ++q;
                ll mm = m;
                mm -= (j - i);
                q += (mm / (n - i));
            }
            if (a[i] + m + 2 > x - q)
            {
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        ll m = ans;
        ubd(1, n, i, i, m, 1);
        if (j - m <= i)
        {
            ubd(1, n, i + 1, j, -1, 1);
            m -= (j - i);
            j = n;
            ubd(1, n, i + 1, j, -(m / (n - i)), 1);
            m %= (n - i);
            ubd(1, n, n - m + 1, n, -1, 1);
            j -= m;
        }
        else
        {
            ubd(1, n, j - m + 1, j, -1, 1);
            j -= m;
        }
        if (qry(1, n, i, 1) == qry(1, n, i + 1, 1))
            j = i;
    }
    for (int i = 1; i <= n; ++i)
        b[i] = qry(1, n, i, 1);
    for (int i = 1; i <= n; ++i)
        printf("%lld ", b[i]);
    printf("\n");
    return;

    while (1)
    {
        bool z = false;
        for (int i = 1; i < n; ++i)
        {
            c[i] = false;
            if (a[i + 1] - a[i] >= 2)
            {
                z = true;
                c[i] = true;
            }
        }
        if (!z)
            break;
        for (int i = 1; i < n; ++i)
        {
            if (c[i])
            {
                ++a[i];
                --a[i + 1];
            }
        }
    }

    deque<int> q;
    for (int i = 1; i <= n; ++i)
        q.push_back(a[i]);

    while (sz(q) >= 2 && q[0] < q[1])
        q.pop_front();
    while (sz(q) >= 2 && q[sz(q) - 2] < q[sz(q) - 1])
        q.pop_back();

    for (int i = 0; i < sz(q); ++i)
    {
        assert(q[i] == q[0]);
    }
    assert(sz(q) <= 2);

    for (int i = 1; i <= n; ++i)
        printf("%lld ", a[i]);
    printf("\n");

    for (int i = 1; i <= n; ++i)
        assert(a[i] == b[i]);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}