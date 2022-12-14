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
using ld = long double;
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
    ll sum;
    int mn;
    int mx;
    int push;
};

const int N = 200'228;
node t[4 * N];

void mrg_t(node &a, const node &b, const node &c) {
    a.sum = b.sum + c.sum;
    a.mn = c.mn;
    a.mx = b.mx;
    assert(b.push == -1 && c.push == -1 && a.push == -1);
}

void push_t(int v, int l, int r) {
    if(t[v].push == -1) {
        return;
    }

    t[v].sum = ll(t[v].push) * (r - l);
    t[v].mn = t[v].mx = t[v].push;

    if(r - l > 1) {
        t[v << 1].push = t[v].push;
        t[v << 1 | 1].push = t[v].push;
    }
    t[v].push = -1;
}

void build_t(int v, int l, int r, const vector<int> &a) {
    if(r - l == 1) {
        t[v] = {a[l], a[l], a[l], -1};
    } else {
        build_t(v << 1, l, (l + r) >> 1, a);
        build_t(v << 1 | 1, (l + r) >> 1, r, a);
        t[v].push = -1;
        mrg_t(t[v], t[v << 1], t[v << 1 | 1]);
    }
}

int upp_t(int v, int l, int r, int X) {
    push_t(v, l, r);
    if(t[v].mn >= X) {
        return INT_MAX / 3;
    }

    if(t[v].mx < X) {
        return l;
    }

    auto val = upp_t(v << 1, l, (l + r) >> 1, X);
    if(val != INT_MAX / 3) {
        return val;
    }

    return upp_t(v << 1 | 1, (l + r) >> 1, r, X);
}

void set_t(int v, int l, int r, int L, int R, int X) {
    push_t(v, l, r);

    if(R <= l || r <= L) {
        return;
    }

    if(L <= l && r <= R) {
        t[v].push = X;
        push_t(v, l, r);
        return;
    }

    set_t(v << 1, l, (l + r) >> 1, L, R, X);
    set_t(v << 1 | 1, (l + r) >> 1, r, L, R, X);
    mrg_t(t[v], t[v << 1], t[v << 1 | 1]);
}

int ans = 0;

int get_t(int v, int l, int r, int X, int Y) {
    push_t(v, l, r);
    if(r <= X) {
        return Y;
    }

    if(t[v].mn > Y) {
        return Y;
    }

    if(X <= l && t[v].sum <= Y) {
        ans += r - l;
        return Y - t[v].sum;
    }

    Y = get_t(v << 1, l, (l + r) >> 1, X, Y);
    return get_t(v << 1 | 1, (l + r) >> 1, r, X, Y);
}

inline void _main_function() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    cin >> a;

    build_t(1, 0, n, a);

    for(int i = 0; i < q; ++i) {
        int t, x, y;
        cin >> t >> x >> y;
        --x;

        if(t == 1) {
            //cout << "upp: " << upp_t(1, 0, n, y) << " " << x + 1 << " mx= " << y << endl;
            set_t(1, 0, n, upp_t(1, 0, n, y), x + 1, y);
        } else {
            ans = 0;
            get_t(1, 0, n, x, y);
            cout << ans << endl;
        }
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