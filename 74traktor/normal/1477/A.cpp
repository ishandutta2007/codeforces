#include <bits/stdc++.h>

using namespace std;

#define int long long

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*set < int > T;
    vector < int > d = {-5, -20, 13, -14, -2, -11};
    for (int i = -10; i <= 10; ++i) {
        for (int j = -10; j <= 10; ++j) {
            for (int z = -10; z <= 10; ++z) {
                for (int w = -10; w <= 10; ++w) {
                    for (int q = -10; q <= 10; ++q) {
                        int sum = i * d[0] + j * d[1] + z * d[2] + w * d[3] + q * d[4];
                        sum += (1 - i - j - z - w - q) * d[5];
                        T.insert(sum);
                    }
                }
            }
        }
    }
    for (auto key : T) {
        if (-100 <= key && key <= 100) {
            cout << key << " ";
        }
    }
    cout << '\n';*/
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n >> k;
        vector < int > a;
        int w = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        for (int i = 1; i < n; ++i) w = __gcd(w, a[i] - a[i - 1]);
        if (abs(k - a[0]) % w == 0) {
            cout << "YES" << '\n';
        }
        else cout << "NO" << '\n';
    }
    return 0;
}