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

const int MAX = 15e6 + 10;
int t1[MAX], _l[MAX], _r[MAX];
int def[MAX];
ll t3[MAX];
int timer;
const ll INF = 1e18;

const int MAX_N = 4e5 + 10;

int build(int l, int r){
    int now = ++timer;
    t3[now] = INF;
    t1[now] = 2e9;
    def[now] = now;
    if(l == r){
        return now;
    }
    int x = (l + r) >> 1;
    _l[now] = build(l, x);
    _r[now] = build(x + 1, r);
    return now;
}

int upd(int v, int l, int r, int p, int val){
    int now = ++timer;
    def[now] = def[v];
    if(l == r){
        t3[now] = val;
        t1[now] = val;
        return now;
    }
    int x = (l + r) >> 1;
    _l[now] = _l[v];
    _r[now] = _r[v];
    if(p <= x){
        _l[now] = upd(_l[v], l, x, p, val);
        _r[now] = def[_r[now]];
    }else{
        _r[now] = upd(_r[v], x + 1, r, p, val);
    }
    t1[now] = min(t1[_l[now]], t1[_r[now]]);
    t3[now] = min(INF, t3[_l[now]] + t3[_r[now]]);
    return now;
}

int find_smaller_eq(int v, int l, int r, int val){
    //cout << l << " " << r << " " << t1[v] << endl;
    if(t1[v] >= val){
        return -1;
    }
    if(l == r){
        return l;
    }
    int x = (l + r) >> 1;
    int ans = find_smaller_eq(_l[v], l, x, val);
    if(ans == -1){
        ans = find_smaller_eq(_r[v], x + 1, r, val);
    }
    return ans;
}

bool solve(int v, int l, int r, int R, int &ans, ll &have){
    //cout << l << " " << r << " " << t3[v] << " " << R << " " << ans << " " << have << endl;
    if(R < l){
        return true;
    }
    if(r <= R){
        if(t3[v] <= have){
            have -= t3[v];
            ans += (r - l + 1);
            return true;
        }
        if(l == r){
            return false;
        }
    }
    int x = (l + r) >> 1;
    if(solve(_r[v], x + 1, r, R, ans, have)){
        return solve(_l[v], l, x, R, ans, have);
    }
    return false;
}


int root[MAX_N];
int sizes[MAX_N];

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
    
    ms(t1);
    ms(t3);
    ms(def);
    ms(_l);
    ms(_r);
    
    timer = 0;
    
    int q;
    cin >> q;
    
    int n = 4e5 + 2;
    
    root[1] = build(1, n);
    
    root[1] = upd(root[1], 1, n, 1, 0);
    sizes[1] = 1;
    
    ll last = 0;
    
    int sz = 1;
    
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            ll r, w;
            cin >> r >> w;
            r ^= last;
            w ^= last;
            assert(w <= 1e9);
            assert(r <= sz);
            int pos = find_smaller_eq(root[r], 1, n, (int) w);
            if(pos == -1){
                pos = sizes[r] + 1;
            }
            //cout << "$ " << pos << " " << w << endl;
            sizes[sz + 1] = pos;
            root[++sz] = upd(root[r], 1, n, pos, (int) w);
        }else{
            ll r, x;
            cin >> r >> x;
            r ^= last;
            x ^= last;
            //cout << "? " << r << " " << x << " " << sizes[r] << endl;
            assert(r <= sz);
            assert(x <= 1e15);
            int ans = 0;
            solve(root[r], 1, n, sizes[r], ans, x);
            last = ans;
            cout << last << endl;
        }
    }
    
#ifdef LOCAL
    cout << "---------- " << clock() << endl;
#endif
    
}