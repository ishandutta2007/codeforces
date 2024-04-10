#include <iostream>

using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;
int a[2][2], b[2][2], c[2][2], den;

int powMod(int x, long long p) {
    int y = 1;
    while(p) {
        if(p & 1ll)
            y = (long long)y * x % MOD;
        p >>= 1ll;
        x = (long long)x * x % MOD;
    }
    return y;
}

void matPow(long long p) {
    b[0][0] = 1;
    b[0][1] = 0;
    b[1][0] = 0;
    b[1][1] = 1;
    while(p) {
        if(p & 1ll) {
            c[0][0] = ((long long)b[0][0] * a[0][0] +
                       (long long)b[0][1] * a[1][0]) % MOD;
            c[0][1] = ((long long)b[0][0] * a[0][1] +
                       (long long)b[0][1] * a[1][1]) % MOD;
            c[1][0] = ((long long)b[1][0] * a[0][0] +
                       (long long)b[1][1] * a[1][0]) % MOD;
            c[1][1] = ((long long)b[1][0] * a[0][1] +
                       (long long)b[1][1] * a[1][1]) % MOD;
            b[0][0] = c[0][0];
            b[0][1] = c[0][1];
            b[1][0] = c[1][0];
            b[1][1] = c[1][1];
        }
        p >>= 1ll;
        c[0][0] = ((long long)a[0][0] * a[0][0] +
                   (long long)a[0][1] * a[1][0]) % MOD;
        c[0][1] = ((long long)a[0][0] * a[0][1] +
                   (long long)a[0][1] * a[1][1]) % MOD;
        c[1][0] = ((long long)a[1][0] * a[0][0] +
                   (long long)a[1][1] * a[1][0]) % MOD;
        c[1][1] = ((long long)a[1][0] * a[0][1] +
                   (long long)a[1][1] * a[1][1]) % MOD;
        a[0][0] = c[0][0];
        a[0][1] = c[0][1];
        a[1][0] = c[1][0];
        a[1][1] = c[1][1];
    }
    a[0][0] = b[0][0];
    a[0][1] = b[0][1];
    a[1][0] = b[1][0];
    a[1][1] = b[1][1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    a[0][0] = 1;
    a[0][1] = 1;
    a[1][0] = 2;
    a[1][1] = 0;
    den = 2;
    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        long long p;
        cin >> p;
        matPow(p);
        den = powMod(den, p);
    }
    int num = (long long)a[1][1] * ((MOD + 1) / 2) % MOD;
    den = (long long)den * ((MOD + 1) / 2) % MOD;
    cout << num << '/' << den << '\n';
    return 0;
}