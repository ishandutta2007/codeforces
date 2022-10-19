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
    int x, y, d;
};

int n, m, k;
ban b[N];

bool operator<(const ban& a, const ban& b)
{
    return (a.d - k) < (b.d - k);
}

int p[N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}
void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p[x] = y;
}

void solv()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d%d", &b[i].x, &b[i].y, &b[i].d);
    sort(b + 1, b + m + 1);

    for (int x = 1; x <= n; ++x)
        p[x] = x;

    ll ans = 0;
    bool z = false;
    for (int i = 1; i <= m; ++i)
    {
        if (b[i].d < k)
        {
            kpc(b[i].x, b[i].y);
        }
        else if (fi(b[i].x) != fi(b[i].y))
        {
            ans += (b[i].d - k);
            kpc(b[i].x, b[i].y);
            z = true;
        }
    }

    if (!z)
    {
        int minu = abs(b[1].d - k);
        for (int i = 1; i <= m; ++i)
            minu = min(minu, abs(b[i].d - k));
        ans += minu;
    }

    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}