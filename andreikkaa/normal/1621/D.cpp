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

const int N = 505;
ll dp[N][N];
ll psr[N][N];
ll psc[N][N];

ll f(const vector<vector<int>> &a) {
    int n = sz(a) / 2;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            assert(a[i][j] == 0);
        }
    }

    for(int i = 0; i < 2 * n; ++i) {
        for(int j = 0; j < 2 * n; ++j) {
            //cout << a[i][j];
            psr[i][j] = a[i][j];
            psc[j][i] = a[i][j];
            if(j) {
                psr[i][j] += psr[i][j - 1];
            }
            if(i) {
                psc[j][i] += psc[j][i - 1];
            }
        }
        //cout << endl;
    }

    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= n; ++j) {
            dp[i][j] = LLONG_MAX;
        }
    }

    auto sum_row = [](int x, int y1, int y2) {
        return psr[x][y2 - 1] - (y1 == 0 ? 0 : psr[x][y1 - 1]);
    };

    auto sum_col = [](int y, int x1, int x2) {
        return psc[y][x2 - 1] - (x1 == 0 ? 0 : psc[y][x1 - 1]);
    };

    dp[0][0] = 0;
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= n; ++j) {
            if(i) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + sum_row(i + n - 1, j, j + n));
            }
            if(j) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + sum_col(j + n - 1, i, i + n));
            }
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }

    return dp[n][n];
}

void dw_to_up(vector<vector<int>> &a) {
    for(int i = 0; i < sz(a) / 2; ++i) {
        for(int j = 0; j < sz(a); ++j) {
            swap(a[i][j], a[i + sz(a) / 2][j]);
        }
    }
}

void rg_to_lf(vector<vector<int>> &a) {
    for(int i = 0; i < sz(a); ++i) {
        for(int j = 0; j < sz(a) / 2; ++j) {
            swap(a[i][j], a[i][j + sz(a) / 2]);
        }
    }
}

void hor(vector<vector<int>> &a) {
    for(int i = 0; i < sz(a) / 2; ++i) {
        for(int j = 0; j < sz(a); ++j) {
            swap(a[i][j], a[sz(a) - i - 1][j]);
        }
    }
}

void ver(vector<vector<int>> &a) {
    for(int i = 0; i < sz(a); ++i) {
        for(int j = 0; j < sz(a) / 2; ++j) {
            swap(a[i][j], a[i][sz(a) - j - 1]);
        }
    }
}

void _solve() {
    int n;
    cin >> n;

    vector<vector<int>> a(2 * n, vector<int>(2 * n));
    cin >> a;

    ll sum = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            sum += a[i + n][j + n];
        }
    }


    ll mn = LLONG_MAX;
    int dx = 0;
    int dy = n;
    for(int _ = 0; _ < 2; ++_) {
        for (int i : {0, n - 1}) {
            for (int j : {0, n - 1}) {
                mn = min(mn, (ll)a[i + dx][j + dy]);
            }
        }
        swap(dx, dy);
    }

    cout << sum + mn << endl;

    /*ll ans = f(a);

    dw_to_up(a);
    hor(a);
    ans = min(ans, f(a));

    //cout << f(a) << endl;

    rg_to_lf(a);
    ver(a);
    ans = min(ans, f(a));
    //cout << f(a) << endl;

    dw_to_up(a);
    hor(a);
    ans = min(ans, f(a));
    //cout << f(a) << endl;

    cout << ans << endl;*/
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