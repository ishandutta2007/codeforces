#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(1234443);

long long n, k;

bool qry(long long l, long long r)
{
    cout << l << ' ' << r << endl;
    string s;
    cin >> s;
    return (s == "Yes");
}

int main()
{
    cin >> n >> k;
    long long l = 1, r = n;
    while (1)
    {
        if ((r - l + 1) <= 55)
        {
            int x = rnd() % (r - l + 1);
            if (qry(l + x, l + x))
                break;
            l = max(1LL, l - k);
            r = min(n, r + k);
        }
        else
        {
            long long m = (l + r) / 2;
            if (qry(l, m))
            {
                l = l - k;
                r = m + k;
            }
            else
            {
                l = m + 1 - k;
                r = r + k;
            }
        }
        l = max(1LL, l);
        r = min(n, r);
    }
    return 0;
}