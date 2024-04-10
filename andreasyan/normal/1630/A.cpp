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

int n, k;
bool c[(1 << 16)];

void solv()
{
    cin >> n >> k;

    for (int x = 0; x < n; ++x)
        c[x] = false;

    if (n == 4 && k == 3)
    {
        cout << "-1\n";
        return;
    }

    if (k == n - 1)
    {
        int m = 0;
        while ((1 << m) != n)
            ++m;
        for (int i = 0; i < m; ++i)
        {
            c[(1 << i)] = c[((n - 1) ^ (1 << ((i + 1) % m)))] = true;
            cout << (1 << i) << ' ' << ((n - 1) ^ (1 << ((i + 1) % m))) << "\n";
        }
    }
    else if (k != 0)
    {
        cout << k << ' ' << (n - 1) << "\n";
        cout << (k ^ (n - 1)) << ' ' << 0 << "\n";
        c[k] = true;
        c[n - 1] = true;
        c[(k ^ (n - 1))] = true;
        c[0] = true;
    }

    for (int x = 0; x < n; ++x)
    {
        if (!c[x])
        {
            cout << x << ' ' << (x ^ (n - 1)) << "\n";
            c[x] = c[(x ^ (n - 1))] = true;
        }
    }
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