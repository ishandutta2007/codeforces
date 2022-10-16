#include <iostream>

using namespace std;

const int MAXN = 1005, MOD = 1000 * 1000 * 1000 + 7;
int c[MAXN][MAXN], cnt[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    for(int i = 0; i < MAXN; i++) {
        c[i][0] = 1;
        for(int j = 1; j <= i; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    }
    int k;
    cin >> k;
    int n = 0;
    for(int i = 0; i < k; i++) {
        cin >> cnt[i];
        n += cnt[i];
    }
    int ans = 1;
    for(int i = k - 1; i >= 0; i--) {
        ans = (long long)ans * c[n - 1][cnt[i] - 1] % MOD;
        n -= cnt[i];
    }
    cout << ans << '\n';
    return 0;
}