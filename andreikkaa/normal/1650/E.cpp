/*
* C++11 code template for contests.
* @author: Andrei Kalendarov
* @e-mail: andreykalendarov@gmail.com
*/

//#define ANDREIKKAA_ALLOCATOR
const int _ML = 450;

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

int stup(int n, int d, vector<int> a) {
    int ans = 0;
    for(int i = 0; i < n; ++i) {

        for(int j = 1; j <= d; ++j) {
            auto b = a;
            b.erase(b.begin() + i);
            b.push_back(j);
            sort(all(b));

            int cur = b[0] - 1;
            for(int k = 1; k < n; ++k) {
                cur = min(cur, b[k] - b[k - 1] - 1);
            }
            ans = max(ans, cur);
        }
    }
    return ans;
}

int clev(int n, int d, vector<int> a) {
    vector<int> lens(n + 1);
    lens[0] = a[0] - 1;
    for(int i = 1; i < n; ++i) {
        lens[i] = a[i] - a[i - 1] - 1;
    }
    lens[n] = d - a.back();

    auto pmn = lens;
    auto pmx = lens;
    auto smn = lens;
    auto smx = lens;
    for(int i = 1; i <= n; ++i) {
        pmn[i] = min(pmn[i], pmn[i - 1]);
        pmx[i] = max(pmx[i], pmx[i - 1]);
    }

    smn.pop_back();
    smx.pop_back();
    for(int i = sz(smn) - 2; i >= 0; --i) {
        smn[i] = min(smn[i], smn[i + 1]);
        smx[i] = max(smx[i], smx[i + 1]);
    }


    int ans = pmn[n - 1];
    for(int i = 0; i < n; ++i) {
        // lens[0:i) + (lens[i] + lens[i + 1] + 1) + lens[i+2;)

        int cur = INT_MAX;
        if(i) {
            cur = min(cur, pmn[i - 1]);
        }
        if(i + 2 < n) {
            cur = min(cur, smn[i + 2]);
        }
        if(i + 1 < n) {
            cur = min(cur, lens[i] + lens[i + 1] + 1);
        }

        int zal = 0;

        // to left
        if(i) {
            zal = max(zal, (pmx[i - 1] - 1) / 2);
        }

        // to right
        if(i + 1 < n) {
            if(i + 2 < sz(smx)) {
                zal = max(zal, (smx[i + 2] - 1) / 2);
            }
            zal = max(zal, d - a.back() - 1);
        }

        // here
        if(i == 0) {
            int sum = lens[0] + lens[1] + 1;
            zal = max(zal, (sum - 1) / 2);
        } else if(i == n - 1) {
            zal = max(zal, d - a[n - 2] - 1);
        } else {
            int sum = lens[i] + lens[i + 1] + 1;
            zal = max(zal, (sum - 1) / 2);
        }

        ans = max(ans, min(zal, cur));
    }
    return ans;
}


inline void _solve() {
#if 1
    int n, d;
    cin >> n >> d;

    vector<int> a(n);
    cin >> a;

    cout << clev(n, d, a) << endl;
    //cout << stup(n, d, a) << endl;
#else
    for(;;) {
        int n = rd() % 3 + 2;
        int d = rd() % 7 + n;

        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            a[i] = rd() % (d - n + 1);
        }
        sort(all(a));
        for(int i = 0; i < n; ++i) {
            a[i] += i + 1;
        }

        int cor = stup(n, d, a);
        int ans = clev(n, d, a);
        if(cor != ans) {
            cout << n << " " << d << endl << a << endl;
            break;
        }
    }
#endif
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