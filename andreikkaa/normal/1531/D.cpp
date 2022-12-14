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

const int N = 100'228;
pair<int, int> t[4 * N][7][2];


pair<int, int> ff(int clr, int lock, int op) {
    if(op == 7) {
        return{clr, 1};
    } else if (op == 8) {
        return{clr, 0};
    } else if (lock) {
        return{clr, 1};
    } else {
        return{op, 0};
    }
}

void do_op(pair<int, int> a[7][2], int op) {
    for(int clr = 0; clr < 7; ++clr) {
        for(int lock = 0; lock < 2; ++lock) {
            a[clr][lock] = ff(clr, lock, op);
        }
    }
}

void mrg_t(pair<int, int> a[7][2], pair<int, int> b[7][2], pair<int, int> c[7][2]) {
    for(int i = 0; i < 7; ++i) {
        for(int j = 0; j < 2; ++j) {
            a[i][j] = c[b[i][j].x][b[i][j].y];
        }
    }
}

void build_t(int v, int l, int r, const vector<int> &a) {
    if(r - l == 1) {
        do_op(t[v], a[l]);
    } else {
        build_t(v << 1, l, (l + r) >> 1, a);
        build_t(v << 1 | 1, (l + r) >> 1, r, a);
        mrg_t(t[v], t[v << 1], t[v << 1 | 1]);
    }
}

void upd_t(int v, int l, int r, int V, int X) {
    if(V < l || r <= V) {
        return;
    }

    if(r - l == 1) {
        do_op(t[v], X);
        return;
    }

    upd_t(v << 1, l, (l + r) >> 1, V, X);
    upd_t(v << 1 | 1, (l + r) >> 1, r, V, X);
    mrg_t(t[v], t[v << 1], t[v << 1 | 1]);
}

map<string, int> clr;


void pr() {
    const int ans = t[1][0][0].x;
    for(auto &i : clr) {
        if(i.y == ans) {
            cout << i.x << endl;
        }
    }
}

void _main_function() {
    int n;
    cin >> n;

    clr["blue"] = 0;
    clr["green"] = 1;
    clr["orange"] = 2;
    clr["red"] = 3;
    clr["violet"] = 4;
    clr["indigo"] = 5;
    clr["yellow"] = 6;
    clr["lock"] = 7;
    clr["unlock"] = 8;

    vector<string> a(n);
    cin >> a;

    vector<int> aa(n);
    for(int i = 0; i < n; ++i) {
        aa[i] = clr[a[i]];
    }

    build_t(1, 0, n, aa);

    int q;
    cin >> q;

    pr();
    for(int i = 0; i < q; ++i) {
        int v;
        string s;
        cin >> v >> s;
        --v;

        upd_t(1, 0, n, v, clr[s]);
        pr();
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