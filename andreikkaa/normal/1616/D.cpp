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

const int N = 50'228;
int t[4 * N];

void set_t(int v, int l, int r, int P, int X) {
    if(P < l || r <= P) {
        return;
    }

    if(r - l == 1) {
        t[v] = X;
        return;
    }

    set_t(v << 1, l, (l + r) >> 1, P, X);
    set_t(v << 1 | 1, (l + r) >> 1, r, P, X);
    t[v] = min(t[v << 1], t[v << 1 | 1]);
}

int get_t(int v, int l, int r, int L, int R) {
    if(R <= l || r <= L) {
        return INT_MAX;
    }

    if(L <= l && r <= R) {
        return t[v];
    }

    return min(
            get_t(v << 1, l, (l + r) >> 1, L, R),
            get_t(v << 1 | 1, (l + r) >> 1, r, L, R)
            );
}

const int L = 18;
int sp[L][N];
int lg2[N];

int get_max(int l, int r) {
    assert(l < r);
    int gg = lg2[r - l];

    return max(sp[gg][l], sp[gg][r - (1 << gg)]);
}


void _solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    cin >> a;

    int x;
    cin >> x;

    for(auto &i : a) {
        i -= x;
    }

    vector<ll> ps(n);
    partial_sum(all(a), ps.begin());

    vector<int> mx(n);
    mx[0] = -1;

    set<pair<ll, int>> st;
    st.insert({0, -1});
    for(int i = 1; i < n; ++i) {
        auto it = st.lower_bound({ps[i], INT_MAX});
        if(it == st.end()) {
            mx[i] = -1;
        } else {
            mx[i] = it->y + 1;
        }

        it = st.insert({ps[i - 1], i - 1}).x;
        for(;;) {
            if(it == st.begin()) {
                break;
            }

            auto pr = it;
            --pr;
            st.erase(pr);
        }
    }

    for(int i = 0; i < n; ++i) {
        sp[0][i] = mx[i];
    }

    //cout << a << endl;
    //cout << ps << endl;
    //cout << mx << endl;
    //cout << endl;

    for(int i = 1; (1 << i) <= n; ++i) {
        for(int j = 0; j + (1 << i) <= n; ++j) {
            sp[i][j] = max(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
        }
    }

    set_t(1, 0, n + 1, 0, 0);
    set_t(1, 0, n + 1, 1, 1);
    vector<int> dp_ok(n + 1, INT_MAX);
    dp_ok[0] = dp_ok[1] = 0;

    for(int i = 1; i < n; ++i) {
        int cur_ch = dp_ok[i] + 1;

        int l = 0;
        int r = i;
        while(l != r) {
            int m = (l + r) / 2;

            if(get_max(m, i + 1) < m) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        --l;

        int cur_not = get_t(1, 0, n + 1, l + 1, i + 1);
        set_t(1, 0, n + 1, i + 1, cur_ch);
        dp_ok[i + 1] = min(cur_ch, cur_not);

        //cout << i << " " << cur_ch << " " << cur_not << endl;
    }

    cout << n - dp_ok.back() << endl;
}

void _main_function() {
    lg2[0] = -1;
    lg2[1] = 0;
    for(int i = 2; i < N; ++i) {
        lg2[i] = lg2[i >> 1] + 1;
    }

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