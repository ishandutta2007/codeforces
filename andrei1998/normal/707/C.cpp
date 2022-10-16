#include <iostream>

#define int long long int
using namespace std;

signed main()
{
    int n;
    cin >> n;

    if ((n & (n - 1)) == 0) {
        if (n == 1 || n == 2) {
            cout << "-1\n";
            return 0;
        }

        cout << n * n / 4 - 1 << ' ' << n * n / 4 + 1 << endl;
        return 0;
    }

    int fact = 1;
    while (n % 2 == 0) {
        n /= 2;
        fact *= 2;
    }

    int k = n / 2;

    int a = 2 * k + 1;
    int b = 2 * k * (k + 1);
    int c = (k + 1) * (k + 1) + k * k;

    a *= fact;
    b *= fact;
    c *= fact;

    cout << b << ' ' << c << '\n';

    return 0;
}