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
const int N = 40;

int n;
double k;
ll a[N];

int c[(1 << (N / 2))];

void solv()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int x;
            cin >> x;
            a[i] |= (x * (1LL << j));
        }
        a[i] |= (1LL << i);
    }

    for (int x = 0; x < (1 << (n / 2)); ++x)
    {
        bool z = true;
        for (int i = 0; i < n / 2; ++i)
        {
            if ((x & (1 << i)))
            {
                if ((x & a[i]) != x)
                {
                    z = false;
                    break;
                }
            }
        }
        if (z)
        {
            ll y = (1LL << n) - 1;
            int q = 0;
            for (int i = 0; i < n / 2; ++i)
            {
                if ((x & (1 << i)))
                {
                    y &= a[i];
                    ++q;
                }
            }

            int u = 0;
            for (int i = n / 2; i < n; ++i)
            {
                if ((y & (1LL << i)))
                {
                    if ((a[i] & x) == x)
                    {
                        u |= (1 << (i - n / 2));
                    }
                }
            }
            c[u] = max(c[u], q);
        }
    }

    for (int x = (1 << (n / 2 + n % 2)) - 1; x >= 0; --x)
    {
        for (int i = 0; i < n / 2 + n % 2; ++i)
        {
            if ((x & (1 << i)))
                c[(x ^ (1 << i))] = max(c[(x ^ (1 << i))], c[x]);
        }
    }

    int ans = 0;
    for (int x = 0; x < (1 << (n / 2 + n % 2)); ++x)
    {
        bool z = true;
        for (int i = 0; i < n / 2 + n % 2; ++i)
        {
            if ((x & (1 << i)))
            {
                if ((x & (a[n / 2 + i] >> (n / 2))) != x)
                {
                    z = false;
                    break;
                }
            }
        }
        if (z)
        {
            int q = 0;
            for (int i = 0; i < n / 2 + n % 2; ++i)
            {
                if ((x & (1 << i)))
                    ++q;
            }
            ans = max(ans, q + c[x]);
        }
    }

    cout << (k / ans) * (k / ans) * (ans * (ans - 1) / 2) << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(9);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}