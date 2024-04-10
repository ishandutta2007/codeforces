#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;

long long p(long long x)
{
    long long q[2] = {};
    long long d = 1;
    int z = 0;
    while (1)
    {
        if (x <= q[0] + q[1] + d)
        {
            q[z] += (x - (q[0] + q[1]));
            break;
        }
        q[z] += d;
        d *= 2;
        z ^= 1;
    }
    q[0] %= M;
    q[1] %= M;
    long long ans = (((1 + 2 * (q[0] - 1) + 1) * q[0]) / 2) % M;
    ans += (((2 + 2 * q[1]) * q[1]) / 2) % M;
    ans %= M;
    return ans;
}

int main()
{
    long long l, r;
    cin >> l >> r;
    cout << (p(r) - p(l - 1) + M) % M << endl;
    return 0;
}