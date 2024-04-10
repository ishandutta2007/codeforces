#include<bits/stdc++.h>

using namespace std;

#define int long long

int check(int a, int b) {
    int x = (2 * a - b) / 3, y = a - 2 * x;
    if (min(x, y) >= 0 && (2 * a - b) % 3 == 0) return 1;
    return 0;
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, a, b;
    cin >> t;
    /*
    a - 2 * x - y = b - x - 2 * y
    a = 2 * x + y
    b = 2 * y + x

    a = x - y + b
    a = 2 * x + y

    x + y = b - y
    2 * y = b - x

    b = y - x + a
    b = 2 * y + x

    a - x = y + x
    y = a - 2 * x

    2 * a - 4 * x = b - x
    3 * x = 2 * a - b
    */
    for (int i = 1; i <= t; ++i) {
        cin >> a >> b;
        if (check(a, b) || check(b, a)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}