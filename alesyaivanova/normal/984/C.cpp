#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b)
{
    if (a < b)
    {
        long long c = b;
        b = a;
        a = c;
    }
    while (b != 0)
    {
        long long c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long p, q, b;
        cin >> p >> q >> b;
        long long m = p % q;
        if (m == 0)
        {
            cout << "Finite\n";
            continue;
        }
        long long u = gcd(q, m);
        q /= u;
        long long h = b;
        while (h > 1)
        {
            h = gcd(q, h);
            q /= h;
        }
        if (q == 1)
            cout << "Finite\n";
        else
            cout << "Infinite\n";
    }
}