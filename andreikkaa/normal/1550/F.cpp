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
const int N = 200'228;
const pair<int, int> DEF = {A, -1};

pair<int, int> t[4 * A];

pair<int, int> get_t_r(int v, int l, int r, int X, int Y) {
    if(r <= X) {
        return DEF;
    }

    if(t[v].x == -1 || (t[v].x == Y && t[v].y == Y)) {
        return DEF;
    }

    if(r - l == 1) {
        assert(t[v].x != Y);
        assert(t[v].x == t[v].y);
        return {abs(X - l), t[v].x};
    }

    auto ans = get_t_r(v << 1, l, (l + r) >> 1, X, Y);
    if(ans != DEF) {
        return ans;
    } else {
        return get_t_r(v << 1 | 1, (l + r) >> 1, r, X, Y);
    }
}

pair<int, int> get_t_l(int v, int l, int r, int X, int Y) {
    if(X < l) {
        return DEF;
    }

    if(t[v].x == -1 || (t[v].x == Y && t[v].y == Y)) {
        return DEF;
    }

    if(r - l == 1) {
        assert(t[v].x != Y);
        assert(t[v].x == t[v].y);
        return {abs(X - l), t[v].x};
    }

    auto ans = get_t_l(v << 1 | 1, (l + r) >> 1, r, X, Y);
    if(ans != DEF) {
        return ans;
    } else {
        return get_t_l(v << 1, l, (l + r) >> 1, X, Y);
    }
}

void set_t(int v, int l, int r, int X, int Y) {
    if(X < l || r <= X) {
        return;
    }

    if(r - l == 1) {
        t[v] = {Y, Y};
        return;
    }

    set_t(v << 1, l, (l + r) >> 1, X, Y);
    set_t(v << 1 | 1, (l + r) >> 1, r, X, Y);

    if(t[v << 1].x == -1) {
        t[v] = t[v << 1 | 1];
    } else if(t[v << 1 | 1].x == -1) {
        t[v] = t[v << 1];
    } else {
        t[v] = {min(t[v << 1].x, t[v << 1 | 1].x), max(t[v << 1].y, t[v << 1 | 1].y)};
    }
}


int dsu[N];

int get_dsu(int x) {
    if(x == dsu[x]) {
        return x;
    }
    return x = get_dsu(dsu[x]);
}

void upd_dsu(int x, int y) {
    dsu[get_dsu(x)] = get_dsu(y);
}

vector<pair<int, int>> g[N];

void add_rib(int a, int b, int c) {
    g[a].push_back({b, c});
    g[b].push_back({a, c});
}

int ans[N];
bool u[N];

void dfs(int v, int p, int x) {
    u[v] = true;
    ans[v] = x;
    for(const auto &i : g[v]) {
        if(!u[i.x]) {
            dfs(i.x, v, max(x, i.y));
        }
    }
}

void solve() {
    memset(t, -1, sizeof t);

    int n, q, s, d;
    cin >> n >> q >> s >> d;
    --s;

    vector<int> a(n);
    cin >> a;

    vector<int> clr(n);
    iota(all(clr), 0);
    iota(dsu, dsu + n, 0);

    for(int i = 0; i < n; ++i) {
        set_t(1, 0, A, a[i], clr[i]);
    }

    while(count(all(clr), clr[0]) != n) {
        vector<pair<int, int>> to_up(n, DEF);
        for(int i = 0; i < n; ++i) {
            auto pl1 = get_t_l(1, 0, A, a[i] - d, clr[i]);
            auto pl2 = get_t_r(1, 0, A, a[i] - d, clr[i]);
            auto pr1 = get_t_l(1, 0, A, a[i] + d, clr[i]);
            auto pr2 = get_t_r(1, 0, A, a[i] + d, clr[i]);
            //cout << i << ":" << endl;
            //cout << pl1 << ", " << pl2 << ", " << pr1 << ", " << pr2 << endl;
            to_up[clr[i]] = min({to_up[clr[i]], pl1, pl2, pr1, pr2});
        }

        for(int i = 0; i < n; ++i) {
            if(to_up[i].y != DEF.y) {
                upd_dsu(i, to_up[i].y);
                add_rib(i, to_up[i].y, to_up[i].x);
            }
        }

        for(int i = 0; i < n; ++i) {
            clr[i] = get_dsu(clr[i]);
        }

        for(int i = 0; i < n; ++i) {
            set_t(1, 0, A, a[i], clr[i]);
        }
    }

    dfs(s, -1, 0);
    for(int i = 0; i < q; ++i) {
        int v, k;
        cin >> v >> k;
        --v;

        if(ans[v] <= k) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}

void _main_function() {
    int t = 1;
    //cin >> t;

    for(int i = 0; i < t; ++i) {
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