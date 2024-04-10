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

const int A = 1'000'228;
constexpr int M = 1'000'000'007;
int cnt[A];
int p;

inline int mul(int a, int b) {
    return int(ll(a) * b % M);
}

inline int add(int a, int b) {
    return (a + b) % M;
}

inline int sub(int a, int b) {
    return (a + M - b) % M;
}

inline int pw(int a, int b) {
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

inline bool can_grab(int pos, ll val) {
    assert(val >= 0);
    if(pos < 0) {
        return false;
    }

    if(val >= A) {
        return false;
    }

    if(cnt[pos] >= val) {
        return true;
    }

    const ll nxt = (val - cnt[pos]) * p;
    if(can_grab(pos - 1, nxt)) {
        assert(cnt[pos - 1] >= nxt);
        cnt[pos - 1] -= nxt;
        cnt[pos] = val;
        return true;
    } else {
        return false;
    }
}

inline void retu(const vector<int> &a) {
    for(int i : a) {
        cnt[i] = 0;
    }
}

void solve() {
    int n;
    cin >> n >> p;

    vector<int> poss(n);
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        poss[i] = x;
        ++cnt[x];
    }

    sort(all(poss));
    poss.erase(unique(all(poss)), poss.end());
    reverse(all(poss));

    if(p == 1) {
        if(n & 1) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        retu(poss);
        return;
    }

    for(int i : poss) {
        if(cnt[i] == 0) {
            continue;
        }

        if(cnt[i] % 2 == 0) {
            cnt[i] = 0;
            continue;
        }

        if(can_grab(i - 1, p)) {
            assert(cnt[i - 1] >= p);
            cnt[i - 1] -= p;
            ++cnt[i];
            cnt[i] = 0;
            continue;
        }

        int ans = pw(p, i);
        for(int j : poss) {
            if(j >= i) {
                continue;
            }
            if(cnt[j]) {
                ans = sub(ans, mul(cnt[j], pw(p, j)));
            }
        }
        cout << ans << endl;
        retu(poss);
        return;
    }

    cout << 0 << endl;
    retu(poss);
}

inline void _main_function() {
    int t;
    cin >> t;

    while(t--) {
        solve();
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