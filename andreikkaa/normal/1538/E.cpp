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

struct var {
    string s;
    string prf;
    string suf;
    ll ans = 0;
};

vector<string> split(string s) {
    vector<string> ans;
    string cur;
    for(char c : s) {
        if(c == ' ') {
            ans.push_back(cur);
            cur.clear();
        } else {
            cur += c;
        }
    }
    ans.push_back(cur);
    return ans;
}

int calc(string s) {
    int ans = 0;
    for(int i = 0; i + 4 <=sz(s); ++i) {
        ans += (s.substr(i, 4) == "haha");
    }
    return ans;
}

var to_var(const string& s) {
    return{s, "", "", calc(s)};
}

var f(const var &a, const var &b) {
    string lft;
    if(sz(a.s)) {
        lft = a.s.substr(max(sz(a.s) - 3, 0));
    } else {
        assert(sz(a.suf) == 4);
        lft = a.suf.substr(1);
    }

    string rgt;
    if(sz(b.s)) {
        rgt = b.s.substr(0, min(3, sz(b.s)));
    } else {
        assert(sz(b.prf) == 4);
        rgt = b.prf.substr(0, 3);
    }

    ll now = a.ans + b.ans + calc(lft + rgt);
    if(sz(a.s)) {
        if(sz(b.s)) {
            string s = a.s + b.s;
            if(sz(s) < 8) {
                return{s, "", "", now};
            } else {
                return{"", s.substr(0, 4), s.substr(sz(s) - 4), now};
            }
        } else {
            return{"", (a.s + b.prf).substr(0, 4), b.suf, now};
        }
    } else {
        if(sz(b.s)) {
            string tmp = a.suf + b.s;
            return{"", a.prf, tmp.substr(sz(tmp) - 4), now};
        } else {
            return{"", a.prf, b.suf, now};
        }
    }
}


void solve() {
    int n;
    cin >> n;

    map<string, var> val;

    string lst;
    cin.get();
    for(int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        auto v = split(s);

        lst = v[0];

        if(v[1] == ":=") {
            val[lst] = to_var(v[2]);
        } else {
            assert(v[1] == "=");
            assert(v[3] == "+");
            val[lst] = f(val[v[2]], val[v[4]]);
        }

        //cout << lst << " = " << val[lst].s << " , " << val[lst].ans << endl;
    }

    cout << val[lst].ans << endl;
}

void _main_function() {
    int t;
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