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

const int N = 200'228;
vector<int> g[N];
ll s[N];
int fir[N];
ll sumsq[N];
int tin[N], tout[N];
int tim;

ll sqq(ll x) {
    return x * (x - 1) / 2;
}

void dfs_prec(int v, int p, int ff) {
    tin[v] = tim++;
    fir[v] = ff;
    s[v] = 1;
    for(int i : g[v]) {
        if(i == p) {
            continue;
        }
        if(ff == -1) {
            dfs_prec(i, v, i);
        } else {
            dfs_prec(i, v, ff);
        }
        s[v] += s[i];
        sumsq[v] += sqq(s[i]);
    }
    tout[v] = tim++;
}

bool par(int a, int b) {
    return tin[a] <= tin[b] && tin[b] <= tout[a];
}

void solve() {
    int n;
    cin >> n;

    tim = 0;
    for(int i = 0; i < n; ++i) {
        sumsq[i] = 0;
        s[i] = 0;
        g[i].clear();
    }

    for(int i= 0 ;i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs_prec(0, -1, -1);
    cout << sumsq[0] << " ";

    int a = -1, b = -1;
    bool zal = false;
    for(int i = 1; i < n; ++i) {
        if(zal || (a != -1 && par(i, a)) || (b != -1 && par(i, b))) {
            cout << "0 ";
        } else {
            if(a == -1) {
                assert(i == 1);
                cout << ll(n - 1) * n / 2 - sumsq[0] - s[1] * (n - s[fir[1]]) << " ";
            } else if(b == -1) {
                ll dwn = s[a], upp = n - s[fir[a]];
                if(par(a, i)) {
                    dwn -= s[i];
                } else if(fir[i] != fir[a]) {
                    upp -= s[i];
                }
                cout << dwn * upp << " ";
            } else {
                ll x = s[a];
                ll y = s[b];
                if(par(a, i)) {
                    x -= s[i];
                } else if(par(b, i)) {
                    y -= s[i];
                }
                cout << x * y << " ";
            }
        }

        if(zal) {
            continue;
        }

        if(i != n) {
            if (a == -1) {
                a = i;
            } else if (par(a, i)) {
                a = i;
            } else if (par(i, a)) {
                //kk
            } else if (fir[a] == fir[i]) {
                zal = true;
            } else if (b == -1) {
                b = i;
            } else if (par(b, i)) {
                b = i;
            } else if (par(i, b)) {
                //kk
            } else if (fir[b] == fir[i]) {
                zal = true;
            } else {
                zal = true;
            }
        }
    }
    cout << 1 - zal << endl;
}

void _main_function() {
    int t = 1;
    cin >> t;

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