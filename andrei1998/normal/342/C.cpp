#include <iostream>

using namespace std;

int main()
{
    int r, h;
    cin >> r >> h;

    int ans = 0;

    while (h >= r) {
        ans += 2;
        h -= r;
    }

    if (4LL * h * h >= 3LL * r * r)
        ans += 3;
    else if (2LL * h >= r)
        ans += 2;
    else
        ans += 1;

    cout << ans << '\n';
    return 0;
}