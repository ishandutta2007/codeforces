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
#ifdef ANDREIKKAA
using ll = long long;
#else
using ll = __int128_t;
#endif
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

const ld EPS = 1e-3;

void addeq(pair<ll, ll>& a, pair<ll, ll> b) {
    a.x += b.x;
    a.y += b.y;
}

struct line {
    int a, b;
    ld c;
};

line f(pair<ld, ld> p) {
    return{1, 1, -ld(p.x) - p.y};
}

line g(pair<ld, ld> p) {
    return{ 1, -1, ld(p.y) - p.x };
}

bool online(line l, pair<ld, ld> p) {
    if (l.b == -1) {
        return abs(p.x - p.y + l.c) < EPS;
    }
    else {
        assert(l.b == 1);
        return abs(p.x + p.y + l.c) < EPS;
    }
}

pair<bool, pair<ld, ld>> inter(line l, line m) {
    assert(l.b != m.b);
    if (l.b == -1) {
        swap(l, m);
    }

    assert(l.b == 1);
    assert(m.b == -1);

    pair<ld, ld> pos = { (-l.c - m.c) / 2, (m.c - l.c) / 2 };
    assert(online(l, pos));
    assert(online(m, pos));
    return{ true, pos};
}

ll cn() {
    int64_t x;
    cin >> x;
    return x;
}

void _solve() {
    int n;
    ll m;
    cin >> n;
    m = cn();

    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; ++i) {
        a[i].x = cn();
        a[i].y = cn();
    }

    map<ll, pair<ll, ll>> bal;
    for (auto i : a) {
        ll l = i.x - i.y + 1;
        ll r = i.x + i.y;
        addeq(bal[l], {1, -l + 1});
        addeq(bal[i.x], { -1, l - 1 });
        addeq(bal[i.x], { -1, i.y + i.x});
        addeq(bal[i.x + i.y + 1], { 1, -i.y - i.x });
    }

    vector<pair<ll, pair<ll, ll>>> e(all(bal));

    pair<ll, ll> cur = { 0, 0 };

    vector<pair<ld, ld>> need;

    ll min_sum = LLONG_MIN;
    ll max_dif = LLONG_MAX;
    for (int i = 0; i + 1 < sz(e); ++i) {
        cur.x += e[i].y.x;
        cur.y += e[i].y.y;
        ll lft = e[i].x;
        ll rgt = e[i + 1].x;

        if (cur.x > 0) {
            ll val = cur.x * (rgt - 1) + cur.y;
            if (val <= m) {
                continue;
            }
            // rgt - 1, val - m
            need.push_back({ rgt - 1, val - m });
            min_sum = max(min_sum, 2 * (rgt - 1 + val - m));
            max_dif = min(max_dif, 2 * (rgt - 1 - (val - m)));
        }
        else if (cur.x == 0) {
            ll val = cur.y;
            if (val <= m) {
                continue;
            }

            ll len = rgt - lft - 1;
            need.push_back({lft + len / 2, val - m + len / 2});
            min_sum = max(min_sum, 2 * lft + len + 2 * (val - m) + len);
            max_dif = min(max_dif, 2 * lft + len - 2 * (val - m) - len);
        }
        else {
            assert(cur.x < 0);
            ll val = cur.x * (lft)+cur.y;
            if (val <= m) {
                continue;
            }
            // lft, val - m
            need.push_back({ lft, (val - m) });
            min_sum = max(min_sum, 2 * (lft + val - m));
            max_dif = min(max_dif, 2 * (lft - (val - m)));
        }
    }

    if (need.empty()) {
        cout << string(n, '1') << endl;
        return;
    }

    for (auto& i : a) {
        i.x *= 2;
        i.y *= 2;
    }

    for (int i = 0; i < n; ++i) {
        if (min_sum <= a[i].x + a[i].y && a[i].x - a[i].y <= max_dif) {
            cout << '1';
        }
        else {
            cout << '0';
        }
    }
    cout << endl;
}

void _main_function() {
    int t = 1;
    cin >> t;

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