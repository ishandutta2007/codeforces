/*
* C++11 code template for contests.
* @author: Andrei Kalendarov
* @e-mail: andreykalendarov@gmail.com
*/

//#define ANDREIKKAA_ALLOCATOR
const int _ML = 228;

const char _inpf[] =
#if defined(ANDREIKKAA)
        "input.txt"
#else
""
#endif
;
const char _outf[] =
#if defined(ANDREIKKAA)
        ""
#else
""
#endif
;

#if defined(ANDREIKKAA)
#undef NDEBUG
#else
#pragma GCC optimize("O3,no-stack-protector")
#endif
#include "bits/stdc++.h"
#if !defined(ANDREIKKAA)
#define endl '\n'
#endif
#define x first
#define y second
using namespace std;
#define rand abcdefghijklmnopqrstuvwxyz
#define random_shuffle abcdefghijklmnopqrstuvwxyz
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using ll = long long;
using ld = double;
const ld PI = 3.14159265358979323846;
mt19937 rd(228);
#if defined(ANDREIKKAA_ALLOCATOR)
char _mem[_ML * 1024 * 1024];
size_t _ptr = 0;
inline void* operator new (size_t _x) { _ptr += _x; assert(_ptr < _ML * 1024 * 1024); return _mem + _ptr - _x; }
inline void operator delete (void*) { }
#endif
template<class T, class U> inline ostream &operator<< (ostream &, const pair<T, U> &);
template<class T, class U> inline istream &operator>> (istream &, pair<T, U> &);
template<class T> inline ostream &operator<< (ostream &, const vector<T> &);
template<class T> inline istream &operator>> (istream &, vector<T> &);
template<class T> inline ostream &operator<< (ostream &, const set<T> &);
template<class T> inline ostream &operator<< (ostream &, const multiset<T> &);
template<class T> inline ostream &operator<< (ostream &, const unordered_set<T> &);
template<class T> inline ostream &operator<< (ostream &, const unordered_multiset<T> &);
template<class T, class U> inline ostream &operator<< (ostream &, const map<T, U> &);
template<class T, class U> inline ostream &operator<< (ostream &, const unordered_map<T, U> &);

/* ________ CODE ________ */

struct node {
    int ans = 0;
    node *l = nullptr;
    node *r = nullptr;
};
const int MEM = 1'500'000;
node mem[MEM];
int ptr = 0;

node *new_node(int ans, node *l, node *r) {
    mem[ptr] = {ans, l, r};
    return mem + ptr++;
}

node *upd_t(node *t, int l, int r, int P, int X) {
    if(P < l || r <= P) {
        return t;
    }

    if(t == nullptr) {
        t = new_node(X, nullptr, nullptr);
    } else {
        t = new_node(t->ans + X, t->l, t->r);
    }

    if(r - l == 1) {
        return t;
    }

    t->l = upd_t(t->l, l, (l + r) >> 1, P, X);
    t->r = upd_t(t->r, (l + r) >> 1, r, P, X);
    return t;
}

int get_t(node *t, int l, int r, int L, int R) {
    if(t == nullptr) {
        return 0;
    }

    if(R <= l || r <= L) {
        return 0;
    }

    if(L <= l && r <= R) {
        return t->ans;
    }

    return get_t(t->l, l, (l + r) >> 1, L, R) + get_t(t->r, (l + r) >> 1, r, L, R);
}

const int N = 35228;
const int K = 102;
int dp[K][N];
int a[N];
node *t[N];
int nxt[N];

int n;

void f(int k, int l, int r, int lft, int rgt) {
    if(r - l <= 0) {
        return;
    }
    const int m = (l + r) / 2;

    dp[k][m] = INT_MAX;
    int pp = -1;
    const int to = min(rgt, m);

    int value = get_t(t[m], 1, n + 1, to, m + 1);
    for(int pos = to - 1; pos >= lft; --pos) {
        const int now = dp[k - 1][pos] + value;
        if(now < dp[k][m]) {
            dp[k][m] = now;
            pp = pos;
        }
        if(pos < nxt[pos] && nxt[pos] <= m) {
            value += nxt[pos] - pos;
        }
    }

    if(r - l == 1) {
        return;
    }

    f(k, l, m, lft, pp + 1);
    f(k, m + 1, r, pp, rgt);
}

void solve() {
    int k;
    cin >> n >> k;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    map<int, int> lst;
    for(int i = 1; i <= n; ++i) {
        t[i] = t[i - 1];
        if(lst.count(a[i])) {
            nxt[lst[a[i]]] = i;
            t[i] = upd_t(t[i], 1, n + 1, lst[a[i]], i - lst[a[i]]);
        }
        dp[1][i] = get_t(t[i], 1, n + 1, 1, i + 1);
        lst[a[i]] = i;
    }

    for(int i = 2; i <= k; ++i) {
        f(i, 1, n + 1, 0, n + 1);
    }

    /*for(int i = 1; i <= k; ++i) {
        for(int j = 0; j <= n; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << dp[k][n] << endl;
}

void _main_function() {
    int t = 1;
    //cin >> t;

    for(int i = 0; i < t; ++i) {
        solve();
    }
}


/* ________ CODE ________ */

int main() {
#if defined(ANDREIKKAA)
    time_t _start = clock();
#endif
    if (_inpf[0] != '\0') assert(freopen(_inpf, "r", stdin) != nullptr);
    if (_outf[0] != '\0') assert(freopen(_outf, "w", stdout) != nullptr);
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cout << setprecision(20);
    //cout << fixed;

    _main_function();
#if defined(ANDREIKKAA)
    cout << "Time: " << (clock() - _start) / (ld)CLOCKS_PER_SEC << endl;
#endif
}

template<class T, class U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p) {
    _out << _p.x << ' ' << _p.y;
    return _out;
}
template<class T, class U> inline istream &operator>> (istream &_in, pair<T, U> &_p) {
    _in >> _p.x >> _p.y;
    return _in;
}
template<class T> inline ostream &operator<< (ostream &_out, const vector<T> &_v) {
    if (_v.empty()) { return _out; }
    _out << *_v.begin();
    for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline istream &operator>> (istream &_in, vector<T> &_v) {
    for (auto &_i : _v) { _in >> _i; }
    return _in;
}
template<class T> inline ostream &operator<< (ostream &_out, const set<T> &_s) {
    if (_s.empty()) { return _out; }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline ostream &operator<< (ostream &_out, const multiset<T> &_s) {
    if (_s.empty()) { return _out; }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline ostream &operator<< (ostream &_out, const unordered_set<T> &_s) {
    if (_s.empty()) { return _out; }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline ostream &operator<< (ostream &_out, const unordered_multiset<T> &_s) {
    if (_s.empty()) { return _out; }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T, class U> inline ostream &operator<< (ostream &_out, const map<T, U> &_m) {
    if (_m.empty()) { return _out; }
    _out << '(' << _m.begin()->x << ": " << _m.begin()->y << ')';
    for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->x << ": " << _it->y << ')'; }
    return _out;
}
template<class T, class U> inline ostream &operator<< (ostream &_out, const unordered_map<T, U> &_m) {
    if (_m.empty()) { return _out; }
    _out << '(' << _m.begin()->x << ": " << _m.begin()->y << ')';
    for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->x << ": " << _it->y << ')'; }
    return _out;
}