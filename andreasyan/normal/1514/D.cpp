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
const int N = 300005, S = 530;

int n, m;
int a[N];

struct ban
{
    int i;
    int l, r;
};
bool operator<(const ban& a, const ban& b)
{
    if (a.l / S < b.l / S)
        return true;
    if (a.l / S > b.l / S)
        return false;
    if ((a.l / S) % 2)
        return a.r < b.r;
    return a.r > b.r;
}

ban b[N];

int q[N];

int ans[N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 0; i < m; ++i)
    {
        b[i].i = i;
        cin >> b[i].l >> b[i].r;
    }
    sort(b, b + m);

    int l = 1, r = 0;
    for (int i = 0; i < m; ++i)
    {
        while (r < b[i].r)
        {
            ++r;
            ++q[a[r]];
        }
        while (l > b[i].l)
        {
            --l;
            ++q[a[l]];
        }
        while (r > b[i].r)
        {
            --q[a[r]];
            --r;
        }
        while (l < b[i].l)
        {
            --q[a[l]];
            ++l;
        }

        ans[b[i].i] = 1;
        for (int j = 0; j < 60; ++j)
        {
            int d = b[i].r - b[i].l + 1;
            int k = b[i].l + rnd() % d;
            if (q[a[k]] > (d + 1) / 2)
            {
                ans[b[i].i] = 1 + d - (d - q[a[k]]) * 2 - 1;
                break;
            }
        }
    }

    for (int i = 0; i < m; ++i)
        cout << ans[i] << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    /*int st = 1000;
    while (st--)
    {
        int x = rnf() % 15;
        int y = rnf() % 15;

        if (y > (x + y + 1) / 2)
        {
            if (rec(x, y) != vrec(x, y))
            {
                cout << x << ' ' << y << "\n";
                cout << rec(x, y) << "\n";
                cout << vrec(x, y) << "\n";
                return 0;
            }
        }
    }
    return 0;*/

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}