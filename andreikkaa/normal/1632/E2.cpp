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

const int N = 300'228;
const int L = 19;
vector<int> g[N];
int d[N];
int la[N][L];

void dfs(int v, int p, int d) {
    ::d[v] = d;

    la[v][0] = p;
    for(int i = 1; i < L; ++i) {
        la[v][i] = la[la[v][i - 1]][i - 1];
    }

    for(int i : g[v]) {
        if(i != p) {
            dfs(i, v, d + 1);
        }
    }
}

int get_lca(int a, int b) {
    if(d[a] < d[b]) {
        swap(a, b);
    }

    for(int i = 0; i < L; ++i) {
        if((d[a] - d[b]) >> i & 1) {
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

    assert(a != b && la[a][0] == la[b][0]);
    return la[a][0];
}

int get_dist(int a, int b) {
    int l = get_lca(a, b);
    return d[a] + d[b] - 2 * d[l];
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

    vector<vector<int>> ver(n + 1);
    for(int i = 1; i <= n; ++i) {
        ver[d[i]].push_back(i);
    }

    vector<vector<int>> st(n + 2), fn(n + 2);
    auto up = [&st, &fn](int l, int r, int x) {
        assert(l < r);
        st[l].push_back(x);
        fn[r].push_back(x);
    };

    int a = 0, b = 0;
    for(int dist = n - 1; dist >= 0; --dist) {
        if(a == 0) {
            up(1, n + 1, dist);
        } else {
            int now = (get_dist(a, b) + 1) / 2;
            if (dist - now + 1 > 1) {
                up(1, dist - now + 1, dist);
            }
        }

        for(int v : ver[dist]) {
            if(a == 0) {
                a = b = v;
                continue;
            }
            if(get_dist(a, b) < get_dist(a, v)) {
                b = v;
            }
            if(get_dist(a, b) < get_dist(b, v)) {
                a = v;
            }
        }
    }

    set<int> s;
    for(int i = 1; i <= n; ++i) {
        for(int j : fn[i]) {
            assert(s.erase(j));
        }
        for(int j : st[i]) {
            s.insert(j);
        }
        assert(sz(s));
        cout << *s.begin() << " ";
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