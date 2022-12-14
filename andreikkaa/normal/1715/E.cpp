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
using namespace std;
#if __has_include("ext/pb_ds/assoc_container.hpp")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#endif
#if !defined(ANDREIKKAA)
#define endl '\n'
#endif
#define x first
#define y second
//#define rand abcdefghijklmnopqrstuvwxyz
//#define random_shuffle abcdefghijklmnopqrstuvwxyz
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
template<class T, class U> inline ostream& operator<< (ostream&, const pair<T, U>&);
template<class T, class U> inline istream& operator>> (istream&, pair<T, U>&);
template<class T> inline ostream& operator<< (ostream&, const vector<T>&);
template<class T> inline istream& operator>> (istream&, vector<T>&);
template<class T> inline ostream& operator<< (ostream&, const set<T>&);
template<class T> inline ostream& operator<< (ostream&, const multiset<T>&);
template<class T> inline ostream& operator<< (ostream&, const unordered_set<T>&);
template<class T> inline ostream& operator<< (ostream&, const unordered_multiset<T>&);
template<class T, class U> inline ostream& operator<< (ostream&, const map<T, U>&);
template<class T, class U> inline ostream& operator<< (ostream&, const unordered_map<T, U>&);
template<class T, size_t N> inline ostream& operator<< (ostream&, const array<T, N>&);
template<class T, size_t N> inline ostream& operator>> (istream&, array<T, N>&);

/* ________ CODE ________ */

const int N = 100'228;
vector<pair<int, int>> g[N];
const ll INF = 1'000'000'000'000LL;

void go(vector<ll>& d) {
    const int n = sz(d);

    set<pair<ll, int>> q;
    for (int i = 0; i < n; ++i) {
        q.insert({ d[i], i });
    }

    while (!q.empty()) {
        int v = q.begin()->y;
        q.erase(q.begin());

        for (auto i : g[v]) {
            if (d[v] + i.y < d[i.x]) {
                q.erase({ d[i.x], i.x });
                d[i.x] = d[v] + i.y;
                q.insert({ d[i.x], i.x });
            }
        }
    }
}

struct Line {
    ll k, b;
    mutable const Line* nx;
    bool operator<(ll x) const {
        if (!nx) return 0;
        return b - nx->b < (nx->k - k)* x;
    }
    bool operator<(const Line& rhs) const {
        return k < rhs.k;
    }
};
// will maintain upper hull for maximum
struct HullDynamic : multiset<Line, less<>> {
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->k == z->k && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->k == x->k && y->b <= x->b;
        return (x->b - y->b) * (z->k - y->k) >= (y->b - z->b) * (y->k - x->k);
    }
    void insert_line(ll k, ll b) {
        auto y = insert({ k, b, 0 });
        if (bad(y)) { erase(y); return; }
        auto z = next(y);
        while (z != end() && bad(z)) z = erase(z);
        if (z != end()) y->nx = &*z;
        while (y != begin() && bad(z = prev(y))) erase(z);
        if (y != begin()) z->nx = &*y;
    }
    ll eval(ll x) {
        auto l = *lower_bound(x);
        return l.k * x + l.b;
    }
};

vector<ll> ff(const vector<ll>& d) {
    const int n = sz(d);
    vector<ll> ans(n, INF);

    HullDynamic h;

    for (int i = 0; i < n; ++i) {
        // ad i
        // -2 * i, ll(i) * i + d[i]
        h.insert_line(2 * i, -ll(i) * i - d[i]);
        ans[i] = -h.eval(i) + ll(i) * i;
    }

    return ans;
}

void f(vector<ll>& d) {
    auto lft = ff(d);
    reverse(all(d));
    auto rgt = ff(d);
    reverse(all(rgt));
    reverse(all(d));
    for (int i = 0; i < sz(d); ++i) {
        assert(min(lft[i], rgt[i]) <= d[i]);
        d[i] = min(lft[i], rgt[i]);
    }
}

void _solve() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;

        g[a].push_back({ b, c });
        g[b].push_back({ a, c });
    }

    vector<ll> d(n, INF);
    d[0] = 0;

    go(d);

    for (int i = 0; i < k; ++i) {
        f(d);
        go(d);
    }

    cout << d << endl;
}

void _main_function() {
    int t = 1;
    //cin >> t;

    for (int i = 0; i < t; ++i) {
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

template<class T, class U> inline ostream& operator<< (ostream& _out, const pair<T, U>& _p) {
    _out << _p.x << ' ' << _p.y;
    return _out;
}
template<class T, class U> inline istream& operator>> (istream& _in, pair<T, U>& _p) {
    _in >> _p.x >> _p.y;
    return _in;
}
template<class T> inline ostream& operator<< (ostream& _out, const vector<T>& _v) {
    if (_v.empty()) { return _out; }
    _out << *_v.begin();
    for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline istream& operator>> (istream& _in, vector<T>& _v) {
    for (auto& _i : _v) { _in >> _i; }
    return _in;
}
template<class T> inline ostream& operator<< (ostream& _out, const set<T>& _s) {
    if (_s.empty()) { return _out; }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline ostream& operator<< (ostream& _out, const multiset<T>& _s) {
    if (_s.empty()) { return _out; }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline ostream& operator<< (ostream& _out, const unordered_set<T>& _s) {
    if (_s.empty()) { return _out; }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline ostream& operator<< (ostream& _out, const unordered_multiset<T>& _s) {
    if (_s.empty()) { return _out; }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T, class U> inline ostream& operator<< (ostream& _out, const map<T, U>& _m) {
    if (_m.empty()) { return _out; }
    _out << '(' << _m.begin()->x << ": " << _m.begin()->y << ')';
    for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->x << ": " << _it->y << ')'; }
    return _out;
}
template<class T, class U> inline ostream& operator<< (ostream& _out, const unordered_map<T, U>& _m) {
    if (_m.empty()) { return _out; }
    _out << '(' << _m.begin()->x << ": " << _m.begin()->y << ')';
    for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->x << ": " << _it->y << ')'; }
    return _out;
}

template<class T, size_t N> inline ostream& operator<< (ostream& _out, const array<T, N>& a) {
    for (int i = 0; i < N; ++i) {
        _out << a[i];
        if (i + 1 < N) {
            _out << ' ';
        }
    }
    return _out;
}
template<class T, size_t N> inline istream& operator>> (istream& _in, array<T, N>& a) {
    for (int i = 0; i < N; ++i) {
        _in >> a[i];
    }
    return _in;
}