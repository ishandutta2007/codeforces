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

const int N = 150;
const int PR = 50;
const int LE = 15;
int dp[N][3];

int f(const set<int> &st) {
    for(int i = 0; ; ++i) {
        if(!st.count(i)) {
            return i;
        }
    }
}

void sol(int tst = 0) {
    int n, a, b, c;
    //n = 0;
    //a = tst % 5 + 1;
    //b = tst / 5 % 5 + 1;
    //c = tst / 25 % 5 + 1;
    cin >> n >> a >> b >> c;


    for(int i = 1; i < N; ++i) {
        set<int> st;
        st.insert(i - a < 0 ? 0 : dp[i - a][0]);
        st.insert(i - b < 0 ? 0 : dp[i - b][1]);
        st.insert(i - c < 0 ? 0 : dp[i - c][2]);
        dp[i][0] = f(st);

        st.clear();
        st.insert(i - a < 0 ? 0 : dp[i - a][0]);
        st.insert(i - c < 0 ? 0 : dp[i - c][2]);
        dp[i][1] = f(st);

        st.clear();
        st.insert(i - a < 0 ? 0 : dp[i - a][0]);
        st.insert(i - b < 0 ? 0 : dp[i - b][1]);
        dp[i][2] = f(st);

        //cout << i << ": " << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] << endl;
    }

    int pre[3] = {-1};
    int len[3] = {-1};

    for(int pos = 0; pos < 3; ++pos) {
        for (int pr = 0; pr <= PR; ++pr) {
            for (int le = 1; le <= LE && pr + 2 * le <= N; ++le) {
                for (int i = pr; i + le < N; ++i) {
                    if (dp[i][pos] != dp[i + le][pos]) {
                        goto nahui;
                    }
                }
                pre[pos] = pr;
                len[pos] = le;
                goto ok;
                nahui:;
            }
        }
        ok:;
        //cout << pre[pos] << " " << len[pos] << endl;
        assert(pre[pos] != -1);
    }

    auto f = [&pre, &len](ll n, int pos) {
        if(n < 0) {
            return ll(0);
        }

        if(n < pre[pos]) {
            return n;
        } else {
            return (n - pre[pos]) % len[pos] + pre[pos];
        }
    };

    vector<ll> arr(n);
    cin >> arr;

    int val = 0;
    for(int i = 0; i < n; ++i) {
        val ^= dp[f(arr[i], 0)][0];
    }

    int cc = 0;
    for(int i= 0; i < n; ++i) {
        if((val ^ dp[f(arr[i], 0)][0] ^ dp[f(arr[i] - a, 0)][0]) == 0) {
            ++cc;
        }

        if((val ^ dp[f(arr[i], 0)][0] ^ dp[f(arr[i] - b, 1)][1]) == 0) {
            ++cc;
        }

        if((val ^ dp[f(arr[i], 0)][0] ^ dp[f(arr[i] - c, 2)][2]) == 0) {
            ++cc;
        }
    }
    cout << cc << endl;
}

inline void _main_function() {
    int t = 5 * 5 * 5;
    cin >> t;

    for(int i = 0; i < t; ++i) {
        sol(i);
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