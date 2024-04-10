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

//#define __DEBUG
#ifdef __DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 2e5 + 10;

set<pair<int, int> > s[MAX];

ll t[MAX << 4], y1[MAX << 4], y2[MAX << 4];

inline void push1(int v){
    if(y1[v] > 1){
        y1[v << 1] *= y1[v];
        y1[v << 1] %= MOD;
        y1[v << 1 | 1] *= y1[v];
        y1[v << 1 | 1] %= MOD;
        y2[v << 1] *= y1[v];
        y2[v << 1] %= MOD;
        y2[v << 1 | 1] *= y1[v];
        y2[v << 1 | 1] %= MOD;
        t[v << 1] *= y1[v];
        t[v << 1] %= MOD;
        t[v << 1 | 1] *= y1[v];
        t[v << 1 | 1] %= MOD;
        y1[v] = 1;
    }
}

inline void add(ll &a, ll b){
    a += b;
    if(a >= MOD){
        a -= MOD;
    }
}

inline void add_2(ll &a, ll b){
    a += b;
    if(a >= MOD){
        a %= MOD;
    }
}

inline void mult(ll &a, ll b){
    a *= b;
    a %= MOD;
}

inline ll sum(ll a, ll b){
    if(a + b >= MOD){
        return a + b - MOD;
    }else{
        return a + b;
    }
}

inline void push2(int v, int l, int r){
    if(y2[v]){
        push1(v << 1);
        push1(v << 1 | 1);
        add(y2[v << 1], y2[v]);
        add(y2[v << 1 | 1], y2[v]);
        int x = (l + r) >> 1;
        add_2(t[v << 1], y2[v] * (x - l + 1));
        add_2(t[v << 1 | 1], y2[v] * (r - x));
        y2[v] = 0;
    }
}

void add_val(int v, int tl, int tr, int l, int r, int val){
    if(tl > tr){
        return;
    }
    push1(v);
    if(l <= tl && tr <= r){
        add_2(t[v], val * 1LL * (tr - tl + 1));
        add(y2[v], val);
        return;
    }
    if(tr < l | r < tl){
        return;
    }
    push2(v, tl, tr);
    int x = (tl + tr) >> 1;
    add_val(v << 1, tl, x, l, r, val);
    add_val(v << 1 | 1, x + 1, tr, l, r, val);
    t[v] = sum(t[v << 1], t[v << 1 | 1]);
}

void mult_val(int v, int tl, int tr, int l, int r, int val){
    push1(v);
    if(l <= tl && tr <= r){
        mult(t[v], val);
        mult(y1[v], val);
        mult(y2[v], val);
        return;
    }
    if(tr < l | r < tl){
        return;
    }
    push2(v, tl, tr);
    int x = (tl + tr) >> 1;
    mult_val(v << 1, tl, x, l, r, val);
    mult_val(v << 1 | 1, x + 1, tr, l, r, val);
    t[v] = sum(t[v << 1], t[v << 1 | 1]);
}

int n, q;

ll get_sum(int v, int tl, int tr, int l, int r){
    push1(v);
    if(l <= tl && tr <= r){
        return t[v];
    }
    if(tr < l || r < tl){
        return 0;
    }
    push2(v, tl, tr);
    int x = (tl + tr) >> 1;
    return sum(get_sum(v << 1, tl, x, l, r), get_sum(v << 1 | 1, x + 1, tr, l, r));
}

void add_val(int l, int r, int x){
    if(l > r)
        return;
    dbg cout << "# " << l << " " << r << " " << x << endl;
    add_val(1, 1, n, l, r, x);
}

void mult_val(int l, int r, int x){
    if(l > r)
        return;
    dbg cout << "* " << l << " " << r << " " << x << endl;
    mult_val(1, 1, n, l, r, x);
}

void __add(int l, int r, int x){
    for(int i = l; i <= r; ){
        set<pair<int, int> >::iterator it = s[x].lower_bound(make_pair(l, -1));
        if(it == s[x].end() || it->second > r){
            s[x].insert(make_pair(r, l));
            add_val(i, r, 1);
            return;
        }
        int L = it->second;
        int R = it->first;
        add_val(i, L - 1, 1);
        mult_val(max(i, L), min(r, R), 2);
        r = max(r, R);
        l = min(l, L);
        s[x].erase(it);
        i = R + 1;
    }
    s[x].insert(make_pair(r, l));
}

struct solve_long {
    set<int> s[1000];
    ll ans[1000];
    solve_long(){
        for(int i = 0; i < 1000; i++){
            ans[i] = 0;
        }
    }
    void add(int l, int r, int x){
        for(int i = l; i <= r; i++){
            if(s[i].find(x) != s[i].end()){
                ans[i] *= 2;
                ans[i] %= MOD;
            }else{
                s[i].insert(x);
                ans[i]++;
                ans[i] %= MOD;
            }
        }
    }
    ll sum(int l, int r){
        ll ans = 0;
        for(int i = l; i <= r; i++){
            ans += this->ans[i];
        }
        return ans % MOD;
    }
};

int main() {
    
    sync;
    srand((unsigned int) time(NULL));
    cout.precision(10);
    cout << fixed;
    
    cin >> n >> q;
    
    for(int i = 0; i < (MAX << 4); i++){
        y1[i] = 1;
    }
    
     solve_long sl;
    
    for(int i = 1; i <= q; i++){
        int t;
        cin >> t;
        if(t == 1){
            int l, r, x;
            cin >> l >> r >> x;
          dbg  sl.add(l, r, x);
            __add(l, r, x);
            dbg {cout << x << ": ";
            for(auto a : s[x]){
                cout << "[" << a.second << "," << a.first << "]";
            }
                cout << endl;}
        }else{
            int l, r;
            cin >> l >> r;
            cout << get_sum(1, 1, n, l, r) << endl;
            dbg cout << "@@@ " << sl.sum(l, r) << endl;
        }
    }
    
}