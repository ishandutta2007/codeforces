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
const int N = 300005;
const int m = 62;

struct ban
{
    ll x;
    int v;
};
bool operator<(const ban& a, const ban& b)
{
    return a.x < b.x;
}

int n;
ban a[N];

vector<ban> v[m];
ll s[m];

ll rec(int j)
{
    ll ss = 0;
    for (int k = 0; k < j; ++k)
        ss += s[k];

    if ((s[j] + ss) > 0)
    {
        if (ss <= 0)
            return (1LL << j);
        ll x = rec(j - 1);

        ll u = 0;
        for (int i = 0; i < sz(v[j]); ++i)
        {
            if (__builtin_popcountll((v[j][i].x & x)) % 2 == 1)
                u -= v[j][i].v;
            else
                u += v[j][i].v;
        }

        if (u > 0)
            x |= (1LL << j);

        return x;
    }
    else
    {
        if (ss >= 0)
            return (1LL << j);
        ll x = rec(j - 1);

        ll u = 0;
        for (int i = 0; i < sz(v[j]); ++i)
        {
            if (__builtin_popcountll((v[j][i].x & x)) % 2 == 1)
                u -= v[j][i].v;
            else
                u += v[j][i].v;
        }

        if (u < 0)
            x |= (1LL << j);

        return x;
    }
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].v >> a[i].x;

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = m - 1; j >= 0; --j)
        {
            if ((a[i].x & (1LL << j)))
            {
                v[j].push_back(a[i]);
                s[j] += a[i].v;
                break;
            }
        }
    }

    cout << rec(m - 1) << "\n";
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