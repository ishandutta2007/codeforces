#include <bits/stdc++.h>

using namespace std;

#define M 20500500

int n, a[M], m = 24;

void conv(int *a) {

    for (int j = 0; j < m; ++j)
        for (int i = (1 << m) - 1; i >= 0; --i)
            a[i] = a[i] + ((i >> j) & 1 ? a[i ^ (1 << j)] : 0);
}

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j < 8; ++j) {
            int mask = 0, sign = -1;
            for (int k = 0; k < 3; ++k)
                if ((j >> k) & 1) {
                    mask |= (1 << (s[k] - 'a'));
                    sign *= -1;
                }
            a[mask] += sign;
        }
    }

    conv(a);

    long long ans = 0;
    for (int i = 0; i < (1 << m); ++i)
        ans ^= 1ll * a[i] * a[i];

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    read();
    cerr << "Time : " << ((double) clock() / CLOCKS_PER_SEC) << "\n";
    return 0;
}