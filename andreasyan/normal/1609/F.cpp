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
#define __builtin_popcount __builtin_popcountll

int n;
ll a[N];

ll ans;
int q[60];

pair<ll, int> minu[N], maxu[N];
void rec(int l, int r)
{
    if (l == r)
    {
        ++ans;
        return;
    }

    int m = (l + r) / 2;
    rec(l, m);
    rec(m + 1, r);

    minu[m + 1] = maxu[m + 1] = m_p(a[m + 1], m + 1);
    for (int i = m + 2; i <= r; ++i)
    {
        minu[i] = min(minu[i - 1], m_p(a[i], i));
        maxu[i] = max(maxu[i - 1], m_p(a[i], i));
    }

    minu[m] = maxu[m] = m_p(a[m], m);
    for (int i = m - 1; i >= l; --i)
    {
        minu[i] = min(minu[i + 1], m_p(a[i], i));
        maxu[i] = max(maxu[i + 1], m_p(a[i], i));
    }

    memset(q, 0, sizeof q);
    int j = m + 1, k = m + 1;
    for (int i = m + 1; i <= r; ++i)
    {
        while (j > l && m_p(a[j - 1], j - 1) < maxu[i])
        {
            --j;
            ++q[__builtin_popcount(minu[j].fi)];
        }
        while (k > j && m_p(a[k - 1], k - 1) > minu[i])
        {
            --k;
            --q[__builtin_popcount(minu[k].fi)];
        }

        if (__builtin_popcount(maxu[i].fi) == __builtin_popcount(minu[i].fi))
            ans += (m - k + 1);
        ans += q[__builtin_popcount(maxu[i].fi)];
    }

    memset(q, 0, sizeof q);
    j = m, k = m;
    for (int i = m; i >= l; --i)
    {
        while (j < r && m_p(a[j + 1], j + 1) < maxu[i])
        {
            ++j;
            ++q[__builtin_popcount(minu[j].fi)];
        }
        while (k < j && m_p(a[k + 1], k + 1) > minu[i])
        {
            ++k;
            --q[__builtin_popcount(minu[k].fi)];
        }

        if (__builtin_popcount(maxu[i].fi) == __builtin_popcount(minu[i].fi))
            ans += (k - m);
        ans += q[__builtin_popcount(maxu[i].fi)];
    }
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    rec(1, n);

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