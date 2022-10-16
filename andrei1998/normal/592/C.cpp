#include <iostream>
#include <algorithm>

#define lint long long int
using namespace std;

lint gcd (lint a, lint b) {
    if (!b)
        return a;

    lint r = a % b;
    while (r) {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

lint lcm (lint a, lint b) {
    lint d = gcd(a, b);

    if (5000000000000000000ll / a / (b / d) > 0)
        return (b / d) * a;
    else
        return 5000000000000000005ll;
}

int main()
{
    lint t, a, b;
    cin >> t >> a >> b;

    if (a > b)
        swap(a, b);

    lint lc = lcm(a, b);
    lint ans = (t / lc) * a + min(t % lc, a - 1);

    lint g = gcd(t, ans);

    cout << ans / g << '/' << t / g << '\n';
    return 0;
}