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

#else
#pragma GCC optimize("O3,no-stack-protector")
#endif

#include <bits/stdc++.h>

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
typedef long long ll;
typedef double ld;
const ld PI = 3.14159265358979323846;
mt19937 rd(228);
#if defined(ANDREIKKAA_ALLOCATOR)
char _mem[_ML * 1024 * 1024];
size_t _ptr = 0;
inline void* operator new (size_t _x) { _ptr += _x; assert(_ptr < _ML * 1024 * 1024); return _mem + _ptr - _x; }
inline void operator delete (void*) { }
#endif

template<class T, class U>
inline ostream &operator<<(ostream &, const pair<T, U> &);

template<class T, class U>
inline istream &operator>>(istream &, pair<T, U> &);

template<class T>
inline ostream &operator<<(ostream &, const vector<T> &);

template<class T>
inline istream &operator>>(istream &, vector<T> &);

template<class T>
inline ostream &operator<<(ostream &, const set<T> &);

template<class T>
inline ostream &operator<<(ostream &, const multiset<T> &);

template<class T>
inline ostream &operator<<(ostream &, const unordered_set<T> &);

template<class T>
inline ostream &operator<<(ostream &, const unordered_multiset<T> &);

template<class T, class U>
inline ostream &operator<<(ostream &, const map<T, U> &);

template<class T, class U>
inline ostream &operator<<(ostream &, const unordered_map<T, U> &);

/* ________ CODE ________ */

const int N = 1000 * 1000 + 228;
int dp[N][4];

inline void _main_function() {
    int n;
    cin >> n;

    char inv = ('0' ^ '1');

    string s, t;
    cin >> s >> t;

    if(n == 1) {
        if(s[0] == t[0]) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
        return;
    }

    s += "00";
    t += "00";
    n += 1;
    const int INF = 1000 * 1000 + 229;
    fill((int*)dp, (int*)dp + 4 * N, INF);
    dp[2][((s[0] - '0') << 1) | (s[1] - '0')] = 0;

    for(int i = 2; i <= n; ++i) {
        for(int j = 0; j <= 3; ++j) {
            if(dp[i][j] == INF) {
                continue;
            }
           //cout << i << " " << j << " " << dp[i][j] << endl;


            if(((j & 2) >> 1) == (t[i - 2] - '0')) {
                dp[i + 1][((j & 1) << 1) | (s[i] - '0')] = min(
                    dp[i + 1][((j & 1) << 1) | (s[i] - '0')],
                    dp[i][j]);
             //cout << "fuck" << endl;
            } else {
                // inv
                dp[i + 1][((j & 1) << 1) | (s[i] - '0')] = min(
                    dp[i + 1][((j & 1) << 1) | (s[i] - '0')],
                    dp[i][j] + 1
                    );
               //cout << i + 1 << " " << (((j & 1) << 1) | (s[i] - '0')) << " = " << dp[i + 1][((j & 1) << 1) | (s[i] - '0')] << endl;

                // sw neigh
                if(((j & 1) != ((j & 2) >> 1))) {
                    dp[i + 1][(j & 2) | (s[i] - '0')] = min(
                        dp[i + 1][(j & 2) | (s[i] - '0')],
                        dp[i][j] + 1
                        );
                }

                //cout << i + 1 << " " << ((j & 2) | (s[i] - '0')) << " = " << dp[i + 1][(j & 2) | (s[i] - '0')] << endl;

                // sw 2
                if(((j & 2) >> 1) != s[i] - '0') {
                    dp[i + 1][((j & 1) << 1) | ((j & 2) >> 1)] = min(
                        dp[i + 1][((j & 1) << 1) | ((j & 2) >> 1)],
                        dp[i][j] + 2);
                }

                //cout << i + 1 << " " << (((j & 1) << 1) | ((j & 2) >> 1)) << " = " << dp[i + 1][((j & 1) << 1) | ((j & 2) >> 1)] << endl;

            }
        }
    }

    cout << dp[n + 1][((t[n - 1] - '0') << 1)] << endl;
}

/* ________ CODE ________ */

int main() {
#if defined(ANDREIKKAA)
    time_t _start = clock();
#endif
    if (_inpf[0] != '\0')
        assert(freopen(_inpf, "r", stdin) != nullptr);
    if (_outf[0] != '\0')
        assert(freopen(_outf, "w", stdout) != nullptr);
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cout << setprecision(20);
    //cout << fixed;

    _main_function();
#if defined(ANDREIKKAA)
    cout << "Time: " << (clock() - _start) / (ld)CLOCKS_PER_SEC << endl;
#endif
}

template<class T, class U>
inline ostream &operator<<(ostream &_out, const pair<T, U> &_p) {
    _out << _p.x << ' ' << _p.y;
    return _out;
}

template<class T, class U>
inline istream &operator>>(istream &_in, pair<T, U> &_p) {
    _in >> _p.x >> _p.y;
    return _in;
}

template<class T>
inline ostream &operator<<(ostream &_out, const vector<T> &_v) {
    if (_v.empty()) {
        return _out;
    }
    _out << *_v.begin();
    for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) {
        _out << ' ' << *_it;
    }
    return _out;
}

template<class T>
inline istream &operator>>(istream &_in, vector<T> &_v) {
    for (auto &_i : _v) {
        _in >> _i;
    }
    return _in;
}

template<class T>
inline ostream &operator<<(ostream &_out, const set<T> &_s) {
    if (_s.empty()) {
        return _out;
    }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) {
        _out << ' ' << *_it;
    }
    return _out;
}

template<class T>
inline ostream &operator<<(ostream &_out, const multiset<T> &_s) {
    if (_s.empty()) {
        return _out;
    }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) {
        _out << ' ' << *_it;
    }
    return _out;
}

template<class T>
inline ostream &operator<<(ostream &_out, const unordered_set<T> &_s) {
    if (_s.empty()) {
        return _out;
    }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) {
        _out << ' ' << *_it;
    }
    return _out;
}

template<class T>
inline ostream &operator<<(ostream &_out, const unordered_multiset<T> &_s) {
    if (_s.empty()) {
        return _out;
    }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) {
        _out << ' ' << *_it;
    }
    return _out;
}

template<class T, class U>
inline ostream &operator<<(ostream &_out, const map<T, U> &_m) {
    if (_m.empty()) {
        return _out;
    }
    _out << '(' << _m.begin()->x << ": " << _m.begin()->y << ')';
    for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) {
        _out << ", (" << _it->x << ": " << _it->y << ')';
    }
    return _out;
}

template<class T, class U>
inline ostream &operator<<(ostream &_out, const unordered_map<T, U> &_m) {
    if (_m.empty()) {
        return _out;
    }
    _out << '(' << _m.begin()->x << ": " << _m.begin()->y << ')';
    for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) {
        _out << ", (" << _it->x << ": " << _it->y << ')';
    }
    return _out;
}