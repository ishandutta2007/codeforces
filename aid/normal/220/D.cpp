#include <iostream>

using namespace std;

const int MAXN = 4005, MOD = 1000 * 1000 * 1000 + 7;
int gcd[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    for(int i = 0; i < MAXN; i++)
        gcd[0][i] = i;
    for(int i = 1; i < MAXN; i++) {
        gcd[i][0] = i;
        for(int j = 1; j <= i; j++)
            gcd[i][j] = gcd[j][i % j];
    }
    for(int i = 0; i < MAXN; i++)
        for(int j = i + 1; j < MAXN; j++)
            gcd[i][j] = gcd[j][i];
    int w, h;
    cin >> w >> h;
    w++;
    h++;
    int ans = 0;
    for(int x0 = 0; x0 < 2; x0++) {
        int cx0 = (x0? w / 2 : (w + 1) / 2);
        for(int y0 = 0; y0 < 2; y0++) {
            int cy0 = (long long)cx0 * (y0? h / 2 : (h + 1) / 2) % MOD;
            for(int x1 = 0; x1 < 2; x1++) {
                int cx1 = (long long)cy0 * (x1? w / 2 : (w + 1) / 2) % MOD;
                for(int y1 = 0; y1 < 2; y1++) {
                    int cy1 = (long long)cx1 * (y1? h / 2 : (h + 1) / 2) % MOD;
                    for(int x2 = 0; x2 < 2; x2++) {
                        int cx2 = (long long)cy1 * (x2? w / 2 : (w + 1) / 2) % MOD;
                        for(int y2 = 0; y2 < 2; y2++) {
                            int cy2 = (long long)cx2 * (y2? h / 2 : (h + 1) / 2) % MOD;
                            if(!(((x1 ^ x0) * (y2 ^ y0)) ^ ((y1 ^ y0) * (x2 ^ x0))))
                                ans = (ans + cy2) % MOD;
                        }
                    }
                }
            }
        }
    }
    ans -= 3ll * w * h * w * h % MOD;
    ans %= MOD;
    ans += 2ll * w * h % MOD;
    ans %= MOD;
    ans -= 1ll * w * h * (h - 1) * (h - 2) % MOD;
    ans %= MOD;
    ans -= 1ll * h * w * (w - 1) * (w - 2) % MOD;
    for(int x = 1; x < w; x++)
        for(int y = 1; y < h; y++) {
            if(x == 0 && y == 0)
                continue;
            ans -= 12ll * (gcd[x][y] - 1) * (w - x) * (h - y) % MOD;
            ans %= MOD;
        }
    ans = (ans + MOD) % MOD;
    cout << ans << '\n';
    return 0;
}