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

ll n;

/*bool por()
{
    //cin >> n;
    for (int k = 2; k * (k - 1) / 2 <= n; ++k)
    {
        if ((n - k * (k - 1) / 2) % k == 0)
        {
            cout << k << "\n";
            return true;
        }
    }
    cout << -1 << "\n";
    return false;
}*/

void solv()
{
    cin >> n;

    int q = 0;
    while (n % 2 == 0)
    {
        ++q;
        n /= 2;
    }

    if (n == 1)
    {
        cout << "-1\n";
        return;
    }

    ll k = 1;
    for (int i = 0; i < q + 1; ++i)
        k *= 2;
    cout << min(n, k) << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    /*for (n = 2; n <= 100; ++n)
    {
        cout << n << ' ';
        por();
    }
    return 0;*/

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}