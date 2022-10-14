#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb emplace_back
#define all(x) (x).begin(), (x).end()

const int INF = 1e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long A, B, C, D;
    cin >> A >> B >> C >> D;
    long long ans = 0;
    for (int z = C; z <= D; z++) {
        if (B + C <= z) continue;
        long long y1 = max(B, z - A + 1);
        ans += max(0LL, C - y1 + 1) * (B - A + 1);
        if (y1 <= B) continue;
        y1 = min(y1 - 1, C);
        if (z - y1 + 1 > B) continue;
        long long mn = max(A, z - y1 + 1);
        long long mx = min(B, z - B + 1);
        if (mx < mn) continue;
        ans += (2 * B + 2 - mn - mx) * (mx - mn + 1) / 2;
    }
    cout << ans;
    return 0;
}