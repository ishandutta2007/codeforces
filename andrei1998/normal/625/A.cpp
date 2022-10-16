#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long int n, a, b, c;
    cin >> n >> a >> b >> c;

    if (a < b - c)
        cout << n / a << '\n';
    else {
        long long int k = 0;
        if (n >= b) {
            k = max(0ll, (n - b) / (b - c) + 1);
            n -= ((b - c) * (k - 1) + b);
        }

        if (k > 0)
            n += c;

        cout << k + n / a << '\n';
    }

    return 0;
}