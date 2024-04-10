// vim:ts=4:sts=4:sw=4:et
// MOSCOW IPT JINOTEGA
// Table #14
#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;
typedef long long i64;

const int mod = 1e9 + 7;

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

int bin(int x, ll to) { 
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

const int M = 255;
const int N = M * 2;
 
int f, b;
ll n;
int p[M];
int c[M];

int deg;
int BY;

int bold;
int P[M], E[M], S[M];

int temp[N];

struct Poly {
    int a[M];

    Poly() {
        fill(a, a + M, 0);
    }

    int& operator[](int x) {
        return a[x];
    }

    int operator[](int x) const {
        return a[x];
    }

    Poly operator+(const Poly& to) const {
        Poly ans;
        for (int i = 0; i < deg; ++i)
            ans[i] = add(a[i], to[i]);
        return ans;
    }

    Poly operator*(const Poly& to) const {
        fill(temp, temp + N, 0);
        for (int i = 0; i < deg; ++i)
            for (int j = 0; j < deg; ++j)
                udd(temp[i + j], mul(a[i], to[j]));
        for (int i = 2 * deg - 1; i >= deg; --i) {
            if (temp[i]) {
                //int cur = mul(temp[i], BY);
                //udd(temp[i - deg], cur);
                for (int t = 0; t < bold; ++t)
                    udd(temp[i - c[t]], temp[i]);
                temp[i] = 0;
            }
        }

        Poly ans;
        for (int i = 0; i < deg; ++i)
            ans[i] = temp[i];
        return ans;
    }

    void norm() {
        for (int i = min(M - 1, 2 * deg - 1); i >= deg; --i) {
            if (a[i]) {
                for (int t = 0; t < bold; ++t)
                    udd(a[i - c[t]], a[i]);
                a[i] = 0;
            }
        }
    }

} I, X;

Poly bin(Poly A, ll to) {
    Poly res = I;
    while (to) {
        if (to & 1) {
            res = res * A;
        }
        A = A * A;
        to >>= 1;
    }
    return res;
}

void read() {
    cin >> f >> b >> n;
    for (int i = 0; i < f; ++i)
        cin >> p[i];
    for (int i = 0; i < b; ++i)
        cin >> c[i];
    sort(c, c + b);

    bold = b;

    deg = c[b - 1];

    I[0] = 1;

    X[1] = 1;
    X.norm();
}

void print(const Poly &A) {
    for (int i = 0; i < deg; ++i)
        cerr << A[i] << " \n"[i + 1 == deg];
}

void calcPE() {
    int p[M];
    fill(p, p + M, 0);

    udd(p[0], 1);
    for (int i = 0; i < bold; ++i)
        p[c[i]] = sub(p[c[i]], 1);
    bool den = inv(p[deg]);
    for (int i = 0; i <= deg; ++i)
        p[i] = mul(p[i], den);

    for (int i = 0; i <= deg; ++i)
        E[i] = mul(p[deg - i], bin(mod - 1, i));

    P[0] = deg;
    for (int k = 1; k <= deg; ++k) {
        int bon = mul(bin(mod - 1, k - 1), k, E[k]);
        for (int i = 1; i < k; ++i)
            udd(bon, mul(bin(mod - 1, k - 1 + i), E[k - i], P[i]));
    }
}

void kill() {
    Poly cur;
    for (int i = 0; i < f; ++i) {
        cur = cur + bin(X, p[i]);
    }
    cur = bin(cur, n);

//    print(cur);

    S[0] = 1;
    for (int i = 1; i < deg; ++i)
        for (int j = 0; j < bold; ++j)
            if (i >= c[j])
                udd(S[i], S[i - c[j]]);

    int ans = 0;
    for (int i = 0; i < deg; ++i)
        udd(ans, mul(S[i], cur[i]));

    cout << ans << "\n";
}

int main() {
#ifdef LOCAL
    assert(freopen("g.in", "r", stdin));
#endif
    //ios_base::sync_with_stdio(false);

    read();
    calcPE();
    kill();

    return 0;
}