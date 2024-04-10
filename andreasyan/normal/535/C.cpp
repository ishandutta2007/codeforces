#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;

long long A, B;
int q;

bool stg(long long l, long long r, long long t, long long m)
{
    if (m >= (r - l + 1))
    {
        return t >= (A + (r - 1) * B);
    }
    long long sum = ((A + (l - 1) * B + A + (r - 1) * B) * (r - l + 1)) / 2;
    if (sum % m == 0)
    {
        return max((A + (r - 1) * B), sum / m) <= t;
    }
    else
    {
        return max((A + (r - 1) * B), sum / m + 1) <= t;
    }
}

int main()
{
    cin >> A >> B >> q;
    while (q--)
    {
        long long ll, t, m;
        cin >> ll >> t >> m;
        if (!stg(ll, ll, t, m))
        {
            cout << "-1" << endl;
            continue;
        }
        long long l = ll, r = ll + N + N;
        while ((r - l) > 3)
        {
            long long rr = (l + r) / 2;
            if (stg(ll, rr, t, m))
                l = rr;
            else
                r = rr;
        }
        for (long long rr = r; rr >= l; --rr)
        {
            if (stg(ll, rr, t, m))
            {
                cout << rr << endl;
                break;
            }
        }
    }
    return 0;
}