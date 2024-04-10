#include <bits/stdc++.h>

using namespace std;

#define int long long

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n;
    k = n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    int i = 2, cnt = 0, f = k;
    while (i * i <= n) {
        if (n % i == 0) {
            cnt++;
            f = i;
            while (n % i == 0) {
                n /= i;
            }
        }
        ++i;
    }
    if (n != 1 && n != k) cnt++, f = n;
    if (cnt > 1) cout << 1;
    else cout << f;
    return 0;
}