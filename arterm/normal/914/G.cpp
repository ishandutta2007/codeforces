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

const int A = 17;
const int N = 1 << A;

int bit(int mask, int i) {
    return (mask >> i) & 1;
}

int n, a[N];
int fib[N];
int OR[N], XOR[N], S[N], T[N];

void pre() {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < N; ++i)
        fib[i] = add(fib[i - 1], fib[i - 2]);
}

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x]++;
    }
}

void conv(int *a, bool rev) {
    for (int i = 0; i < A; ++i)
        for (int mask = 0; mask < N; ++mask)
            if (bit(mask, i)) {
                int x = a[mask];
                int y = a[mask ^ (1 << i)];
                a[mask] = sub(y, x);
                a[mask ^ (1 << i)] = add(x, y);
            }


    int in = inv(N);
    if (rev)
        for (int i = 0; i < N; ++i)
            a[i] = mul(a[i], in);
}

void uconv(int *a, bool rev) {
    for (int i = 0; i < A; ++i)
        for (int mask = 0; mask < N; ++mask)
            if (!bit(mask, i)) {
                if (!rev) {
                    udd(a[mask], a[mask ^ (1 << i)]);
                } else {
                    a[mask] = sub(a[mask], a[mask ^ (1 << i)]);
                }
            }
}

void kill() {
    for (int mask = 0; mask < N; ++mask) {
        for (int sub = mask; ; sub = (sub - 1) & mask) {
            udd(OR[mask], mul(a[sub], a[mask ^ sub]));
            if (sub == 0)
                break;
        }
    }

    for (int i = 0; i < N; ++i)
        S[i] = a[i];

    for (int i = 0; i < N; ++i)
        XOR[i] = a[i];
    conv(XOR, false);
    for (int i = 0; i < N; ++i)
        XOR[i] = mul(XOR[i], XOR[i]);
    conv(XOR, true);

    //for (int i = 0; i < 10; ++i)
        //cout << i << ": " << XOR[i] << endl;
    
    for (int i = 0; i < N; ++i) {
        OR[i] = mul(OR[i], fib[i]);
        XOR[i] = mul(XOR[i], fib[i]);
        S[i] = mul(S[i], fib[i]);
    }


    uconv(OR, false);
    uconv(XOR, false);
    uconv(S, false);

    for (int i = 0; i < N; ++i)
        T[i] = mul(OR[i], XOR[i], S[i]);

    uconv(T, true);

    //for (int i = 0; i < 10; ++i)
        //cerr << i << ": " << T[i] << endl;

    int ans = 0;
    for (int i = 0; i < A; ++i)
        udd(ans, T[1 << i]);
    cout << ans << endl;
}

int main() {
#ifdef LOCAL
    assert(freopen("g.in", "r", stdin));
#endif
    //ios_base::sync_with_stdio(false);

    pre();
    read();
    kill();

    return 0;
}