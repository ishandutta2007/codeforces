#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;

    double delta = b * b - 4 * a * c;
    delta = sqrt(delta);

    double x1 = (-b + delta) / (2 * a);
    double x2 = (-b - delta) / (2 * a);

    if (x2 > x1)
        swap(x2, x1);

    cout << fixed << setprecision(20) << x1 << '\n' << x2 << endl;
    return 0;
}