#include <iostream>
#include <algorithm>

using namespace std;

bool works(int x, int n, int m) {
    int sase = x / 6;
    int doi = x / 2 - x / 6;
    int trei = x / 3 - x / 6;

    n = max(0, n - doi);
    m = max(0, m - trei);

    return n + m <= sase;
}

int main()
{
    int st = 1;
    int dr = 10000005;
    int ans = dr + 1;

    int n, m;
    cin >> n >> m;

    int mijl;
    while (st <= dr) {
        mijl = (st + dr) >> 1;

        if (works(mijl, n, m)) {
            dr = mijl - 1;
            ans = mijl;
        }
        else
            st = mijl + 1;
    }

    cout << ans << '\n';
    return 0;
}