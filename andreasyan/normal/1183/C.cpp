#include <bits/stdc++.h>
using namespace std;

int k, n, a, b;

bool stg(long long x)
{
    long long kk = k;
    long long nn = n;
    kk -= (x * a);
    nn -= x;
    kk -= (nn * b);
    return kk >= 1;
}

void solv()
{
    cin >> k >> n >> a >> b;
    int l = 0, r = n;
    while ((r - l) > 3)
    {
        int m = (l + r) / 2;
        if (stg(m))
            l = m;
        else
            r = m;
    }
    for (int m = r; m >= l; --m)
    {
        if (stg(m))
        {
            cout << m << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int tt;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}