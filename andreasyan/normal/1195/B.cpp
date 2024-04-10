#include <bits/stdc++.h>
using namespace std;

long long ans;
long long n, k;
long long q;

int main()
{
    cin >> n >> k;
    long long i = 1;
    while (n)
    {
        if (q <= k)
        {
            q += i;
            ++i;
            --n;
        }
        else
        {
            ans += (q - k);
            n -= (q - k);
            q = k;
        }
    }
    cout << ans << endl;
    return 0;
}