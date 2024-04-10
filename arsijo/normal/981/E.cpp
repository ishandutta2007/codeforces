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

const int MAX = 1e5;

bitset<10001> dp[MAX];
bitset<10001> ans;

vector<int> vec[MAX];

void add(int v, int tl, int tr, int l, int r, int val){
    if(l <= tl && tr <= r){
        vec[v].push_back(val);
        return;
    }
    if(tr < l || r < tl){
        return;
    }
    int x = (tl + tr) >> 1;
    add(v << 1, tl, x, l, r, val);
    add(v << 1 | 1, x + 1, tr, l, r, val);
}

void build(int v, int l, int r){
    for(int a : vec[v]){
        dp[0] = dp[v];
        dp[0] <<= a;
        dp[v] |= dp[0];
    }
    if(l == r){
        ans |= dp[v];
        return;
    }
    int x = (l + r) >> 1;
    dp[v << 1] |= dp[v];
    dp[v << 1 | 1] |= dp[v];
    build(v << 1, l, x);
    build(v << 1 | 1, x + 1, r);
}

int main() {
    sync;
    srand((unsigned int) time(NULL));
    cout.precision(10);
    cout << fixed;
    
    int n, m;
    cin >> n >> m;
    
    while(m--){
        int l, r, x;
        cin >> l >> r >> x;
        add(1, 1, n, l, r, x);
    }
    
    dp[1][0] = 1;
    
    build(1, 1, n);
    
    vector<int> v;
    for(int i = 1; i <= n; i++){
        if(ans[i]){
            v.push_back(i);
        }
    }
    
    cout << v.size() << endl;
    for(int a : v){
        cout << a << " ";
    }
    
}