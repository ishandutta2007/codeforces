#include <iostream>
#include <complex>

using namespace std;

typedef complex <int> Point;

int main()
{
    Point A, B, C;

    int x, y;
    cin >> x >> y; A = Point(x, y);
    cin >> x >> y; B = Point(x, y);
    cin >> x >> y; C = Point(x, y);

    cout << "3\n";

    Point ans = A + B - C;
    cout << ans.real() << ' ' << ans.imag() << '\n';
    ans = A + C - B;
    cout << ans.real() << ' ' << ans.imag() << '\n';
    ans = B + C - A;
    cout << ans.real() << ' ' << ans.imag() << '\n';
    return 0;
}