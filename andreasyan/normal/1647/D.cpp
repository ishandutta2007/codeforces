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

bool isprime(int x)
{
    if (x <= 1)
        return false;
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

void solv()
{
    int x, d;
    cin >> x >> d;

    int q = 0;
    while (x % d == 0)
    {
        x /= d;
        ++q;
    }

    if (q > 1 && x > 1 && !isprime(x))
    {
        cout << "YES\n";
        return;
    }
    x *= d;
    --q;

    if (isprime(d) || q <= 1)
    {
        cout << "NO\n";
        return;
    }

    vector<int> dv;
    int dd = d;
    for (int i = 2; i <= dd; ++i)
    {
        if (dd % i == 0)
        {
            while (dd % i == 0)
                dd /= i;
            dv.push_back(i);
        }
    }
    if (dd > 1)
        dv.push_back(dd);

    if (sz(dv) >= 2)
    {
        cout << "YES\n";
        return;
    }

    int qd = 0;
    while (d % dv[0] == 0)
    {
        d /= dv[0];
        ++qd;
    }

    int qx = 0;
    while (x % dv[0] == 0)
    {
        x /= dv[0];
        ++qx;
    }

    if (qx / q + !!(qx % q) < qd)
        cout << "YES\n";
    else
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