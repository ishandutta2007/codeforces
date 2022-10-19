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
 
int pop(int x) {
    return __builtin_popcount(x);
}

const int M = 1010;

string s;
int k;
int a[M];
int c[M][M];
int len[M];

void pre() {
    for (int i = 0; i < M; ++i)
        c[i][0] = 1;
    for (int i = 1; i < M; ++i)
        for (int j = 1; j < M; ++j)
            c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
}

void read() {
    cin >> s;
    cin >> k;
}

void kill() {
    if (k == 0) {
        cout << "1\n";
        return;
    }

    s = "0" + s;
    int e = s.length() - 1;
    while (s[e] == '1') {
        s[e] = '0';
        --e;
    }
    s[e] = '1';

    int sum = 0;
    for (int i = 0; i < (int) s.length(); ++i) {
        if (s[i] == '1') {
            int rem = s.length() - i - 1;
            for (int j = 0; j <= rem; ++j)
                udd(a[sum + j], c[rem][j]);
            ++sum;
        }
    }

    if (k == 1) {
        cout << sub(a[1], 1) << endl;
        return;
    }

    len[1] = 0;
    for (int i = 2; i < M; ++i)
        len[i] = 1 + len[pop(i)];

    int ans = 0;
    for (int i = 2; i < M; ++i)
        if (len[i] == k - 1)
            udd(ans, a[i]);

    cout << ans << endl;
}

int main() {
#ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
#endif
    //ios_base::sync_with_stdio(false);

    pre();
    read();
    kill();

    return 0;
}