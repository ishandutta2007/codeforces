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
//    assert(x != 0);
    return bin(x, mod - 2);
}


const int M = 200200;
const int N = 3030;

int n, m;
int a[M], w[M];
int d[N][N];

void read() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> w[i];
}

void kill() {
    int spos = 0, sneg = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i])
            udd(spos, w[i]);
        else
            udd(sneg, w[i]);
    }

    for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= m; ++j)
            d[i][j] = 0;

    d[0][0] = 1;

    for (int a = 0; a < m && a <= sneg; ++a)
        for (int b = 0; a + b < m; ++b) {
            int pmin = mul(sub(sneg, a), inv(add(sneg, spos, sub(b, a))));
            udd(d[a + 1][b], mul(d[a][b], pmin));
            udd(d[a][b + 1], mul(d[a][b], sub(1, pmin)));
        }

    int mulneg = 0;
    int mulpos = 0;

    for (int a = 0; a <= m; ++a) {
        int b = m - a;
        int cur = d[a][b];

//        cerr << -a << " " << b << " " << cur << "\n";

        udd(mulneg, mul(sub(sneg, a), cur));

        udd(mulpos, mul(add(spos, b), cur));
    }

    mulneg = mul(inv(sneg), mulneg);
    mulpos = mul(inv(spos), mulpos);

    for (int i = 0; i < n; ++i)
        if (a[i]) {
            cout << mul(w[i], mulpos) << "\n";
        } else {
            cout << mul(w[i], mulneg) << "\n";
        }

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);

    read();
    kill();
}