#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
int MOD = 998244353;
const ld E = 1e-9;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#ifndef LONG_LONG_MAX
#define LONG_LONG_MAX LLONG_MAX
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".DAT"); _write(x ".SOL")
#define output _write("output.txt")
#define input _read("input.txt")
#define prev time_prev
#ifndef M_PI
#define M_PI acos(-1)
#endif
#define remove tipa_remove
#define next tipa_next
#define left tipa_left
#define right tipa_right
#define y1 hello_world
unsigned char ccc;
bool _minus = false;
template<typename T>
inline T sqr(T t) {
    return (t * t);
}
inline void read(ll &n) {
    n = 0;
    _minus = false;
    while (true) {
        ccc = getchar();
        if (ccc == ' ' || ccc == '\n')
        break;
        if (ccc == '-') {
            _minus = true;
            continue;
        }
        n = n * 10 + ccc - '0';
    }
    if (_minus)
    n *= -1;
}
inline bool read(int &n) {
    n = 0;
    _minus = false;
    while (true) {
        ccc = getchar();
        if (ccc == ' ' || ccc == '\n') {
            if (ccc == '\n')
            return true;
            break;
        }
        if (ccc == '-') {
            _minus = true;
            continue;
        }
        n = n * 10 + ccc - '0';
    }
    if (_minus)
    n *= -1;
    return false;
}
char wwww[19];
int kkkk;
inline void write(ll y) {
    long long x = y;
    kkkk = 0;
    if (x < 0) {
        putchar('-');
        x *= -1;
    }
    if (!x){
        ++kkkk; wwww[kkkk] = '0';
    }else
    while (x) {
        ++kkkk;
        wwww[kkkk] = char(x % 10 + '0');
        x /= 10;
    }
    for (int i = kkkk; i >= 1; --i)
    putchar(wwww[i]);
}
#ifdef LOCAL
//#define __DEBUG
#endif
#ifdef __DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

ll __pow(ll a, ll b){
    if (b == 0)
    return 1;
    if (b & 1){
        return (__pow(a, b - 1) * a) % MOD;
    }
    return sqr(__pow(a, b >> 1)) % MOD;
}

const int MAX = 2e5 + 10;

ll ar[MAX];
ll t1[MAX << 2], t2[MAX << 2];
int n;

pair<ll, ll> find(int v, int tl, int tr, int l, int r){
    if (l <= tl && tr <= r){
        return {t1[v], t2[v]};
    }
    if (tr < l || r < tl){
        return {0, 1};
    }
    int x = (tl + tr) >> 1;
    auto a = find(v << 1, tl, x, l, r);
    auto b = find(v << 1 | 1, x + 1, tr, l, r);
    return {(b.first + a.first * b.second) % MOD, (a.second * b.second) % MOD};
}

ll find(int l, int r){
    return find(1, 1, n, l, r).first;
}

void build(int v, int l, int r){
    if (l == r){
        t1[v] = t2[v] = ar[l];
        return;
    }
    int x = (l + r) >> 1;
    build(v << 1, l, x);
    build(v << 1 | 1, x + 1, r);
    t1[v] = (t1[v << 1 | 1] + t1[v << 1] * t2[v << 1 | 1]) % MOD;
    t2[v] = (t2[v << 1] * t2[v << 1 | 1]) % MOD;
}

inline void __div(ll &res, int l, int r){
    ll t = find(l, r - 1);
    res = (res + MOD - t) % MOD;
}

inline void __mul(ll &res, int l, int r){
    ll t = find(l, r - 1);
    res = (res + t) % MOD;
}

int main() {
    sync;
    srand((unsigned int) time(NULL));
    cout.precision(10);
    cout << fixed;
    
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    int ans = 1;
    int c = 0;
    int d = 0;
    for (int i = 0; i < n; i++){
        c += v[i] == 0;
        d += v[i] == 1;
    }
    for (int i = 0; i < n; i++){
        int a = 0;
        for (int j = 0; j < i; j++){
            a += v[j] == 0;
        }
        for (int j = i; j < n; j++){
            a += v[j] == 1;
        }
        ans = max(ans, a);
    }
    
    cout << max(ans, max(c, d)) << endl;
    
}