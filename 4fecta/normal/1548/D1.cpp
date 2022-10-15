#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define x first
#define y second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 6005;

int n, x, y, ans, freq[4][4];
pii a[MN];

int c3(int x) {
    if (x < 3) return 0;
    return x * (x - 1) * (x - 2) / 6;
}

int c2(int x) {
    if (x < 2) return 0;
    return x * (x - 1) / 2;
}

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
        freq[a[i].x % 4][a[i].y % 4]++;
    }
    for (int i = 0; i < 4; i += 2) {
        for (int j = 0; j < 4; j += 2) {
            ans += c3(freq[i][j]);
            for (int i2 = 0; i2 < 4; i2 += 2) {
                for (int j2 = 0; j2 < 4; j2 += 2) {
                    if (i == i2 && j == j2) continue;
                    ans += c2(freq[i][j]) * freq[i2][j2];
                }
            }
        }
    }
    printf("%lld\n", ans);

    return 0;
}