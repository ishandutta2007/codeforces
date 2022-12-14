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

string stup(string s) {
    string ans(2, s[0]);
    for(int i = 1; i <= sz(s); ++i) {
        string cur = s.substr(0, i);
        auto r = cur;
        reverse(all(r));

        cur += r;
        ans = min(ans, cur);
    }

    return ans;
}

string s, t;

const int N = 100'228;
const int M = 1'000'000'009;
const int P = 31;
ll h[N];
ll g[N];
ll pm[N];
int n;

ll get_pr(int l, int r) {
    if(l == r) {
        return 0;
    }

    return ((h[r - 1] - (l == 0 ? ll(0) : h[l - 1]) * pm[r - l]) % M + M) % M;
}

ll get_obr(int l, int r) {
    if(l == r) {
        return 0;
    }
    r = n - r - 1;
    l = n - l - 1;

    return ((g[r - 1] - (l == 0 ? ll(0) : g[l - 1]) * pm[r - l]) % M + M) % M;
}

int cmp_pr_ob(int l1, int r1, int l2, int r2) {
    int l = 0;
    int r = r1 - l1 + 1;

    while(l != r) {
        int m = (l + r) / 2;

        if(get_pr(l1, l1 + m) == get_obr(l2, l2 - m)) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    if(l == r1 - l1 + 1) {
        return 0;
    }

    if(s[l1 + l - 1] < s[l2 - l + 1]) {
        return -1;
    } else {
        assert(s[l1 + l - 1] > s[l2 - l + 1]);
        return 1;
    }
}

int cmp_ob_ob(int l1, int r1, int l2, int r2) {
    int l = 0;
    int r = l1 - r1 + 1;

    while(l != r) {
        int m = (l + r) / 2;

        //cout << l1 << " > " << l1 - m << " " << get_obr(l1, l1 - m) << endl;
        //cout << l2 << " > " << l2 - m << " " << get_obr(l2, l2 - m) << endl;
        if(get_obr(l1, l1 - m) == get_obr(l2, l2 - m)) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    if(l == l1 - r1 + 1) {
        return 0;
    }

    if(s[l1 - l + 1] < s[l2 - l + 1]) {
        return -1;
    } else {
        assert(s[l1 - l + 1] > s[l2 - l + 1]);
        return 1;
    }
}

string clev(string s) {
    n = sz(s);
    ::s = s;

    for(int i = 0; i < n; ++i) {
        if(i) {
            h[i] = h[i - 1] * P;
        }
        h[i] += s[i] - 'a' + 1;
        h[i] %= M;
    }

    t = s;
    reverse(all(t));
    for(int i = 0; i < n; ++i) {
        if(i) {
            g[i] = g[i - 1] * P;
        }
        g[i] += t[i] - 'a' + 1;
        g[i] %= M;
    }

    int pos = 1;
    for(int i = 2; i <= n; ++i) {
        int len = min(pos, i - pos);
        int res = cmp_pr_ob(pos, pos + len, pos - 1, pos - len - 1);
        if(res == -1) {
            pos = i;
            continue;
        } else if(res == 1) {
            continue;
        } else {
            if(len == pos) {
                continue;
            }

            int rest = pos - len;
            if(cmp_ob_ob(pos - 1, pos - 1 - rest, rest - 1, -1) == -1) {
                pos = i;
                continue;
            }
        }
    }

    auto ans = s.substr(0, pos);
    auto r = ans;
    reverse(all(r));
    return ans + r;
}

void _solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;


    cout << clev(s) << endl;
    /*cout << stup(s) << endl;
    //return;


    for(;;) {
        string now;
        for(int i = 0; i < 3; ++i) {
            char c = 'a' + rd() % 5;
            now += c;
        }

        auto a = stup(now);
        auto b = clev(now);

        if(a != b) {
            cout << now << " " << a << " " << b << endl;
            return;
        }
    }*/
}

void _main_function() {
    pm[0] = 1;
    for(int i = 1; i < N; ++i) {
        pm[i] = pm[i - 1] * P % M;
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