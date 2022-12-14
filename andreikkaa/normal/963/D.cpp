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

const int N = 100 * 1000 + 228;
const int INF = 1000 * 1000;
const int P = 31;
const int M = 1000 * 1000 * 1000 + 9;

vector<pair<int, int>> q[N];
vector<int> pos[N];
int k[N];
int h[N];
int pw[N];
int ans[N];

int get_h(int l, int r)
{
    return (int)(((h[r] - (l ? (ll)h[l - 1] * pw[r - l + 1] : 0)) % M + M) % M);
}

int hsh(const string &s)
{
    int ans = 0;
    for(char c : s)
    {
        ans = (int)(((ll)ans * P + c - 'a' + 1) % M);
    }
    return ans;
}

inline void _main_function()
{
    pw[0] = 1;
    for(int i = 1; i < N; ++i)
    {
        pw[i] = (int)((ll)pw[i - 1] * P % M);
    }
    
    string s;
    cin >> s;
    
    for(int i = 0; i < sz(s); ++i)
    {
        h[i] = (int)(((i ? (ll)h[i - 1] * P : 0) + s[i] - 'a' + 1) % M);
    }
    
    int n;
    cin >> n;
    
    fill(ans, ans + n, INF);
    
    for(int i = 0; i < n; ++i)
    {
        cin >> k[i];
        string t;
        cin >> t;
        q[sz(t)].emplace_back(hsh(t), i);
    }
    
    for(int len = 1; len <= sz(s); ++len)
    {
        if(q[len].empty())
        {
            continue;
        }
        
        sort(all(q[len]));
        
        for(int i = 0; i + len <= sz(s); ++i)
        {
            auto h = get_h(i, i + len - 1);
            int l = 0;
            int r = sz(q[len]);
            while(l != r)
            {
                int m = (l + r) / 2;
                if(q[len][m].x < h)
                {
                    l = m + 1;
                }
                else
                {
                    r = m;
                }
            }
            if(r < sz(q[len]) && q[len][r].x == h)
            {
                pos[q[len][r].y].push_back(i);
            }
        }
        
        for(int i = 0; i < sz(q[len]); ++i)
        {
            int num = q[len][i].y;
            for(int j = k[num] - 1; j < sz(pos[num]); ++j)
            {
                ans[num] = min(ans[num], pos[num][j] + len - pos[num][j - k[num] + 1]);
            }
        }
    }
    
    for(int i = 0; i < n; ++i)
    {
        if(ans[i] == INF)
        {
            ans[i] = -1;
        }
        cout << ans[i] << endl;
    }
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