#include <bits/stdc++.h>

using namespace std;

int d, n, m;

bool check(int x, int y) {
    return ((y >= -x + d) && (y >= x - d) && (y <= x + d) && (y <= (-x + 2 * n - d)));
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> d >> m;
    while (m --> 0) {
        int x, y;
        cin >> x >> y;
        if (check(x, y))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}