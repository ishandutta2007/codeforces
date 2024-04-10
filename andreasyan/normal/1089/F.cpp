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
#define int long long

bool isprime(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int gcd(int a, int b, int& x, int& y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return y;
    }

    int x1, y1_;
    int g = gcd(b % a, a, x1, y1_);

    x = y1_ - (b / a) * x1;
    y = x1;
    return g;
}

void solv()
{
    int n;
    cin >> n;
    //for (int n = 2; n <= 1000; ++n)
    {
        int cn = n;
        int a = 0, b = 0;
        for (int i = 2; i * i <= n; ++i)
        {
            if (n % i == 0)
            {
                while (n % i == 0)
                    n /= i;

                if (a == 0)
                    a = i;
                else if (b == 0)
                    b = i;
            }
        }
        if (n > 1)
        {
            if (a == 0)
                a = n;
            else if (b == 0)
                b = n;
        }
        n = cn;

        if (b == 0)
        {
            cout << "NO\n";
            return;
        }

        int x, y;
        int g = gcd(a, b, x, y);

        x *= (n - 1);
        y *= (n - 1);

        if (x < 0)
        {
            int r = (-x) / b + !!((-x) % b);
            x += r * b;
            y -= r * a;
        }
        else if (y < 0)
        {
            int r = (-y) / a + !!((-y) % a);
            y += r * a;
            x -= r * b;
        }

        assert(x * a + y * b == n - 1);
        assert(x > 0 && y > 0);

        cout << "YES\n";
        cout << "2\n";
        cout << x << ' ' << n / a << "\n";
        cout << y << ' ' << n / b << "\n";
    }
}

int32_t main()
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