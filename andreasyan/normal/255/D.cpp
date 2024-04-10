#include <bits/stdc++.h>
using namespace std;

long long n, x, y, c;

long long sum(long long a1, long long n, long long q)
{
    return (a1 + a1 + (n - 1) * q) * n / 2;
}

bool stg(long long k)
{
    long long q = sum(0, k + 1, 4) + 1;

    long long rr = x + k;
    if (rr > n)
    {
        q -= sum(1, (rr - n), 2);
    }

    long long ll = x - k;
    if (ll < 1)
    {
        q -= sum(1, (1 - ll), 2);
    }

    long long uu = y + k;
    if (uu > n)
    {
        q -= sum(1, (uu - n), 2);
    }

    long long dd = y - k;
    if (dd < 1)
    {
        q -= sum(1, (1 - dd), 2);
    }

    if (uu > n)
    {
        long long e = (1 + (2 * (uu - n - 1)));
        if (x + ((e - 1) / 2) > n)
        {
            q += sum(1, ((x + ((e - 1) / 2)) - n), 1);
        }
        if (x - ((e - 1) / 2) < 1)
        {
            q += sum(1, (1 - (x - ((e - 1) / 2))), 1);
        }
    }

    if (dd < 1)
    {
        long long e = (1 + (2 * (1 - dd - 1)));
        if (x + ((e - 1) / 2) > n)
        {
            q += sum(1, ((x + ((e - 1) / 2)) - n), 1);
        }
        if (x - ((e - 1) / 2) < 1)
        {
            q += sum(1, (1 - (x - ((e - 1) / 2))), 1);
        }
    }
    //cout << q << endl;
    return (q >= c);
}

long long byn()
{
    long long l = 0, r = n + n + n;
    while ((r - l) > 3)
    {
        long long m = (l + r) / 2;
        if (stg(m))
            r = m;
        else
            l = m;
    }
    for (long long m = l; m <= r; ++m)
    {
        if (stg(m))
            return m;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> x >> y >> c;
    /*long long k;
    cin >> k;*/
    cout << byn() << endl;;
    return 0;
}