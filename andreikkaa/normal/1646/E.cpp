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

ll ans = 0;

void sol(const vector<vector<int>> &a, int m) {
    for(int msk = 1; msk < (1 << sz(a)); ++msk) {
        vector<int> cur;
        for(int i = 0; i < sz(a); ++i) {
            if(msk >> i & 1) {
                cur.push_back(i);
            }
        }

        assert(sz(cur));
        if(sz(cur) == 1) {
            ans += m;
            continue;
        }

        ll lcm = 1;
        int mn = INT_MAX;
        for(int i : cur) {
            mn = min(mn, a[i][0]);
            lcm = lcm / gcd(lcm, a[i][0]) * a[i][0];
        }
        ll mnp = lcm / mn;
        int cnt = m / mnp;

        if(sz(cur) & 1) {
            ans += cnt;
        } else {
            ans -= cnt;
        }
    }
}

const int N = 1'000'228;
int lp[N];
vector<int> pr;

bool match(const vector<int> &a, const vector<int> &b) {
    assert(sz(a) == sz(b));
    for(int i = 1; i < sz(a); ++i) {
        if(a[0] * b[i] != a[i] * b[0]) {
            return false;
        }
    }
    return true;
}

void _solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 2; i <= n; ++i) {
        if(lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for(int j = 0; j < sz(pr) && pr[j] <= lp[i] && i * pr[j] <= n; ++j) {
            lp[i * pr[j]] = pr[j];
        }
    }

    map<int, vector<vector<int>>> gr;
    for(int i = 2; i <= n; ++i) {
        int cur = 1;
        vector<int> cnt;
        for(int j = i; j > 1; ) {
            int dv = lp[j];
            cnt.push_back(0);
            while(lp[j] == dv) {
                j /= dv;
                ++cnt.back();
            }
            cur *= dv;
        }
        gr[cur].push_back(cnt);
    }

    for(const auto &g : gr) {
        //cout << g.x << ":" << endl;
        vector<vector<vector<int>>> zals(sz(g.y));
        for(int i = 0; i < sz(g.y); ++i) {
            for(int j = 0; j < i; ++j) {
                if(match(g.y[j], g.y[i])) {
                    zals[j].push_back(g.y[i]);
                    goto ok;
                }
            }
            zals[i].push_back(g.y[i]);
            ok:;
        }
        for(const auto &i : zals) {
            if(!i.empty()) {
                for(const auto &j : i) {
                    //cout << j << "; ";
                }
                //cout << endl;
                sol(i, m);
            }
        }
        //cout << endl;
    }
    cout << ans + 1 << endl;
}

void _main_function() {
    int t = 1;
    //cin >> t;

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