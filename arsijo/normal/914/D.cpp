#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
int MOD = 1e9 + 7;
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

int n;
const int MAX = 5e5 + 10;

int t[MAX << 2];

int ar[MAX];

int gcd(int a, int b){
    while(a && b){
        a >= b ? a %= b : b %= a;
    }
    return a + b;
}

void build(int v, int l, int r){
    if(l == r){
        t[v] = ar[l];
        return;
    }
    int x = (l + r) >> 1;
    build(v << 1, l, x);
    build(v << 1 | 1, x + 1, r);
    t[v] = gcd(t[v << 1], t[v << 1 | 1]);
}

void find(int v, int tl, int tr, int l, int r, int k, int &g){
    if(g > 1 || tr < l || r < tl){
        return;
    }
    if(t[v] % k == 0){
        return;
    }
    if(tl == tr){
        g++;
        return;
    }
    int x = (tl + tr) >> 1;
    find(v << 1, tl, x, l, r, k, g);
    find(v << 1 | 1, x + 1, tr, l, r, k, g);
}

void upd(int v, int l, int r, int pos, int k){
    if(l == r){
        t[v] = k;
        return;
    }
    int x = (l + r) >> 1;
    if(pos <= x){
        upd(v << 1, l, x, pos, k);
    }else{
        upd(v << 1 | 1, x + 1, r, pos, k);
    }
    t[v] = gcd(t[v << 1], t[v << 1 | 1]);
}

int main() {
    sync;
    srand((unsigned int) time(NULL));
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL
    input;
    output;
#else
    
#endif
    
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
    }
    
    build(1, 1, n);
    
    int m;
    cin >> m;
    
    while(m--){
        int t;
        cin >> t;
        if(t == 1){
            int l, r, k;
            cin >> l >> r >> k;
            int q = 0;
            find(1, 1, n, l, r, k, q);
            cout << (q <= 1 ? "YES" : "NO") << endl;
        }else{
            int pos, k;
            cin >> pos >> k;
            upd(1, 1, n, pos, k);
        }
    }
    
#ifdef LOCAL
    cout << "---------- " << clock() << endl;
#endif
    
}