#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    double ans = 1e18;

    //Incercam pe urcus
    if (a >= b) {
        int k = ((a - b) / b) / 2;
        double x = (a - b) / (2.0 * k);

        if (x < ans)
            ans = x;
    }

    //Incercam pe coboras
    if (a >= b) {
        int k = ((a - b) / b) / 2;
        double x = (a + b) / (2.0 * k + 2);

        if (x < ans)
            ans = x;
    }

    if (ans == 1e18)
        cout << "-1\n";
    else
        cout << fixed << setprecision(12) << ans << '\n';

    return 0;
}