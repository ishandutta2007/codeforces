#include <iostream>

using namespace std;

int main()
{
    double s;
    double a, b;
    cin >> a >> b;
    s = 60 * a + b;
    double h, d, c, n;
    cin >> h >> d >> c >> n;
    if (s >= 1200) cout << ((int)(h + n - 1) / (int)n) * 0.8 * c;
    else cout << min (((int)(h + n - 1) / (int)n) * c, ((int)(h + d * (1200 - s) + n - 1) / (int)n) * 0.8 * c);
}