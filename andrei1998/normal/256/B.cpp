#include <iostream>
#include <algorithm>

#define lint long long int
using namespace std;

int n, x, y, c;

bool works(int d) {
    //Sabia avea 2 parti
    lint _c = c;

    //Partea de sus
    for (int dx = 0; x - dx >= 1 && dx <= d && _c > 0; ++ dx) {
        int lim_dy = d - dx;
        _c -= min(n - y, lim_dy) + 1LL;
        _c -= min(y - 1, lim_dy) + 1LL;
        ++ _c;
    }

    //Partea de jos
    for (int dx = 1; x + dx <= n && dx <= d && _c > 0; ++ dx) {
        int lim_dy = d - dx;
        _c -= min(n - y, lim_dy) + 1LL;
        _c -= min(y - 1, lim_dy) + 1LL;
        ++ _c;
    }

    return _c <= 0;
}

int main()
{
    cin >> n >> x >> y >> c;

    int st = 0;
    int dr = 200000;
    int mid;
    int ans = dr + 1;

    while (st <= dr) {
        mid = (st + dr) >> 1;
        if (works(mid)) {
            ans = mid;
            dr = mid - 1;
        }
        else
            st = mid + 1;
    }

    cout << ans << '\n';
    return 0;
}