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

int n;
int a[N];

struct ban
{
    ll s;
    ll p;
    ban()
    {
        s = p = 0;
    }
    ban(ll x)
    {
        s = x;
        if (x < 0)
            p = x;
        else
            p = 0;
    }
};
ban mer(const ban& l, const ban& r)
{
    ban ans;
    ans.s = l.s + r.s;
    ans.p = min(l.p, l.s + r.p);
    return ans;
}

ban t[N * 4];

void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(y);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

bool so(int i, int j)
{
    return a[i] > a[j];
}

int b[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        b[i] = i;
    sort(b + 1, b + n + 1, so);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ubd(1, n, b[i], a[b[i]], 1);
        if (t[1].p >= 0)
        {
            ++ans;
            continue;
        }
        ubd(1, n, b[i], 0, 1);
    }

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