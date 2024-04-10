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

const int MAX = 1000;

int dp1[MAX + 10][MAX + 10]; // length is i and we used j segments
int dp2[MAX + 10][MAX + 10];

inline void add(int &val, int v){
    val += v;
    if(val >= MOD){
        val -= MOD;
    }
}

int c[MAX + MAX + 10][MAX + MAX + 10];
ll fac[MAX + MAX + 10];

inline ll get(int n, int m){
    return c[n + m][m];
}

int main() {
    sync;
    srand((unsigned int) time(NULL));
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL
#else
    
#endif
    
    fac[0] = 1;
    for(int i = 1; i <= MAX + MAX; i++){
        fac[i] = (fac[i - 1] * 1LL * i) % MOD;
    }
    
    c[0][0] = 1;
    for(int i = 1; i <= MAX + MAX; i++){
        c[i][0] = c[i][i] = 1;
        for(int j = 1; j < i; j++){
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]);
            if(c[i][j] >= MOD)
                c[i][j] -= MOD;
        }
    }
    
    dp1[0][0] = 1;
    for(int add = 1; add <= MAX; add++){
        for(int i = MAX - add; i >= 0; i--){
            for(int j = 0; j < MAX; j++){
                ::add(dp1[i + add][j + 1], dp1[i][j]);
            }
        }
    }
    for(int i = 1; i <= MAX; i++){
        for(int j = 1; j <= i; j++){
            ll ans = 0;
            for(int k = j; k <= i; k++){
                ans += (dp1[k][j] * get(j, i - k) % MOD);
            }
            ans %= MOD;
            ans *= fac[j];
            dp2[i][j] = (ans % MOD);
        }
    }
    
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", dp2[a][b]);
    }
#ifdef LOCAL
    cout << "---------- " << clock() << endl;
#endif
    
}