/*
* C++11 code template for contests.
* @author: Andrei Kalendarov
* @e-mail: andreykalendarov@gmail.com
*/

//#define ANDREIKKAA_ALLOCATOR
const int _ML = 500;

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
template<class T, size_t N> inline ostream &operator<< (ostream &, const array<T, N> &);
template<class T, size_t N> inline ostream &operator>> (ostream &, array<T, N> &);

/* ________ CODE ________ */


void _solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<pair<char, int>> a;
    for(int i = 0; i < sz(s); ) {
        int j;
        for(j = i; j < sz(s) && s[j] == s[i]; ++j);
        a.push_back({s[i], j - i});
        i = j;
    }

    vector<pair<int, int>> suf(sz(a) + 1);
    for(int i = sz(a) - 1; i >= 0; --i) {
        suf[i] = suf[i + 1];
        if(a[i].x == 'R') {
            suf[i].y += a[i].y;
        } else {
            assert(a[i].x == 'D');
            suf[i].x += a[i].y;
        }
    }

    int x1 = 0, x2 = 1, y1 = 0, y2 = 1;
    ll ans = 1;
    for(int ii = 0; ii < sz(a); ++ii) {
        const auto &i = a[ii];

        int nx1, nx2, ny1, ny2;
        if(i.x == 'R') {
            nx1 = x1;
            nx2 = x2;

            ny1 = y1 + i.y;
            ny2 = y2 + i.y;
            ny2 = n - suf[ii + 1].y;
        } else {
            assert(i.x == 'D');
            ny1 = y1;
            ny2 = y2;

            nx1 = x1 + i.y;
            nx2 = x2 + i.y;
            nx2 = n - suf[ii + 1].x;
        }

        assert(nx1 < nx2);
        assert(ny1 < ny2);

        ans += ll(nx2 - x1) * (ny2 - y1);

        ans -= ll(x2 - x1) * (y2 - y1);

        x1 = nx1;
        y1 = ny1;
        x2 = nx2;
        y2 = ny2;
    }

    cout << ans << endl;
}

void _main_function() {
    int t = 1;
    cin >> t;

    for(int i = 0; i < t; ++i) {
        _solve();
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
    cout << fixed;

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

template<class T, size_t N> inline ostream &operator<< (ostream &_out, const array<T, N> &a) {
    for(int i = 0; i < N; ++i) {
        _out << a[i];
        if(i + 1 < N) {
            _out << ' ';
        }
    }
    return _out;
}
template<class T, size_t N> inline istream &operator>> (istream &_in, array<T, N> &a) {
    for(int i = 0; i < N; ++i) {
        _in >> a[i];
    }
    return _in;
}