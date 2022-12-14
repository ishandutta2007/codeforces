/*
* C++11 code template for contests.
* @author: Andrei Kalendarov
* @e-mail: andreykalendarov@gmail.com
*/

//#define ANDREIKKAA_ALLOCATOR
const int _ML = 400;

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
template<class T, size_t N> inline ostream &operator<< (ostream &, const array<T, N> &);
template<class T, size_t N> inline ostream &operator>> (ostream &, array<T, N> &);

/* ________ CODE ________ */

const int N = 10'002;
int f[N];
int fi[N];

int M;

int mul(int a, int b) {
    return int(ll(a) * b % M);
}

int bp(int a, int b) {
    int r = 1;
    while(b) {
        if(b & 1) {
            r = mul(r, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return r;
}

void addeq(int &a, int b) {
    a = (a + b) % M;
}

int inv(int a) {
    return bp(a, M - 2);
}

int cnk(int n, int k) {
    assert(0 <= k && k <= n);
    return mul(f[n], mul(fi[k], fi[n - k]));
}

int ways(int a, int b) {
    return cnk(a + b, a);
}

void _solve(int _t) {
    int n;
    cin >> n >> M;

    f[0] = fi[0] = 1;
    for(int i = 1; i < N; ++i) {
        f[i] = mul(f[i - 1], i);
        fi[i] = inv(f[i]);
    }


    int ans = 0;
    vector<int> cc(n);
    for(int sum = n / 2 - 1; sum <= 2 * (n / 2 - 1); ++sum) {
            int slen = sum;
            int cnt = n / 2 - (sum - n / 2 + 1);
            cc[slen] += cnt;
            int dw = n - slen - 3;
            if(dw < 0) {
                assert(dw == -1);
                assert(n % 2 == 0);
                //assert(i == n / 2 - 1 && j == n / 2 - 1);
                dw = 0;
            }

            int cur = 0;
            for(int k = 0; k <= dw; ++k) {
                addeq(cur, mul(mul(f[k], cnk(dw, k)), ways(k, slen)));
            }
            addeq(ans, mul(cnt, mul(f[slen], cur)));
        }

    for(int i = 0; i < n; ++i) {
        //cout << i << " " << cc[i] << endl;
    }

    cout << mul(n, ans) << endl;
}

void _main_function() {
    int t = 1;
    //cin >> t;

    for(int i = 0; i < t; ++i) {
        _solve(i);
    }
}

/* ________ CODE ________ */

int main() {
#if defined(ANDREIKKAA)
    auto _start = chrono::steady_clock::now();
#endif
    if (_inpf[0] != '\0') assert(freopen(_inpf, "r", stdin) != nullptr);
    if (_outf[0] != '\0') assert(freopen(_outf, "w", stdout) != nullptr);
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cout << setprecision(20);
    cout << fixed;

    _main_function();
#if defined(ANDREIKKAA)
    cout.flush();
    cerr << "Time: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - _start).count() << "ms" << endl;
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
    _out << *_v.cbegin();
    for (auto _it = ++_v.cbegin(); _it != _v.cend(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline istream &operator>> (istream &_in, vector<T> &_v) {
    for (auto &_i : _v) { _in >> _i; }
    return _in;
}
template<class T> inline ostream &operator<< (ostream &_out, const set<T> &_s) {
    if (_s.empty()) { return _out; }
    _out << *_s.cbegin();
    for (auto _it = ++_s.cbegin(); _it != _s.cend(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline ostream &operator<< (ostream &_out, const multiset<T> &_s) {
    if (_s.empty()) { return _out; }
    _out << *_s.cbegin();
    for (auto _it = ++_s.cbegin(); _it != _s.cend(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline ostream &operator<< (ostream &_out, const unordered_set<T> &_s) {
    if (_s.empty()) { return _out; }
    _out << *_s.cbegin();
    for (auto _it = ++_s.cbegin(); _it != _s.cend(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline ostream &operator<< (ostream &_out, const unordered_multiset<T> &_s) {
    if (_s.empty()) { return _out; }
    _out << *_s.cbegin();
    for (auto _it = ++_s.cbegin(); _it != _s.cend(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T, class U> inline ostream &operator<< (ostream &_out, const map<T, U> &_m) {
    if (_m.empty()) { return _out; }
    _out << '(' << _m.cbegin()->x << ": " << _m.cbegin()->y << ')';
    for (auto _it = ++_m.cbegin(); _it != _m.cend(); ++_it) { _out << ", (" << _it->x << ": " << _it->y << ')'; }
    return _out;
}
template<class T, class U> inline ostream &operator<< (ostream &_out, const unordered_map<T, U> &_m) {
    if (_m.empty()) { return _out; }
    _out << '(' << _m.cbegin()->x << ": " << _m.cbegin()->y << ')';
    for (auto _it = ++_m.cbegin(); _it != _m.cend(); ++_it) { _out << ", (" << _it->x << ": " << _it->y << ')'; }
    return _out;
}

template<class T, size_t N> inline ostream &operator<< (ostream &_out, const array<T, N> &_a) {
    if (_a.empty()) { return _out; }
    _out << *_a.cbegin();
    auto _it = _a.cbegin();
    for (++_it; _it != _a.cend(); ++_it) { _out << ' ' << *_it; }
    return _out;
}

template<class T, size_t N> inline istream &operator>> (istream &_in, array<T, N> &_a) {
    for(auto &i : _a) { _in >> _a[i]; }
    return _in;
}