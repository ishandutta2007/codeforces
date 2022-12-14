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

const int N = 3002;
vector<int> g[N];
int d[N];
bool ok[N];
bool mark[N];

void dfs(int v, int p, int d) {
    ::d[v] = d;

    for(int i : g[v]) {
        if(i != p) {
            dfs(i, v, d + 1);
        }
    }
}

bool dfs_mark(int v, int p) {
    bool ret = !ok[v];

    for(int i : g[v]) {
        if(i == p) {
            continue;
        }

        ret |= dfs_mark(i, v);
    }

    return mark[v] = ret;
}

pair<int, int> dfs_far(int v, int p) {
    if(!mark[v]) {
        return{-228228, v};
    }
    pair<int, int> ret = {0, v};

    for(int i : g[v]) {
        if(i == p) {
            continue;
        }

        auto q = dfs_far(i, v);
        ++q.x;
        ret = max(ret, q);
    }

    return ret;
}

void _solve() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        g[i].clear();
    }

    for(int i = 2; i <= n; ++i) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0, 0);

    vector<int> ans(n + 1, INT_MAX);
    for(int dist = 1; dist <= n - 1; ++dist) {
        int start = -1;
        for(int v = 1; v <= n; ++v) {
            if(d[v] <= dist) {
                ok[v] = true;
            } else {
                start = v;
                ok[v] = false;
            }
        }

        if(start == -1) {
            for(int &i : ans) {
                i = min(i, dist);
            }
            break;
        }
        dfs_mark(start, 0);

        /*cout << dist << endl;
        for(int v = 1; v <= n; ++v) {
            cout << ok[v] << " " << mark[v] << endl;
        }*/

        int v;
        for(v = 1; v <= n; ++v) {
            if(mark[v]) {
                break;
            }
        }

        if(v == n + 1) {
            assert(false);
        }

        auto p = dfs_far(v, 0);
        p = dfs_far(p.y, 0);

        int plus = (p.x + 1) / 2;
        for(int x = 1; x + plus <= dist; ++x) {
            ans[x] = min(ans[x], dist);
        }
    }

    for(int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

void _main_function() {
    int t = 1000;
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