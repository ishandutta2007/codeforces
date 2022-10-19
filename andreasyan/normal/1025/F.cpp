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
const int N = 2003;

struct ban
{
    int x, y;
    ban(){}
    ban(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return m_p(a.x, a.y) < m_p(b.x, b.y);
}

int n;
ban a[N];

ll f(ban t1, ban t2, ban t)
{
    return (t1.x - t.x) * 1LL * (t1.y - t2.y) - (t1.y - t.y) * 1LL * (t1.x - t2.x);
}

ban u;
bool so(const ban& a, const ban& b)
{
    ban aa = a;
    if (a.y - u.y < 0)
    {
        aa.x = u.x - a.x + u.x;
        aa.y = u.y - a.y + u.y;
    }
    ban bb = b;
    if (b.y - u.y < 0)
    {
        bb.x = u.x - b.x + u.x;
        bb.y = u.y - b.y + u.y;
    }
    return f(u, aa, bb) > 0;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].x >> a[i].y;
    sort(a + 1, a + n + 1);

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        vector<ban> v;
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
                continue;
            v.push_back(a[j]);
        }

        u = a[i];
        sort(all(v), so);

        /*for (int j = 0; j < sz(v); ++j)
        {
            ll q = 0;
            for (int i = 0; i < sz(v); ++i)
            {
                if (i == j)
                    continue;
                if (f(u, v[j], v[i]) > 0)
                    ++q;
            }
            if ((q * (q - 1) / 2 * (n - q - 2) * (n - q - 3) / 2) == 1)
            {
                cout << i << "\n";
            }
            ans = (ans + q * (q - 1) / 2 * (n - q - 2) * (n - q - 3) / 2);
        }
        continue;*/

        ll q = 0;
        bool z = true;
        for (int i = 1; i < sz(v); ++i)
        {
            {
                if (f(u, v[0], v[i]) > 0)
                    ++q;
            }
        }
        for (int i = 0; i < sz(v); ++i)
        {
            ans = (ans + q * (q - 1) / 2 * (n - q - 2) * (n - q - 3) / 2);
            if (i < sz(v) - 1)
            {
                if (z)
                {
                    if (f(u, v[i], v[i + 1]) > 0)
                        --q;
                }
                else
                {
                    if (f(u, v[i], v[i + 1]) < 0)
                        --q;
                }
                if (f(u, v[i], v[i + 1]) < 0)
                    z ^= true;
                if (z)
                {
                    if (f(u, v[i + 1], v[i]) > 0)
                        ++q;
                }
                else
                {
                    if (f(u, v[i + 1], v[i]) < 0)
                        ++q;
                }
            }
        }
    }

    cout << ans / 2 << "\n";
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
        solv();
    return 0;
}