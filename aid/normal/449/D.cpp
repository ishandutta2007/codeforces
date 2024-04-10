#include <iostream>

using namespace std;

const int MAXN = 2000 * 1000 + 5, LOGN = 20,
    MOD = 1000 * 1000 * 1000 + 7;
int c[MAXN], pow2[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        c[((1 << LOGN) - 1) & ~a]++;
    }
    for(int i = 0; i < LOGN; i++)
        for(int j = 0; j < (1 << LOGN); j++)
            if(!(j & (1 << i)))
                c[j | (1 << i)] += c[j];
    pow2[0] = 1;
    for(int i = 1; i <= n; i++)
        pow2[i] = (2 * pow2[i - 1]) % MOD;
    for(int i = 0; i < (1 << LOGN); i++)
        c[i] = pow2[c[i]];
    int ans = 0;
    for(int i = 0; i < (1 << LOGN); i++)
        ans = (ans + (__builtin_popcount(i) & 1? MOD - c[i] : c[i])) % MOD;
    cout << ans << '\n';
    return 0;
}