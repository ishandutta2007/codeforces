#include <bits/stdc++.h>

using namespace std;

const int M = 200200;

#define long long long

int a[M], n, b[M], ds[M], m = 0, h[M];
long f[M];
int bad[M], sz;

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

void build(int d) {
    for (int i = 0; i < d; ++i)
        b[i] = a[i];
    for (int i = 0; i < n; ++i)
        b[i % d] = max(b[i % d], a[i]);
    for (int i = 0; i < n; ++i)
        b[i] = b[i % d];
}

void recount(int t) {
    fill(bad, bad + t + 1, 0);
    for (int i = 2; i <= t; ++i)
        if (t % i == 0)
            for (int j = i; j <= t; j += i)
                bad[j] = 1;
    for (int i = 1; i <= t; ++i)
        bad[i] += bad[i - 1];
}

int cnt(int k) {
    return k - bad[k];
}

long run(int d) {
    for (int i = 3 * n; i >= 0; --i) {
        int x = i % n;
        if (b[x] != a[x])
            h[x] = 0;
        else
            h[x] = 1 + h[(x + 1) % n];
    }

    long ans = 0;

    for (int i = 0; i < n; ++i) {
        h[i] = min(n - 1, h[i]);
        ans += cnt(h[i] / d);
    }

    return ans;
}

void kill() {
    long ans = 0;
    for (int d = 1; d < n; ++d)
        if (n % d == 0) {
            build(d);
            recount(n / d);
            ans += run(d);
        }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    read();
    kill();
    return 0;
}