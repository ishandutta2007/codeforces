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

struct zal {
    vector<int> a;
    ll sum = 0;
    int id = 0;
    int sh = 0;
};


void _solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    cin >> a;

    sort(all(a));
    a.erase(a.begin(), a.begin() + n - m);
    n = m;

    vector<zal> b(m);
    int sh = 0;
    for(int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        b[i].a.resize(x);
        cin >> b[i].a;

        b[i].sh = sh;
        b[i].sum = accumulate(all(b[i].a), ll(0));
        b[i].id = i;
        sh += sz(b[i].a);
    }

    sort(all(b), [](const zal &a, const zal &b) {
        return a.sum * sz(b.a) < b.sum * sz(a.a);
    });

    set<int> bad;
    vector<int> mn(m);
    for(int i = 0; i < m; ++i) {
        mn[i] = lower_bound(all(a), (b[i].sum + sz(b[i].a) - 1) / sz(b[i].a)) - a.begin();
        mn[i] = mn[i] - i;
        if(mn[i] >= 0) {
            bad.insert(i);
        }
    }

    vector<bool> ok_nxt(m + 1);
    ok_nxt[m] = true;
    for(int i = m - 1; i >= 0; --i) {
        if(mn[i] > 0) {
            break;
        } else {
            ok_nxt[i] = true;
        }
    }

    vector<bool> ok_prv(m);
    for(int i = 0; i < m; ++i) {
        if(mn[i] > 0) {
            break;
        } else {
            ok_prv[i] = true;
        }
    }

    auto ok_minus_1 = [&bad](int l, int r) {
        auto it = bad.lower_bound(l);
        return it == bad.end() || *it >= r;
    };

    string ans(sh, '0');
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < sz(b[i].a); ++j) {
            ll ns = b[i].sum - b[i].a[j];
            int nss = sz(b[i].a) - 1;
            int pos = lower_bound(all(a), (ns + nss - 1) / nss) - a.begin();

            if(pos > i) {
                if (!ok_nxt[pos + 1]) {
                    continue;
                }

                if (!ok_minus_1(i + 1, pos + 1)) {// [)
                    continue;
                }

                if(i && !ok_prv[i - 1]) {
                    continue;
                }

                ans[b[i].sh + j] = '1';
            } else if(pos == i) {
                if(ok_nxt[pos + 1] && (i == 0 || ok_prv[i - 1])) {
                    ans[b[i].sh + j] = '1';
                }
            } else {
                if(pos && !ok_prv[pos - 1]) {
                    continue;
                }

                if(!ok_nxt[i + 1]) {
                    continue;
                }

                ans[b[i].sh + j] = '1';
            }
        }
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