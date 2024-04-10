#include <iostream>
#include <cmath>

using namespace std;

typedef long long int lint;

const double EPS = 1e-5;
int R;

bool inside(double x, double y) {
    return x * x + y * y <= 1LL * R * R + EPS;
}

bool haxagonInside(double x, double y) {
    return inside(x + 0.5, y + sqrt(3) / 2) &&
           inside(x + 0.5, y - sqrt(3) / 2) &&
           inside(x + 1, y) &&
           inside(x - 0.5, y + sqrt(3) / 2) &&
           inside(x - 0.5, y - sqrt(3) / 2) &&
           inside(x - 1, y);
}

int main()
{
    cin >> R;

    lint res = 0;

    //Even lines
    double x = 1.5;
    double y = sqrt(3) / 2;
    for (; x <= R; x += 3) {
        int st = 0;
        int dr = 3 * 1000000 + 5;
        int ans = -1;

        while (st <= dr) {
            int mid = (st + dr) >> 1;
            if (haxagonInside(x, y + mid * sqrt(3))) {
                ans = mid;
                st = mid + 1;
            }
            else
                dr = mid - 1;
        }

        if (ans >= 0)
            res += 4 * (ans + 1);
    }


    //Odd lines
    x = 0, y = 0;
    for (; x <= R; x += 3) {
        int st = 0;
        int dr = 3 * 1000000 + 5;
        int ans = -1;

        while (st <= dr) {
            int mid = (st + dr) >> 1;
            if (haxagonInside(x, y + mid * sqrt(3))) {
                ans = mid;
                st = mid + 1;
            }
            else
                dr = mid - 1;
        }

        if (ans >= 0) {
            if (x > 0)
                res += 4 * ans + 2;
            else
                res += 2 * ans + 1;
        }
    }

    cout << res << '\n';
    return 0;
}