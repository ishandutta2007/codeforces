#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9 + 5;

int main()
{
    ios_base :: sync_with_stdio(false);

    int n;
    cin >> n;

    int l = -INF;
    int r = +INF;

    int sum = 0;
    for (int i = 1; i <= n; ++ i) {
        int c, d;
        cin >> c >> d;

        if (d == 1)
            l = max(1900 - sum, l);
        else
            r = min(1900 - sum - 1, r);
        sum += c;
    }


    if (r < l) {
        cout << "Impossible\n";
        return 0;
    }
    else if (r == INF) {
        cout << "Infinity\n";
        return 0;
    }

    cout << r + sum << '\n';
    return 0;
}