#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, d, t;
    cin >> k >> d >> t;
    int T = (k + d - 1) / d * d;
    int part1 = k;
    int part2 = T - part1;
    int l = 0, r = 4 * t;
    while(r - l > 1) {
        int m = (l + r) / 2;
        int R = m % (2 * T);
        int A = 4 * part1 * (m / (2 * T)) + 2 * min(2 * part1, R);
        int B = 2 * part2 * (m / (2 * T)) + max((int)0, R - 2 * part1);
        if(A + B >= 4 * t) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << fixed << setprecision(8);
    cout << r / 2. << endl;
    return 0;
}