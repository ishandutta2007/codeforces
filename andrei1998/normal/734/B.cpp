#include <bits/stdc++.h>

#define int long long int
using namespace std;

signed main()
{
    int k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;

    int k56 = min(k5, k6);

    int k256 = min(k2, k56);

    int sum = 256LL * k256;

    k56 -= k256;
    k2 -= k256;

    int k32 = min(k3, k2);

    sum += 32LL * k32;

    cout << sum << '\n';
    return 0;
}