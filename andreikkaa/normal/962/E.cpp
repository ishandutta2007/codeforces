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
#include <bits/stdc++.h>
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
typedef long long ll;
typedef double ld;
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

const ll D = 24 * 60 * 60;

bool ok(pair<ll, ll> a, pair<ll, ll> b)
{
    if(a.x > b.x)
    {
        swap(a, b);
    }
    return abs(a.x - b.x) <= D || abs(a.y - b.x) <= D || abs(a.y - b.y) <= D ||
           (a.x <= b.x && b.x <= a.y);
}

ll f(int y, int m, int d, int hh, int mm)
{
    tm t = {0};
    t.tm_year = y;
    t.tm_mon = m - 1;
    t.tm_mday = d;
    t.tm_hour = hh;
    t.tm_min = mm;
    return mktime(&t);
}

vector <ll> Vin[3];
ll in[300050][2];
ll getans(vector<ll> Vu) {
    if (Vu.empty()) return 0;
    return in[Vu.back()][0] - in[Vu[0]][0];
}

inline void _main_function()
{
    ll N, i, j, k;
    scanf("%lld", &N);
    for (i = 1; i <= N; i++) {
        ll t;
        char c[2];
        scanf("%lld %s", &t, c);
        in[i][0] = t;
        if (c[0] == 'R') in[i][1] = 0;
        else if (c[0] == 'B') in[i][1] = 1;
        else in[i][1] = 2;
        Vin[in[i][1]].push_back(i);
    }
    if (Vin[2].empty()) {printf("%lld\n", getans(Vin[0]) + getans(Vin[1])); return;}
    
    vector <ll> Vu[2];
    
    ll ans = 0;
    ll x = Vin[2][0];
    ll v1 = in[x][0], v2 = in[x][0];
    for (i = 1; i < x; i++) {
        if (in[i][1] == 0) v1 = min(v1, in[i][0]);
        else v2 = min(v2, in[i][0]);
    }
    ans += in[x][0] - v1;
    ans += in[x][0] - v2;
    
    x = Vin[2].back();
    v1 = v2 = in[x][0];
    for (i = x + 1; i <= N; i++) {
        if (in[i][1] == 0) v1 = max(v1, in[i][0]);
        else v2 = max(v2, in[i][0]);
    }
    ans += v1 + v2 - in[x][0] * 2;
    
    for (i = 0; i + 1 < Vin[2].size(); i++) {
        ll s = Vin[2][i], e = Vin[2][i + 1];
        Vu[0].clear();
        Vu[1].clear();
        Vu[0].push_back(in[s][0]);
        Vu[1].push_back(in[s][0]);
        for (j = s + 1; j < e; j++) Vu[in[j][1]].push_back(in[j][0]);
        Vu[0].push_back(in[e][0]);
        Vu[1].push_back(in[e][0]);
        
        ll mx[2] = { 0,0 };
        for (j = 0; j < 2; j++) {
            for (k = 0; k + 1 < Vu[j].size(); k++) mx[j] = max(mx[j], Vu[j][k + 1] - Vu[j][k]);
        }
        
        ans += (ll)min((ll)2 * (in[e][0] - in[s][0]), (ll)3 * (in[e][0] - in[s][0]) - mx[0] - mx[1]);
    }
    printf("%lld\n", ans);
}

/* ________ CODE ________ */

int main()
{
#if defined(ANDREIKKAA)
    clock_t _start = clock();
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

template<class T, class U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p)
{
    _out << _p.x << ' ' << _p.y;
    return _out;
}
template<class T, class U> inline istream &operator>> (istream &_in, pair<T, U> &_p)
{
    _in >> _p.x >> _p.y;
    return _in;
}
template<class T> inline ostream &operator<< (ostream &_out, const vector<T> &_v)
{
    if (_v.empty()) { return _out; }
    _out << *_v.begin();
    for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline istream &operator>> (istream &_in, vector<T> &_v)
{
    for (auto &_i : _v) { _in >> _i; }
    return _in;
}
template<class T> inline ostream &operator<< (ostream &_out, const set<T> &_s)
{
    if (_s.empty()) { return _out; }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline ostream &operator<< (ostream &_out, const multiset<T> &_s)
{
    if (_s.empty()) { return _out; }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline ostream &operator<< (ostream &_out, const unordered_set<T> &_s)
{
    if (_s.empty()) { return _out; }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T> inline ostream &operator<< (ostream &_out, const unordered_multiset<T> &_s)
{
    if (_s.empty()) { return _out; }
    _out << *_s.begin();
    for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; }
    return _out;
}
template<class T, class U> inline ostream &operator<< (ostream &_out, const map<T, U> &_m)
{
    if (_m.empty()) { return _out; }
    _out << '(' << _m.begin()->x << ": " << _m.begin()->y << ')';
    for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->x << ": " << _it->y << ')'; }
    return _out;
}
template<class T, class U> inline ostream &operator<< (ostream &_out, const unordered_map<T, U> &_m)
{
    if (_m.empty()) { return _out; }
    _out << '(' << _m.begin()->x << ": " << _m.begin()->y << ')';
    for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->x << ": " << _it->y << ')'; }
    return _out;
}