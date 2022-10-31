#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int r1, r2, c1, c2, d1, d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;

    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            if (i == j) continue;
            for (int k = 1; k <= 9; ++k) {
                if (k == i || k == j) continue;
                for (int p = 1; p <= 9; ++p) {
                    if (p == i || p == k || p == j) continue;
                    if (i + j == r1 && p + k == r2 && i + k == c1 && j + p == c2 && i + p == d1 && j + k == d2) {
                        cout << i << ' ' << j << '\n' << k << ' ' << p << '\n';
                        return 0;
                    }
                }
            }
        }
    }

    puts("-1");
}