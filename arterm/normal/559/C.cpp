#include <bits/stdc++.h>

using namespace std;

const int M = 200200;
const int N = 2020;
const int mod = 1000000007;

#define long long long
#define x first
#define y second

int h, w, n;
pair<int, int> cell[N];

void read() {
    cin >> h >> w >> n;
    for (int i = 0; i < n; ++i) {
        cin >> cell[i].first >> cell[i].second;
        cell[i].x--;
        cell[i].y--;
    }
    cell[n++] = make_pair(h - 1, w - 1);
    sort(cell, cell + n);
}

long f[M], r[M];

void pre() {
    f[0] = 1;
    for (int i = 1; i < M; ++i)
        f[i] = (1ll * i * f[i - 1]) % mod;

    r[1] = 1;
    for (int i = 2; i < M; ++i) {
        r[i] = -1ll * (mod / i) * r[mod % i];
        r[i] %= mod;
        if (r[i] < 0)
            r[i] += mod;
    }

    r[0] = 1;
    for (int i = 1; i < M; ++i) {
        r[i] = (r[i] * r[i - 1]) % mod;
    }
}

long binom(long n, long k) {
    if (k < 0 || k > n)
        return 0;
    return (((f[n] * r[k]) % mod) * r[n - k]) % mod;
}

long ways(long x, long y) {
    return binom(x + y, x);
}

long d[M];

bool inside(const pair<int, int> &a, const pair<int, int> &b) {
    return a.x <= b.x && a.y <= b.y;
}

void kill() {
    for (int i = 0; i < n; ++i) {
        d[i] = ways(cell[i].first, cell[i].second);
        for (int j = 0; j < i; ++j) 
            if (inside(cell[j], cell[i])) {
                d[i] = (d[i] - d[j] * ways(cell[i].x - cell[j].x, cell[i].y - cell[j].y)) % mod;
            }
    }
    long ans = d[n - 1];
    if (ans < 0)
        ans += mod;
    cout << ans << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    read();
    pre();
    kill();
    return 0;
}