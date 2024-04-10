//
// Created by artsem on 07.06.19.
//

#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int mod = 998244353;

int add(int x) {
    return x;
}

template<typename... T>
int add(int x, T... y) {
    x += add(y...);
    if (x >= mod)
        x -= mod;
    return x;
}

template<typename... T>
int udd(int &x, T... y) {
    return x = add(x, y...);
}

template<typename... T>
int sub(int x, T... y) {
    return add(x, mod - add(y...));
}

int mul(int x) {
    return x;
}

template<typename... T>
int mul(int x, T... y) {
    return 1ll * x * mul(y...) % mod;
}

int bin(int x, int to) {
    int y = 1;
    while (to) {
        if (to & 1)
            y = mul(x, y);
        x = mul(x, x);
        to >>= 1;
    }
    return y;
}

int inv(int x) {
    assert(x != 0);
    return bin(x, mod - 2);
}


const int M = 200200;

int n;
int d[M];
int f[M];

void read() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        d[u]++;
        d[v]++;
    }
}


void kill() {
    f[0] = 1;
    for (int i = 1; i < M; ++i)
        f[i] = mul(i, f[i - 1]);
    int ans = n;
    for (int i = 0; i < n; ++i)
        ans = mul(ans, f[d[i]]);
    cout << ans << "\n";
}

int main() {
//#ifdef LOCAL
//    assert(freopen("f.in", "r", stdin));
//#endif

    ios_base::sync_with_stdio(false);

    read();
    kill();
}