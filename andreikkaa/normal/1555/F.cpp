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

const int N = 300'228;
int t[4 * N];

void upd_t(int v, int l, int r, int L, int R) {
    if(R <= l || r <= L) {
        return;
    }

    if(L <= l && r <= R) {
        ++t[v];
        return;
    }

    upd_t(v << 1, l, (l + r) >> 1, L, R);
    upd_t(v << 1 | 1, (l + r) >> 1, r, L, R);
}

int get_t(int v, int l, int r, int L) {
    int ans = 0;
    while(true) {
        ans += t[v];
        if(r - l == 1) {
            return ans;
        }
        const int m = (l + r) / 2;
        v <<= 1;
        if(L < m) {
            r = m;
        } else {
            l = m;
            v |= 1;
        }
    }
}

const int L = 19;
vector<pair<int, int>> g[N];
int d[N];
int la[N][L];
bool u[N];
int tin[N];
int tout[N];
int tim;
int ps[N];

void dfs(int v, int p, int ps) {
    ::ps[v] = ps;
    tin[v] = tim++;
    d[v] = d[p] + 1;
    u[v] = true;
    la[v][0] = p;
    for(int i = 1; i < L; ++i) {
        la[v][i] = la[la[v][i - 1]][i - 1];
    }

    for(auto i : g[v]) {
        if(i.x == p) {
            continue;
        }
        dfs(i.x, v, ps ^ i.y);
    }
    tout[v] = tim;
}

int get_lca(int a, int b) {
    if(d[a] < d[b]) {
        swap(a, b);
    }

    const int dif = d[a] - d[b];
    for(int i = 0; i < L; ++i) {
        if(dif >> i & 1) {
            a = la[a][i];
        }
    }

    if(a == b) {
        return a;
    }

    for(int i = L - 1; i >= 0; --i) {
        if(la[a][i] != la[b][i]) {
            a = la[a][i];
            b = la[b][i];
        }
    }
    assert(la[a][0] == la[b][0]);

    return la[a][0];
}

int dsu[N];
int get_dsu(int x) {
    if(dsu[x] == x) {
        return x;
    }
    return dsu[x] = get_dsu(dsu[x]);
}

int n;

void upd(int low, int up) {
    for(; low != up; low = la[low][0]) {
        upd_t(1, 0, n, tin[low], tout[low]);
    }
}

int gt(int v) {
    return get_t(1, 0, n, tin[v]);
}

void solve() {
    int q;
    cin >> n >> q;

    vector<pair<pair<int, int>, int>> a(q);
    cin >> a;

    set<pair<int, int>> st;
    iota(dsu, dsu + n + 1, 0);
    for(auto &i : a) {
        if(i.x.x > i.x.y) {
            swap(i.x.x, i.x.y);
        }
        int a = get_dsu(i.x.x);
        int b = get_dsu(i.x.y);
        if(a != b) {
            dsu[a] = b;
            g[i.x.x].push_back({i.x.y, i.y});
            g[i.x.y].push_back({i.x.x, i.y});
            st.insert(i.x);
        }
    }

    for(int i = 1; i <= n; ++i) {
        if(!u[i]) {
            dfs(i, 0, 0);
        }
    }
    assert(tim == n);

    for(const auto &i : a) {
        if(st.count(i.x)) {
            cout << "YES" << endl;
            continue;
        }

        int lca = get_lca(i.x.x, i.x.y);
        if((ps[i.x.x] ^ ps[i.x.y] ^ i.y) == 0) {
            cout << "NO" << endl;
            continue;
        }

        if(gt(i.x.x) + gt(i.x.y) - 2 * gt(lca)) {
            cout << "NO" << endl;
            continue;
        }

        upd(i.x.x, lca);
        upd(i.x.y, lca);
        cout << "YES" << endl;
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