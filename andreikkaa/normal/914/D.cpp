/*
* C++11 code template for contests.
* @author: Andrei Kalendarov
* @e-mail: andreykalendarov@gmail.com
*/

//#define ANDREIKKAA_ALLOCATOR
//#define ANDREIKKAA_INTERACTIVE
const int _ML = 220;
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

#if !defined(ANDREIKKAA)
#pragma GCC optimize ("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define rand rd
#define random_shuffle abcdefghijklmnopqrstuvwxyz
#if !defined(ANDREIKKAA_INTERACTIVE) && !defined(ANDREIKKAA)
#define endl '\n'
#endif
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef double ld;
const ld PI = 3.14159265358979323846;
mt19937 rd(228);

#if defined(ANDREIKKAA_ALLOCATOR)
char _mem[_ML * 1024 * 1024];
size_t _ptr = 0;
inline void* operator new (size_t _x) { _ptr += _x; return _mem + _ptr - _x; }
inline void operator delete (void*) { }
#endif

template<typename T, typename U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p) { _out << _p.first << ' ' << _p.second; return _out; }
template<typename T, typename U> inline istream &operator>> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const vector<T> &_v) { if (_v.empty()) { return _out; } _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline istream &operator>> (istream &_in, vector<T> &_v) { for (auto &_i : _v) { _in >> _i; } return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const unordered_map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }

/* ________ CODE ________ */

const int N = 500 * 1000 + 228;
int t[4 * N];
int lb[4 * N];
int rb[4 * N];
int a[N];

void build_t(int v, int l, int r)
{
    lb[v] = l;
    rb[v] = r;

    if(r - l == 1)
    {
        t[v] = a[l];
    }
    else
    {
        build_t(v << 1, l, (l + r) >> 1);
        build_t(v << 1 | 1, (l + r) >> 1, r);
        t[v] = __gcd(t[v << 1], t[v << 1 | 1]);
    }
}

void upd_t(int v, int l, int r, const int L, const int X)
{
    if(L < l || r <= L)
    {
        return;
    }

    if(r - l == 1)
    {
        t[v] = X;
        return;
    }

    upd_t(v << 1, l, (l + r) >> 1, L, X);
    upd_t(v << 1 | 1, (l + r) >> 1, r, L, X);
    t[v] = __gcd(t[v << 1], t[v << 1 | 1]);
}

vector<int> buf;

void get_t(int v, int l, int r, const int L, const int R)
{
    if(R <= l || r <= L)
    {
        return;
    }

    if(L <= l && r <= R)
    {
        buf.push_back(v);
        return;
    }

    get_t(v << 1, l, (l + r) >> 1, L, R);
    get_t(v << 1 | 1, (l + r) >> 1, r, L, R);
}

bool get2_t(int v, int l, int r, const int X)
{
    if(r - l == 1)
    {
        return true;
    }

    if(t[v << 1] % X != 0 && t[v << 1 | 1] % X != 0)
    {
        return false;
    }

    if(t[v << 1] % X != 0)
    {
        return get2_t(v << 1, l, (l + r) >> 1, X);
    }
    else
    {
        return get2_t(v << 1 | 1, (l + r) >> 1, r, X);
    }
}

inline void mainFunction()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    build_t(1, 0, n);

    int q;
    cin >> q;

    for(int i = 0; i < q; ++i)
    {
        int t;
        cin >> t;

        if(t == 1)
        {
            buf.clear();

            int l, r, x;
            cin >> l >> r >> x;

            get_t(1, 0, n, l - 1, r);

            int ok = -1;
            for(int j : buf)
            {
                if(::t[j] % x != 0)
                {
                    if(ok != -1)
                    {
                        goto kk;
                    }
                    else
                    {
                        ok = j;
                    }
                }
            }

            if(ok == -1 || get2_t(ok, lb[ok], rb[ok], x))
            {
                cout << "YES" << endl;
                continue;
            }

            kk:;
            cout << "NO" << endl;
        }
        else
        {
            int p, x;
            cin >> p >> x;

            upd_t(1, 0, n, p - 1, x);
        }
    }
}

/* ________ CODE ________ */

int main()
{
#if defined(ANDREIKKAA)
    time_t _start = clock();
#endif
    if (_inpf[0] != '\0') assert(freopen(_inpf, "r", stdin) != nullptr);
    if (_outf[0] != '\0') assert(freopen(_outf, "w", stdout) != nullptr);
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(228);
    //cout << fixed;
    mainFunction();
#if defined(ANDREIKKAA)
    cout << "Time: " << (clock() - _start) / (ld)CLOCKS_PER_SEC << endl;
#endif
}