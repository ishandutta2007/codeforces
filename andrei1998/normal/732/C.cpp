#include <iostream>
#include <algorithm>

#define int long long int
using namespace std;

int solve(int b, int d, int s) {
    if (b <= 1 && d <= 1 && s <= 1)
        return 0;

    int ans = 4e18 + 2005;
    for (int m1 = 0; m1 < 4; ++ m1) {
        int z = max(b + (m1 > 0), max(d + (m1 > 1), s + (m1 > 2)));

        int m2 = 0;
        if (z - (m1 > 0) == b)
            m2 = 1;
        if (z - (m1 > 1) == d)
            m2 = 2;
        if (z - (m1 > 2) == s)
            m2 = 3;


        int missed = ((z - 1) * 3 - m1 + m2) - b - d - s;
        if (missed < ans)
            ans = missed;
    }

    return ans;
}

signed main()
{
    int b, d, s;
    cin >> b >> d >> s;

    cout << solve(b, d, s) << '\n';
    return 0;
}