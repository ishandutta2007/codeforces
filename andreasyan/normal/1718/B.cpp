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
const int N = 102;

int n;
int a[N], ca[N];

int f[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        ca[i] = a[i];

    f[0] = 1;
    f[1] = 1;
    for (int i = 2; ; ++i)
    {
        f[i] = f[i - 1] + f[i - 2];
        if (f[i] > 1000000000)
        {
            break;
        }
    }

    ll sa = 0;
    for (int i = 1; i <= n; ++i)
        sa += a[i];

    int m = -1;
    ll sf = 0;
    for (int i = 0; ; ++i)
    {
        sf += f[i];
        if (f[i] > 1000000000)
            break;
        if (sf == sa)
        {
            m = i;
            break;
        }
    }

    if (n > m + 1)
    {
        cout << "NO\n";
        return;
    }

    for (int s = 1; s <= n; ++s)
    {
        for (int i = 1; i <= n; ++i)
            a[i] = ca[i];
        bool z = true;
        ll xx = 0;
        for (int i = 1; i <= n; ++i)
        {
            ll x = 0;
            if (i == s)
            {
                a[i]--;
                x |= (1LL << 0);
            }
            for (int j = m; j >= 1; --j)
            {
                if (a[i] >= f[j])
                {
                    a[i] -= f[j];
                    x |= (1LL << j);
                }
            }
            for (int j = 0; j < m; ++j)
            {
                if ((x & (1LL << j)) && (x & (1LL << (j + 1))))
                {
                    z = false;
                    break;
                }
            }
            if (z == false)
                break;
            if ((x & xx))
            {
                z = false;
                break;
            }
            xx |= x;
        }
        if (z)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}