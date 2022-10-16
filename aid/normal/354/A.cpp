#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 5;
const long long INF = 1000ll * 1000 * 1000 * 1000;
int w[MAXN], s[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, l, r, ql, qr;
    cin >> n >> l >> r >> ql >> qr;
    for(int i = 0; i < n; i++) {
        cin >> w[i];
        s[i + 1] = s[i] + w[i];
    }
    long long ans = INF;
    for(int i = 0; i <= n; i++) {
        long long d = s[i] * l + (s[n] - s[i]) * r;
        if(i + i < n)
            d += (n - i - i - 1) * qr;
        else if(i + i > n)
            d += (i + i - n - 1) * ql;
        if(d < ans)
            ans = d;
    }
    cout << ans << '\n';
    return 0;
}