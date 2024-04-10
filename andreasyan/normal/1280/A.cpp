#include <bits/stdc++.h>
using namespace std;
const int N = 502, M = 1000000007;

int x;
int n, m;
string a;

void solv()
{
    cin >> x >> a;
    n = m = a.size();
    for (int i = 1; i <= x; ++i)
    {
        int q = (a[i - 1] - '0' - 1);
        n = (n + (q * 1LL * (n - i + M))) % M;
        int mm = m;
        while (q--)
        {
            if (m >= x)
                break;
            for (int j = i; j < mm; ++j)
            {
                a += a[j];
                ++m;
                if (m >= x)
                    break;
            }
        }
    }
    cout << n << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int tt;
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}